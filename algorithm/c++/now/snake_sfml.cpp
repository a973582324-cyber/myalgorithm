// SFML snake: arrows or WASD, R restart, ESC quit.
// VS: C/C++ -> Additional Include Directories: SFML\include
// Linker -> Additional Library Directories: SFML\lib (match Debug/Release)
// Linker -> Input -> Additional Dependencies (Debug):
//   sfml-graphics-d.lib;sfml-window-d.lib;sfml-system-d.lib
// Release: sfml-graphics.lib;sfml-window.lib;sfml-system.lib
// Copy SFML\bin DLLs next to the exe or add to PATH.
// One exe = one main(): if VS also compiles 源.cpp (or any other file with main),
// exclude that file from the project or set "Exclude From Build" = Yes, else LNK2005.

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <cstdlib>
#include <ctime>
#include <deque>
#include <string>

namespace {

    constexpr unsigned kCell = 24;
    constexpr int kCols = 20;
    constexpr int kRows = 15;
    constexpr float kMoveInterval = 0.12f;

    int randomInt(int minV, int maxV) {
        return minV + (std::rand() % (maxV - minV + 1));
    }

    bool cellOccupiedBySnake(int x, int y, const std::deque<sf::Vector2i>& snake) {
        for (const auto& p : snake) {
            if (p.x == x && p.y == y) {
                return true;
            }
        }
        return false;
    }

    void placeFood(sf::Vector2i& food, const std::deque<sf::Vector2i>& snake) {
        for (;;) {
            food.x = randomInt(0, kCols - 1);
            food.y = randomInt(0, kRows - 1);
            if (!cellOccupiedBySnake(food.x, food.y, snake)) {
                break;
            }
        }
    }

    bool hitsBody(int nx, int ny, const std::deque<sf::Vector2i>& snake, bool willGrow) {
        if (willGrow) {
            for (const auto& p : snake) {
                if (p.x == nx && p.y == ny) {
                    return true;
                }
            }
            return false;
        }
        for (size_t i = 0; i + 1 < snake.size(); ++i) {
            if (snake[i].x == nx && snake[i].y == ny) {
                return true;
            }
        }
        return false;
    }

} // namespace

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    const unsigned winW = kCols * kCell;
    const unsigned winH = kRows * kCell + 40;

    sf::RenderWindow window(sf::VideoMode(winW, winH), "Snake (SFML)");
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("C:/Windows/Fonts/msyh.ttc")) {
        font.loadFromFile("C:/Windows/Fonts/arial.ttf");
    }

    sf::Text hud;
    hud.setFont(font);
    hud.setCharacterSize(18);
    hud.setFillColor(sf::Color::White);
    hud.setPosition(sf::Vector2f(8.f, static_cast<float>(kRows * kCell + 6)));

    std::deque<sf::Vector2i> snake;
    snake.push_back(sf::Vector2i(kCols / 2, kRows / 2));
    snake.push_back(sf::Vector2i(kCols / 2 - 1, kRows / 2));

    sf::Vector2i food;
    placeFood(food, snake);

    int dirX = 1;
    int dirY = 0;
    int pendingX = 1;
    int pendingY = 0;

    int score = 0;
    bool alive = true;

    sf::Clock moveClock;
    sf::RectangleShape cell(sf::Vector2f(static_cast<float>(kCell - 2), static_cast<float>(kCell - 2)));

    while (window.isOpen()) {
        sf::Event ev;
        while (window.pollEvent(ev)) {
            if (ev.type == sf::Event::Closed) {
                window.close();
            }
            if (ev.type == sf::Event::KeyPressed) {
                if (ev.key.code == sf::Keyboard::Escape) {
                    window.close();
                    break;
                }
                if (!alive && ev.key.code == sf::Keyboard::R) {
                    snake.clear();
                    snake.push_back(sf::Vector2i(kCols / 2, kRows / 2));
                    snake.push_back(sf::Vector2i(kCols / 2 - 1, kRows / 2));
                    placeFood(food, snake);
                    dirX = 1;
                    dirY = 0;
                    pendingX = 1;
                    pendingY = 0;
                    score = 0;
                    alive = true;
                    moveClock.restart();
                }
                int nx = 0;
                int ny = 0;
                bool want = false;
                switch (ev.key.code) {
                case sf::Keyboard::Up:
                case sf::Keyboard::W:
                    nx = 0;
                    ny = -1;
                    want = true;
                    break;
                case sf::Keyboard::Down:
                case sf::Keyboard::S:
                    nx = 0;
                    ny = 1;
                    want = true;
                    break;
                case sf::Keyboard::Left:
                case sf::Keyboard::A:
                    nx = -1;
                    ny = 0;
                    want = true;
                    break;
                case sf::Keyboard::Right:
                case sf::Keyboard::D:
                    nx = 1;
                    ny = 0;
                    want = true;
                    break;
                default:
                    break;
                }
                if (want && !(nx == -dirX && ny == -dirY)) {
                    pendingX = nx;
                    pendingY = ny;
                }
            }
        }

        if (alive && moveClock.getElapsedTime().asSeconds() >= kMoveInterval) {
            moveClock.restart();
            dirX = pendingX;
            dirY = pendingY;

            sf::Vector2i head = snake.front();
            sf::Vector2i next(head.x + dirX, head.y + dirY);

            if (next.x < 0 || next.x >= kCols || next.y < 0 || next.y >= kRows) {
                alive = false;
            }
            else {
                bool eat = (next.x == food.x && next.y == food.y);
                if (hitsBody(next.x, next.y, snake, eat)) {
                    alive = false;
                }
                else {
                    snake.push_front(next);
                    if (eat) {
                        ++score;
                        placeFood(food, snake);
                    }
                    else {
                        snake.pop_back();
                    }
                }
            }
        }

        window.clear(sf::Color(30, 30, 40));

        cell.setFillColor(sf::Color(220, 60, 60));
        cell.setPosition(sf::Vector2f(
            static_cast<float>(food.x * kCell + 1), static_cast<float>(food.y * kCell + 1)));
        window.draw(cell);

        for (size_t i = 0; i < snake.size(); ++i) {
            const auto& p = snake[i];
            if (i == 0) {
                cell.setFillColor(sf::Color(80, 200, 120));
            }
            else {
                cell.setFillColor(sf::Color(50, 160, 90));
            }
            cell.setPosition(sf::Vector2f(
                static_cast<float>(p.x * kCell + 1), static_cast<float>(p.y * kCell + 1)));
            window.draw(cell);
        }

        if (alive) {
            hud.setString("Score: " + std::to_string(score) + "   ESC quit");
        }
        else {
            hud.setString("Game over  Score: " + std::to_string(score) + "   R restart   ESC quit");
        }
        window.draw(hud);

        window.display();
    }

    return 0;
}

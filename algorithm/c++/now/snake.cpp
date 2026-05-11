// Windows 控制台贪吃蛇：WASD 或方向键移动，ESC 退出
#include <conio.h>
#include <ctime>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <utility>
#include <windows.h>

using std::cout;
using std::deque;
using std::make_pair;
using std::pair;

static const int kWidth = 28;
static const int kHeight = 16;

static void setCursor(int x, int y) {
    COORD pos = {static_cast<SHORT>(x), static_cast<SHORT>(y)};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

static void setCursorVisible(bool visible) {
    CONSOLE_CURSOR_INFO ci = {1, visible ? TRUE : FALSE};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ci);
}

static bool collidesWithBody(int nx, int ny, const deque<pair<int, int>> &snake, bool willEat) {
    if (willEat) {
        for (const auto &seg : snake) {
            if (seg.first == nx && seg.second == ny) {
                return true;
            }
        }
        return false;
    }
    // 移动后尾部会离开一格，允许新头占用原尾部位置
    for (size_t i = 0; i + 1 < snake.size(); ++i) {
        if (snake[i].first == nx && snake[i].second == ny) {
            return true;
        }
    }
    return false;
}

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    setCursorVisible(false);

    deque<pair<int, int>> snake;
    snake.push_back(make_pair(kWidth / 2, kHeight / 2));
    snake.push_back(make_pair(kWidth / 2 - 1, kHeight / 2));

    int dx = 1;
    int dy = 0;
    int foodX = 0;
    int foodY = 0;

    auto placeFood = [&]() {
        for (;;) {
            foodX = std::rand() % kWidth;
            foodY = std::rand() % kHeight;
            bool ok = true;
            for (const auto &seg : snake) {
                if (seg.first == foodX && seg.second == foodY) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                break;
            }
        }
    };
    placeFood();

    int score = 0;
    bool running = true;

    while (running) {
        while (_kbhit()) {
            int c = _getch();
            if (c == 0 || c == 224) {
                c = _getch();
            }
            int ndx = dx;
            int ndy = dy;
            switch (c) {
                case 'w':
                case 'W':
                case 72:
                    ndx = 0;
                    ndy = -1;
                    break;
                case 's':
                case 'S':
                case 80:
                    ndx = 0;
                    ndy = 1;
                    break;
                case 'a':
                case 'A':
                case 75:
                    ndx = -1;
                    ndy = 0;
                    break;
                case 'd':
                case 'D':
                case 77:
                    ndx = 1;
                    ndy = 0;
                    break;
                case 27:
                    running = false;
                    break;
                default:
                    break;
            }
            if (!(ndx == -dx && ndy == -dy)) {
                dx = ndx;
                dy = ndy;
            }
        }

        if (!running) {
            break;
        }

        int nx = snake.front().first + dx;
        int ny = snake.front().second + dy;

        if (nx < 0 || nx >= kWidth || ny < 0 || ny >= kHeight) {
            break;
        }

        bool willEat = (nx == foodX && ny == foodY);
        if (collidesWithBody(nx, ny, snake, willEat)) {
            break;
        }

        snake.push_front(make_pair(nx, ny));
        if (willEat) {
            ++score;
            placeFood();
        } else {
            snake.pop_back();
        }

        setCursor(0, 0);
        cout << '+';
        for (int i = 0; i < kWidth; ++i) {
            cout << '-';
        }
        cout << "+\n";
        for (int y = 0; y < kHeight; ++y) {
            cout << '|';
            for (int x = 0; x < kWidth; ++x) {
                char ch = ' ';
                if (x == foodX && y == foodY) {
                    ch = '*';
                }
                size_t idx = 0;
                for (const auto &seg : snake) {
                    if (seg.first == x && seg.second == y) {
                        ch = (idx == 0) ? '@' : 'o';
                        break;
                    }
                    ++idx;
                }
                cout << ch;
            }
            cout << "|\n";
        }
        cout << '+';
        for (int i = 0; i < kWidth; ++i) {
            cout << '-';
        }
        cout << "+\n";
        cout << "Score: " << score << "   WASD / arrows   ESC quit\n";

        Sleep(130);
    }

    setCursorVisible(true);
    setCursor(0, kHeight + 2);
    cout << "Game over. Final score: " << score << '\n';
    return 0;
}

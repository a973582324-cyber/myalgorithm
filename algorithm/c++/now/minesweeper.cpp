// Windows 控制台扫雷：方向键移动，Enter 翻开，F 标记/取消，Q 退出
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <windows.h>

using std::cout;
using std::make_pair;
using std::pair;
using std::queue;
using std::vector;

static const int kRows = 9;
static const int kCols = 9;
static const int kMineCount = 10;

static vector<vector<bool>> gMine;
static vector<vector<bool>> gRevealed;
static vector<vector<bool>> gFlagged;
static bool gMinesPlaced = false;
static bool gGameOver = false;
static bool gWon = false;
static int gCurR = 0;
static int gCurC = 0;

static void setCursor(int x, int y) {
    COORD pos = {static_cast<SHORT>(x), static_cast<SHORT>(y)};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

static void setCursorVisible(bool visible) {
    CONSOLE_CURSOR_INFO ci = {1, visible ? TRUE : FALSE};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ci);
}

static int countAdjacent(int r, int c) {
    int n = 0;
    for (int dr = -1; dr <= 1; ++dr) {
        for (int dc = -1; dc <= 1; ++dc) {
            if (dr == 0 && dc == 0) {
                continue;
            }
            int nr = r + dr;
            int nc = c + dc;
            if (nr >= 0 && nr < kRows && nc >= 0 && nc < kCols && gMine[nr][nc]) {
                ++n;
            }
        }
    }
    return n;
}

static void placeMines(int safeR, int safeC) {
    gMine.assign(kRows, vector<bool>(kCols, false));
    int placed = 0;
    while (placed < kMineCount) {
        int r = std::rand() % kRows;
        int c = std::rand() % kCols;
        if (gMine[r][c]) {
            continue;
        }
        bool nearSafe = false;
        for (int dr = -1; dr <= 1 && !nearSafe; ++dr) {
            for (int dc = -1; dc <= 1; ++dc) {
                if (r == safeR + dr && c == safeC + dc) {
                    nearSafe = true;
                    break;
                }
            }
        }
        if (nearSafe) {
            continue;
        }
        gMine[r][c] = true;
        ++placed;
    }
    gMinesPlaced = true;
}

static void floodReveal(int sr, int sc) {
    queue<pair<int, int>> q;
    q.push(make_pair(sr, sc));
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        if (r < 0 || r >= kRows || c < 0 || c >= kCols) {
            continue;
        }
        if (gFlagged[r][c] || gRevealed[r][c]) {
            continue;
        }
        if (gMine[r][c]) {
            continue;
        }
        gRevealed[r][c] = true;
        if (countAdjacent(r, c) == 0) {
            for (int dr = -1; dr <= 1; ++dr) {
                for (int dc = -1; dc <= 1; ++dc) {
                    if (dr == 0 && dc == 0) {
                        continue;
                    }
                    q.push(make_pair(r + dr, c + dc));
                }
            }
        }
    }
}

static void tryReveal(int r, int c) {
    if (gGameOver || gWon) {
        return;
    }
    if (gFlagged[r][c] || gRevealed[r][c]) {
        return;
    }
    if (!gMinesPlaced) {
        placeMines(r, c);
    }
    if (gMine[r][c]) {
        gGameOver = true;
        for (int i = 0; i < kRows; ++i) {
            for (int j = 0; j < kCols; ++j) {
                if (gMine[i][j]) {
                    gRevealed[i][j] = true;
                }
            }
        }
        return;
    }
    floodReveal(r, c);

    int revealedSafe = 0;
    for (int i = 0; i < kRows; ++i) {
        for (int j = 0; j < kCols; ++j) {
            if (gRevealed[i][j] && !gMine[i][j]) {
                ++revealedSafe;
            }
        }
    }
    if (revealedSafe == kRows * kCols - kMineCount) {
        gWon = true;
    }
}

static void toggleFlag(int r, int c) {
    if (gGameOver || gWon) {
        return;
    }
    if (gRevealed[r][c]) {
        return;
    }
    gFlagged[r][c] = !gFlagged[r][c];
}

static void draw() {
    setCursor(0, 0);
    int flags = 0;
    for (int i = 0; i < kRows; ++i) {
        for (int j = 0; j < kCols; ++j) {
            if (gFlagged[i][j]) {
                ++flags;
            }
        }
    }

    for (int i = 0; i < kRows; ++i) {
        for (int j = 0; j < kCols; ++j) {
            char ch = '#';
            bool onCur = (i == gCurR && j == gCurC);
            if (!gRevealed[i][j]) {
                ch = gFlagged[i][j] ? 'F' : '#';
            } else if (gMine[i][j]) {
                ch = '*';
            } else {
                int n = countAdjacent(i, j);
                ch = (n == 0) ? '.' : static_cast<char>('0' + n);
            }
            if (onCur) {
                cout << '[' << ch << ']';
            } else {
                cout << ' ' << ch << ' ';
            }
        }
        cout << '\n';
    }

    cout << "mines: " << kMineCount << "  flags: " << flags;
    if (gGameOver) {
        cout << "  BOOM!";
    } else if (gWon) {
        cout << "  YOU WIN!";
    }
    cout << "\nArrows move  Enter reveal  F flag  Q quit\n";
}

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    setCursorVisible(false);

    gMine.assign(kRows, vector<bool>(kCols, false));
    gRevealed.assign(kRows, vector<bool>(kCols, false));
    gFlagged.assign(kRows, vector<bool>(kCols, false));

    bool quit = false;
    while (!quit) {
        while (_kbhit()) {
            int c = _getch();
            if (c == 0 || c == 224) {
                c = _getch();
            }
            switch (c) {
                case 72:
                    if (gCurR > 0) {
                        --gCurR;
                    }
                    break;
                case 80:
                    if (gCurR + 1 < kRows) {
                        ++gCurR;
                    }
                    break;
                case 75:
                    if (gCurC > 0) {
                        --gCurC;
                    }
                    break;
                case 77:
                    if (gCurC + 1 < kCols) {
                        ++gCurC;
                    }
                    break;
                case '\r':
                case ' ':
                    tryReveal(gCurR, gCurC);
                    break;
                case 'f':
                case 'F':
                    toggleFlag(gCurR, gCurC);
                    break;
                case 'q':
                case 'Q':
                    quit = true;
                    break;
                default:
                    break;
            }
        }
        if (quit) {
            break;
        }
        draw();
        Sleep(80);
    }

    setCursorVisible(true);
    setCursor(0, kRows + 3);
    if (gWon) {
        cout << "You cleared the field.\n";
    } else if (gGameOver) {
        cout << "You hit a mine.\n";
    } else {
        cout << "Bye.\n";
    }
    return 0;
}

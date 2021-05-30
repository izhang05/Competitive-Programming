#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 8;

char grid[maxn][maxn];

bool avail[maxn][maxn];

bool valid(int x, int y) {
    return x >= 0 && y >= 0 && x < maxn && y < maxn;
}

pair<int, int> get_ind(string s) {
#ifdef DEBUG
    cout << s << " " << s[0] - 'a' << " " << s[1] - '1' << endl;
#endif
    return {s[0] - 'a', s[1] - '1'};
}

void rook(int x, int y) {
    for (int k = 1;; ++k) {
        int nx = x + k, ny = y;
        if (valid(nx, ny)) {
            avail[nx][ny] = false;
            if (grid[nx][ny] != 0) {
                break;
            }
        } else {
            break;
        }
    }
    for (int k = -1;; --k) {
        int nx = x + k, ny = y;
        if (valid(nx, ny)) {
            avail[nx][ny] = false;
            if (grid[nx][ny] != 0) {
                break;
            }
        } else {
            break;
        }
    }
    for (int k = 1;; ++k) {
        int nx = x, ny = y + k;
        if (valid(nx, ny)) {
            avail[nx][ny] = false;
            if (grid[nx][ny] != 0) {
                break;
            }
        } else {
            break;
        }
    }
    for (int k = -1;; --k) {
        int nx = x, ny = y + k;
        if (valid(nx, ny)) {
            avail[nx][ny] = false;
            if (grid[nx][ny] != 0) {
                break;
            }
        } else {
            break;
        }
    }
}

void bishop(int x, int y) {
    for (int k = 1;; ++k) {
        int nx = x + k, ny = y + k;
        if (valid(nx, ny)) {
            avail[nx][ny] = false;
            if (grid[nx][ny] != 0) {
                break;
            }
        } else {
            break;
        }
    }
    for (int k = 1;; ++k) {
        int nx = x + k, ny = y - k;
        if (valid(nx, ny)) {
            avail[nx][ny] = false;
            if (grid[nx][ny] != 0) {
                break;
            }
        } else {
            break;
        }
    }
    for (int k = 1;; ++k) {
        int nx = x - k, ny = y + k;
        if (valid(nx, ny)) {
            avail[nx][ny] = false;
            if (grid[nx][ny] != 0) {
                break;
            }
        } else {
            break;
        }
    }
    for (int k = 1;; ++k) {
        int nx = x - k, ny = y - k;
        if (valid(nx, ny)) {
            avail[nx][ny] = false;
            if (grid[nx][ny] != 0) {
                break;
            }
        } else {
            break;
        }
    }
}

void knight(int x, int y) {
    for (auto &i : {-2, 2}) {
        for (auto &j : {-1, 1}) {
            int nx = x + i, ny = y + j;
            if (valid(nx, ny)) {
                avail[nx][ny] = false;
            }
        }
    }
    for (auto &i : {-1, 1}) {
        for (auto &j : {-2, 2}) {
            int nx = x + i, ny = y + j;
            if (valid(nx, ny)) {
                avail[nx][ny] = false;
            }
        }
    }
}

void pawn(int x, int y) {
    for (int i = -1; i <= 1; ++i) {
        if (i == 0) {
            continue;
        }
        int nx = x + i, ny = y + 1;
        if (valid(nx, ny)) {
            avail[nx][ny] = false;
        }
    }
}

string find_king_status(string s) {
    int n = ((int) s.size() + 1) / 4;
#ifdef DEBUG
    cout << n << endl;
#endif
    pair<int, int> king;
    for (int i = 0; i < n; ++i) {
        char p = s[4 * i];
        string cur;
        cur.push_back(s[4 * i + 1]);
        cur.push_back(s[4 * i + 2]);
        pair<int, int> ind = get_ind(cur);
        if (p == 'K') {
            king = ind;
        } else {
            grid[ind.first][ind.second] = p;
        }
    }
#ifdef DEBUG
    cout << "king: " << king.first << " " << king.second << endl;
#endif
    memset(avail, true, sizeof(avail));
    for (int i = 0; i < maxn; ++i) {
        for (int j = 0; j < maxn; ++j) {
            if (grid[i][j] == 'R') {
                rook(i, j);
            } else if (grid[i][j] == 'B') {
                bishop(i, j);
            } else if (grid[i][j] == 'Q') {
                rook(i, j);
                bishop(i, j);
            } else if (grid[i][j] == 'N') {
                knight(i, j);
            } else if (grid[i][j] == 'P') {
                pawn(i, j);
            }
        }
    }
    bool check = !avail[king.first][king.second], move = false;
    for (int i = -1; i <= 1 && !move; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) {
                continue;
            }
            int nx = king.first + i, ny = king.second + j;
            if (valid(nx, ny) && avail[nx][ny]) {
#ifdef DEBUG
                cout << "avail: " << nx << " " << ny << endl;
#endif
                move = true;
                break;
            }
        }
    }

    if (check) {
        if (move) {
            return "CHECK";
        } else {
            return "CHECKMATE";
        }
    } else {
        if (move) {
            return "SAFE";
        } else {
            return "STALEMATE";
        }
    }
}

int main() {
    setIO("c");
    string pieces;
    getline(cin, pieces);

    string result = find_king_status(pieces);

    cout << "result: " << result << "\n";

    return 0;
}

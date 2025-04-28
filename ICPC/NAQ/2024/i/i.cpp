#include <bits/stdc++.h>

using namespace std;

#if defined LOCAL || defined DEBUG

#include <debug.h>

#else
struct dbg {
    template<class c>
    dbg &operator<<(const c &) { return *this; }
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#endif

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("out.txt", "w", stderr);
#endif
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 35;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
char grid[mxn][mxn];
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int n;

bool valid(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < n;
}


void test_case() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j) {
            grid[i][j] = s[j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] >= '0' && grid[i][j] <= '9') {
                int cnt = 0;
                for (int k = 0; k < 4; ++k) {
                    int nx = i + dx[k], ny = j + dy[k];
                    if (valid(nx, ny) && grid[nx][ny] == '?') {
                        ++cnt;
                    }
                }
                if (cnt != grid[i][j] - '0') {
                    cout << 0 << "\n";
                    return;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '?') {
                for (int k = 0; k < 4; ++k) {
                    int nx = i + dx[k], ny = j + dy[k];
                    while (valid(nx, ny)) {
                        if (grid[nx][ny] == '?') {
                            cout << 0 << "\n";
                            return;
                        }
                        if ((grid[nx][ny] >= '0' && grid[nx][ny] <= '9') || grid[nx][ny] == 'X') {
                            break;
                        }
                        grid[nx][ny] = '#';
                        nx += dx[k], ny += dy[k];
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '.') {
                cout << 0 << "\n";
                return;
            }
        }
    }
    cout << 1 << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}

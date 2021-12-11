#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
//    freopen("out.txt", "w", stdout);
//    freopen("out.txt", "w", stderr);
#endif
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
int grid[10][10];
int new_grid[10][10];

bool valid(int x, int y) {
    return x >= 0 && y >= 0 && x < 10 && y < 10;
}

void test_case() {
    int n = 10;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j) {
            grid[i][j] = s[j] - '0';
        }
    }
    int sol = 0;
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                ++grid[j][k];
            }
        }
        bool changed = true;
        while (changed) {
            changed = false;
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (grid[j][k] > 9) {
                        changed = true;
                        ++sol;
                        for (auto &l: vector<int>{-1, 0, 1}) {
                            for (auto &m: vector<int>{-1, 0, 1}) {
                                int nx = j + l, ny = m + k;
                                if (valid(nx, ny)) {
                                    ++grid[nx][ny];
                                }
                            }
                        }
                        grid[j][k] = -inf;
                    }
                }
            }
        }
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                if (grid[j][k] < 0) {
                    grid[j][k] = 0;
                }
            }
        }
    }
    cout << sol << "\n";
}

int main() {
    setIO("11");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}

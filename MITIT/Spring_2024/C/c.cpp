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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 1e3 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
char grid[mxn][mxn];
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int n, m;

bool valid(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}


void test_case() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    long long sol = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'o') {
                vector<pair<int, int>> bad;
                for (int k = 0; k < 4; ++k) {
                    int nx = i + dx[k], ny = j + dy[k];
                    if (!valid(nx, ny) || grid[nx][ny] != '.') {
                        bad.emplace_back(nx, ny);
                    }
                }
                if (bad.size() == 0) {
                    sol *= 4;
                } else if (bad.size() == 1) {
                    sol *= 2;
                } else if (bad.size() >= 3) {
                    sol *= 0;
                } else {
                    if (bad.size() != 2) {
                        sol *= 0;
                        continue;
                    }
                    if (abs(bad[0].first - bad[1].first) + abs(bad[0].second - bad[1].second) != 2) {
                        sol *= 0;
                    }
                }
                sol %= mod;
            }
        }
    }
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}

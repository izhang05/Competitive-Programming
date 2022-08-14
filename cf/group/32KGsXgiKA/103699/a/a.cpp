/* Author: izhang
 * Time: 07-07-2022 22:31:59
**/
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 5e3 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
bool used[maxn][maxn];
int ind[maxn][maxn];

int r, c;
bool good(pair<int, int> x) {
    return x.first >= 0 && x.second >= 0 && x.first < r && x.second < c;
}

void test_case() {
    cin >> r >> c;
    int n;
    cin >> n;
    memset(ind, -1, sizeof(ind));
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
        --a[i].first, --a[i].second;
        used[i][i] = true;
        ind[a[i].first][a[i].second] = i;
    }
    int sol = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (used[i][j]) {
                continue;
            }
            used[i][j] = true;
            int dx = a[j].first - a[i].first, dy = a[j].second - a[i].second, cur = 2;
            pair<int, int> pos = a[j];
            while (good({pos.first + dx, pos.second + dy}) && ind[pos.first][pos.second] != -1) {
                ++cur;
                int pre = ind[pos.first][pos.second];
                pos.first += dx, pos.second += dy;
                used[pre][ind[pos.first][pos.second]] = true;
            }
            if (good({pos.first + dx, pos.second + dy})) {
                continue;
            }
            pos = a[i];
            while (good({pos.first - dx, pos.second - dy}) && ind[pos.first][pos.second] != -1) {
                ++cur;
                int pre = ind[pos.first][pos.second];
                pos.first -= dx, pos.second -= dy;
                used[pre][ind[pos.first][pos.second]] = true;
            }
            if (good({pos.first - dx, pos.second - dy})) {
                continue;
            }
            sol = max(sol, cur);
        }
    }
    cout << (sol > 2 ? sol : 0) << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}

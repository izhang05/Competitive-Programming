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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 110;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
bool grid[maxn][maxn][maxn];

void test_case() {
    int n = 420;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        pair<int, int> x;
        cin >> x.first >> x.second;
        x.first += 50, x.second += 50;
        pair<int, int> y;
        cin >> y.first >> y.second;
        y.first += 50, y.second += 50;
        pair<int, int> z;
        cin >> z.first >> z.second;
        z.first += 50, z.second += 50;
        for (int j = x.first; j <= x.second; ++j) {
            for (int k = y.first; k <= y.second; ++k) {
                for (int l = z.first; l <= z.second; ++l) {
                    grid[j][k][l] = t;
                }
            }
        }
    }
    int sol = 0;
    for (auto &i : grid) {
        for (auto &j : i) {
            for (auto &k : j) {
                if (k) {
                    ++sol;
                }
            }
        }
    }
    cout << sol << "\n";
}

int main() {
    setIO("22");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}

/* Author: izhang05
 * Time: 12-26-2021 12:41:54
**/
#include <bits/stdc++.h>

using namespace std;

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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5, k = 300;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
struct train {
    int start, x, y;
    [[nodiscard]] bool maint(int t) const {
        return ((t - start) % (x + y)) >= x;
    }
};

vector<train> a;
int n, m;
int pre[maxn], cnt[k][k];

void test_case() {
    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y;
    }
    int cur = 0;
    for (int i = 0; i < m; ++i) {
        cur += pre[i];
        int t, c;
        cin >> t >> c;
        --c;
        if (t == 1) {
            a[c].start = i;
            int sum = a[c].x + a[c].y;
            if (sum >= k) {
                for (int j = i; j < m; j += a[c].x + a[c].y) {
                    if (j + a[c].x < m) {
                        ++pre[j + a[c].x];
                    }
                    if (j + a[c].x + a[c].y < m) {
                        --pre[j + a[c].x + a[c].y];
                    }
                }
            } else {
                for (int j = i + a[c].x; j < min(m, i + sum); ++j) {
                    ++cnt[sum][j % sum];
                }
            }
        } else {
            int sum = a[c].x + a[c].y;
            if (sum >= k) {
                if (a[c].maint(i)) {
                    --cur;
                }
                for (int j = a[c].start; j < m; j += a[c].x + a[c].y) {
                    if (j + a[c].x < m) {
                        --pre[j + a[c].x];
                    }
                    if (j + a[c].x + a[c].y < m) {
                        ++pre[j + a[c].x + a[c].y];
                    }
                }
            } else {
                for (int j = a[c].start + a[c].x; j < min(m, a[c].start + sum); ++j) {
                    --cnt[sum][j % sum];
                }
            }
        }
        int sol = cur;
        for (int j = 1; j < k; ++j) {
            sol += cnt[j][i % j];
        }
        cout << sol << "\n";
    }
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}

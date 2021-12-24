/* Author: izhang05
 * Time: 12-23-2021 20:40:02
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

void test_case() {
    int n;
    cin >> n;
    vector<int> a(n);
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    vector<int> cur(n);
    map<pair<int, int>, int> bonus;
    int q;
    cin >> q;
    long long sol = 0;
    while (q--) {
        int s, t, u;
        cin >> s >> t >> u;
        --s, --u;
        if (bonus.find({s, t}) != bonus.end()) {
            int ind = bonus[{s, t}];
            if (cur[ind] <= a[ind]) {
                --sol;
            }
            --cur[ind];
        }
        if (u != -1) {
            if (cur[u] < a[u]) {
                ++sol;
            }
            ++cur[u];
            bonus[{s, t}] = u;
        } else {
            bonus.erase({s, t});
        }
        cout << max(1ll, sum - sol) << "\n";
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

/* Author: izhang05
 * Time: 09-14-2021 17:17:11
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

template<class T>
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n * m);
    set<int> nums;
    for (int i = 0; i < n * m; ++i) {
        cin >> a[i];
        nums.insert(a[i]);
    }
    map<int, int> ind;
    int tmp = 0;
    for (auto &i : nums) {
        ind[i] = tmp++;
    }
    for (int i = 0; i < n * m; ++i) {
        a[i] = ind[a[i]];
    }
    vector<int> order;
    int cur = 0;
    for (int i = 0; i < m;) {
        bool found = false;
        for (int j = m - 1; j >= 0; --j) {
            if (a[j] == cur) {
                a[j] = inf;
                order.push_back(j);
                found = true;
                break;
            }
        }
        if (!found) {
            ++cur, ++i;
        }
    }
    vector<bool> filled(m);
    int sol = 0;
    for (auto &i : order) {
        for (int j = 0; j < i; ++j) {
            if (filled[j]) {
                ++sol;
            }
        }
        filled[i] = true;
    }
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/* Author: izhang05
 * Time: 07-19-2021 23:59:18
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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    int j = 0;
    multiset<int> occ;
    for (int i = 0; i < n; ++i) {
        if (occ.empty() || *occ.begin() > b[i]) {
            while (j < n) {
                int cur = a[j++];
                occ.insert(cur);
                if (cur <= b[i]) {
                    if (j - 2 > i) {
                        swap(a[j - 1], a[j - 2]);
                        --j;
                        if (occ.find(a[j]) == occ.end()) {
                            a[j] = *prev(occ.end());
                            occ.erase(prev(occ.end()));
                        } else {
                            occ.erase(occ.find(a[j]));
                        }
#ifdef DEBUG
                        cout << a[j] << "\n";
                        for (auto &k : occ) {
                            cout << k << " ";
                        }
                        cout << endl;
#endif
                    }
                    break;
                }
            }
        }
        if (occ.empty() || *occ.begin() != b[i]) {
            cout << "NO"
                 << "\n";
            return;
        }
        occ.erase(occ.begin());
    }
    cout << "YES"
         << "\n";
}

int main() {
    setIO("3");

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

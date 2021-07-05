/* Author: izhang05
 * Time: 07-04-2021 22:41:48
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


int main() {
    setIO("1");

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        deque<int> sol;
        for (auto &i : a) {
            if (i % 2) {
                sol.push_front(i);
            } else {
                sol.push_back(i);
            }
        }
        for (auto &i : sol) {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}

/* Author: izhang05
 * Time: 06-25-2021 11:35:03
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
        vector<int> a(n + 1);
        vector<unordered_map<int, int>> occ(2 * n + 2);
        long long sol = 0;
        for (int i = 1; i < n + 1; ++i) {
            cin >> a[i];
            sol += occ[a[i]][i];
            int cur = a[i] - i, cnt = 1;
            while (cur <= 2 * n + 1 && cnt <= 2 * n + 1) {
                ++occ[cnt][cur];
                ++cnt;
                cur += a[i];
            }
        }
        cout << sol << "\n";
    }
    return 0;
}

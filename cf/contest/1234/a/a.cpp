/* Author: izhang05
 * Time: 07-02-2021 21:35:27
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
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
        }
        cout << (sum + n - 1) / n << "\n";
    }
    return 0;
}

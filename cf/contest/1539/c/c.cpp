/* Author: izhang05
 * Time: 06-22-2021 21:25:02
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

    long long n, k, x;
    cin >> n >> k >> x;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long pre = a[0];
    vector<long long> diff;
    for (int i = 1; i < n; ++i) {
        if (a[i] - pre > x) {
            diff.push_back((a[i] - pre - 1) / x);
        }
        pre = a[i];
    }
    int sol = int(diff.size()) + 1;
    sort(diff.begin(), diff.end());
    for (int i = 0; i < int(diff.size()) && k > 0; ++i) {
        if (diff[i] <= k) {
            k -= diff[i];
            --sol;
        } else {
            break;
        }
    }
    cout << sol << "\n";
    return 0;
}

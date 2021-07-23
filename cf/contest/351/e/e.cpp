/* Author: izhang05
 * Time: 07-23-2021 15:24:57
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

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] = abs(a[i]);
    }
    long long sol = 0;
    while (!a.empty()) {
        int mx = *max_element(a.begin(), a.end()), num = (int) count(a.begin(), a.end(), mx);
        int l = 0, r = (int) a.size() - num;
        for (auto &i : a) {
            ++l, --r;
            if (i == mx) {
                --l, ++r;
                sol += min(l, r);
            }
        }
        a.erase(remove(a.begin(), a.end(), mx), a.end());
    }
    cout << sol << "\n";
    return 0;
}

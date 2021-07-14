/* Author: izhang05
 * Time: 07-13-2021 22:22:56
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
    vector<int> a(n), occ(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        occ[a[i]] = i;
    }
    vector<int> b(n);
    multiset<int> left, right;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        --b[i];
        if (occ[b[i]] < i) {
            right.insert(i - occ[b[i]]);
        } else {
            left.insert(occ[b[i]] - i);
        }
    }
    for (int i = 0; i < n; ++i) {
        int sol = inf;
        if (!left.empty()) {
            sol = *left.begin() + i;
        }
        if (!right.empty()) {
            sol = min(sol, *right.begin() - i);
        }
        cout << sol << endl;
        while (!right.empty() && *right.begin() - i == 1) {
            right.erase(right.begin());
            left.insert(-i - 1);
        }
        assert(left.find(occ[b[i]] - i) != left.end());
        left.erase(left.find(occ[b[i]] - i));
        if (occ[b[i]] == n - 1) {
            left.insert(-i - 1);
        } else {
            right.insert(n - occ[b[i]] + i);
        }
    }
    return 0;
}

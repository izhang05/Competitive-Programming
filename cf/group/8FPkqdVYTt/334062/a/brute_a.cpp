/* Author: izhang05
 * Time: 07-10-2021 16:27:05
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifndef TEST
    freopen((name + ".in").c_str(), "r", stdin);
//    freopen((name + ".out").c_str(), "w", stdout);
//    freopen((name + ".out").c_str(), "w", stderr);
#endif
}
template<class T>
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}

int main() {
    setIO("mincross");
    int n;
    cin >> n;
    vector<int> a(n), occ(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        occ[a[i]] = i;
    }
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        --b[i];
    }
    long long sol = 1e18;
    for (int i = 0; i < n; ++i) {
        long long cur = 0;
        for (int j = 0; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (occ[b[k]] < occ[b[j]]) {
                    ++cur;
                }
            }
        }
        sol = min(sol, cur);
        rotate(b.begin(), b.begin() + 1, b.end());
    }

    cout << sol << "\n";
    return 0;
}

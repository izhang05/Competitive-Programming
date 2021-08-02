/*
ID: izhang01
TASK: sort
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    freopen("sort.out", "w", stderr);
}
//#define DEBUG

int main() {
    setIO();
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> sorted_a(a.begin(), a.end());
    sort(sorted_a.begin(), sorted_a.end());
    map<int, int> cnt;
    int sol = 1, cur = 0;
    for (int i = 0; i < n; ++i) {
        if (++cnt[a[i]] > 0) {
            ++cur;
        }
        if (--cnt[sorted_a[i]] >= 0) {
            --cur;
        }
        sol = max(sol, cur);
    }
    cout << sol << "\n";
    return 0;
}

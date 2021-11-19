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
    map<int, queue<int>> ind;
    int cur = 0;
    for (auto &i : sorted_a) {
        ind[i].push(cur);
        i = cur++;
    }
    vector<int> loc(n);
    for (int i = 0; i < n; ++i) {
        int cur_val = ind[a[i]].front();
        ind[a[i]].pop();
        a[i] = cur_val;
        loc[a[i]] = i;
#ifdef DEBUG
        cout << a[i] << " ";
#endif
    }
#ifdef DEBUG
    cout << "\n";
    cout << "\n";
    for (int i = 0; i < n; ++i) {
        cout << loc[i] << " ";
    }
    cout << "\n";
#endif
    vector<int> sol(n);
    set<int> large;
    int mx = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i - 1] > sorted_a[i - 1]) {
            large.insert(a[i - 1]);
        }
        large.erase(sorted_a[i - 1]);
        mx = max(mx, loc[sorted_a[i - 1]]);
        int cur_val = max({int(large.size()), mx - (i - 1), 1});
        sol[i] = cur_val;
        sol[i - 1] = max(sol[i - 1], cur_val);
    }
    cout << accumulate(sol.begin(), sol.end(), 0ll) << "\n";
    return 0;
}

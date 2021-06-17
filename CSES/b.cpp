#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}
template<class T>
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5;
int pre[maxn];

int main() {
    setIO("b");

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    map<int, pair<int, int>> best;
    pair<int, int> sol;
    for (int i = 0; i < n; ++i) {
        int v = a[i], cur;
        if (best.find(v - 1) == best.end()) {
            cur = 1;
            pre[i] = i;
        } else {
            cur = best[v - 1].first + 1;
            pre[i] = best[v - 1].second;
        }
        best[v] = max(best[v], {cur, i});
        sol = max(sol, {cur, i});
    }
    cout << sol.first << "\n";
    vector<int> ind{sol.second + 1};
    int cur = sol.second;
    while (pre[cur] != cur) {
        cur = pre[cur];
        ind.push_back(cur + 1);
    }
    reverse(ind.begin(), ind.end());
    print(ind);

    return 0;
}

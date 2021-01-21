/*
ID: izhang01
TASK: cereal
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("cereal.in", "r", stdin);
    freopen("cereal.out", "w", stdout);
}
const int maxn = 1e5 + 5;
int state[maxn], cur = 0, taken[maxn];

void solve(int x) {

}


int main() {
    setIO();
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> fav(n);
    for (int i = 0; i < n; ++i) {
        cin >> fav[i].first >> fav[i].second;
        --fav[i].first, --fav[i].second;
        taken[i] = -1;
        state[i] = -1;
    }
    vector<int> sol(n);
    for (int i = n - 1; i >= 0; --i) {
        solve(i);
        sol[i] = cur;
    }
    for (int i = 0; i < n; ++i) {
        cout << sol[i] << "\n";
    }
    return 0;
}

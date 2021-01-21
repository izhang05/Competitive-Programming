/*
ID: izhang01
TASK: planting
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 1;
int deg[maxn];

int main() {
    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);
    int n;
    cin >> n;
    int a, b, sol = 0;
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        sol = max({sol, ++deg[a], ++deg[b]});
    }
    cout << sol + 1 << "\n";
    return 0;
}

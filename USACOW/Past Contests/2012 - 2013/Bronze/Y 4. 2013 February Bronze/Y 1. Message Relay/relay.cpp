/*
ID: izhang01
TASK: relay
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("relay.in", "r", stdin);
    freopen("relay.out", "w", stdout);
}
const int maxn = 1e3;
int p[maxn];
bool v[maxn], pos;

void dfs(int n) {
    if (n == -1) {
        return;
    }
    if (v[n]) {
        pos = false;
        return;
    }
    v[n] = true;
    dfs(p[n]);
}

int main() {
    setIO();
    int n;
    cin >> n;
    int a;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        p[i] = a - 1;
    }
    int sol = 0;
    for (int i = 0; i < n; ++i) {
        pos = true;
        memset(v, 0, sizeof(v));
        dfs(i);
        sol += pos;
    }
    cout << sol << "\n";
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());

//#define DEBUG
void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    freopen("1.out", "w", stderr);
#endif
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e3 + 5;
int adj[maxn];
bool visited[maxn];

void sol(int c) {
    visited[c] = true;
    if (visited[adj[c]]) {
        cout << adj[c] + 1 << "\n";
        return;
    }
    sol(adj[c]);
}


int main() {
    setIO();

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        --a;
        adj[i] = a;
    }
    for (int i = 0; i < n; ++i) {
        memset(visited, false, sizeof(visited));
        sol(i);
    }
    return 0;
}

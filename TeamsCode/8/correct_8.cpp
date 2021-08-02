#include <iostream>
#include <cassert>
#include <vector>

#define pb push_back

const int MX = 5e5 + 10;
using namespace std;

int dep[MX]; //max distance leaf
int cnt[MX], temp[MX]; //cnt and temp...
int cpy[MX][50]; //my way of storing the answer
vector<int> adj[MX];
int n;

int ans = 0; //answer in a global counter

int dfs1(int u, int p) { //compute dep
    dep[u] = 0;
    for (int v : adj[u]) {
        if (v != p) {
            dep[u] = max(dep[u], dfs1(v, u) + 1);
        }
    }
    return dep[u]; //if u is a leaf, the dep[u] will still be 0
}

void dfs2(int u, int p, int d) { //computing temp
    temp[d]++;
    for (int v : adj[u]) {
        if (v != p) {
            dfs2(v, u, d + 1);
        }
    }
}

void dfs3(int u, int p, int d) { //actual answer finding
    for (int i = 0; i <= dep[u]; i++) {
        cpy[i][d] = cnt[i]; //1. copying down the answer
    }
    for (int i = 0; i <= dep[u]; i++) {
        temp[i] = 0; //temp isnt all 0's from the previous use of it
    }
    dfs2(u, p, 0); //2. compute temp
    if (u == 1) {
        for (int i = 0; i <= dep[u]; i++) {
            cnt[i] = temp[i]; //case when u is the root
        }
    } else {
        for (int i = dep[u]; i >= 0; i--) {
            cnt[i] = (i > 0 ? cnt[i - 1] : 0) + (temp[i] - ((i > 1) ? temp[i - 2] : 0));
            //3. recompute cnt
        }
    }
    for (int i = 0; i <= dep[u]; i++) {
        ans = max(ans, cnt[i]); //4. account for the answer
    }
    for (int v : adj[u]) {
        if (v != p) {
            dfs3(v, u, d + 1); //5. dfs again
        }
    }
    for (int i = 0; i <= dep[u]; i++) {
        cnt[i] = cpy[i][d]; //6. restoring answer
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        ans = 0;
        for (int i = 0; i <= n + 1; i++) {
            cnt[i] = temp[i] = dep[i] = 0;
            adj[i].clear();
            for (int j = 0; j < 50; j++) cpy[i][j] = 0;
        }
        for (int i = 1; i < n; i++) {
            int a = i, b = n % i;
            a++, b++; //making the tree 1-based
            adj[a].pb(b);
            adj[b].pb(a);
        }
        dfs1(1, 0);
        dfs3(1, 0, 0);
        cout << ans << "\n";
    }
    return 0;
}

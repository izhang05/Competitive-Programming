#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int add(int a, int b) {
    int c = a + b;
    if(c >= MOD) c -= MOD;
    return c;
}

int mult(int a, int b) {
    return (1ll * a * b) % MOD;
}

int binpow(int a, int b) {
    int c = 1;
    for(; b > 0; b /= 2, a = mult(a, a)) if(b & 1) c = mult(c, a);
    return c;
}

int divide(int a, int b) {
    return mult(a, binpow(b, MOD - 2));
}

int n;

vector<vector<int>> tree;
vector<array<int, 2>> dp;

void dfs(int v, int p) {
    for(auto e : tree[v]) {
        if(e != p) dfs(e, v);
    }

    if(tree[v].size() == 1 && v != 1){
        dp[v] = {1, 1};
    }
    else{
        dp[v][0] = 1;

        for(auto e : tree[v]) {
            if(e != p) {
                dp[v][0] = mult(dp[v][0], add(dp[e][0], dp[e][1]));
            }
        }

        vector<int> prefix(tree[v].size(), 1), suffix(tree[v].size(), 1);

        for(int i = 0; i < tree[v].size(); i++) {
            if(i != 0) prefix[i] = prefix[i - 1];

            if(tree[v][i] != p) {
                prefix[i] = mult(prefix[i], add(dp[tree[v][i]][0], dp[tree[v][i]][1]));
            }
        }

        for(int i = (int)tree[v].size() - 1; i >= 0; i--) {
            if(i != (int)tree[v].size() - 1) suffix[i] = suffix[i + 1];

            if(tree[v][i] != p) {
                suffix[i] = mult(suffix[i], add(dp[tree[v][i]][0], dp[tree[v][i]][1]));
            }
        }

        dp[v][1] = 0;

        for(int i = 0; i < tree[v].size(); i++) {
            if(tree[v][i] != p) {
                int a = i == 0 ? 1 : prefix[i - 1];
                int b = i == (int)tree[v].size() - 1 ? 1 : suffix[i + 1];

                dp[v][1] = add(dp[v][1], mult(mult(a, b), dp[tree[v][i]][1]));
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    cin >> n;

    tree.assign(n + 1, {});
    dp.assign(n + 1, array<int, 2>());

    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;

        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1, 0);

    cout << dp[1][0];
}
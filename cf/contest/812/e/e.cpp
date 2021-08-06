/* Author: izhang05
 * Time: 08-04-2021 17:39:49
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("out.txt", "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5, maxa = 1e7 + 5;
vector<int> adj[maxn];
int a[maxn];
long long even_cnt[maxa], odd_cnt[maxa], leaf_depth, total_even, total_odd, even_xor, odd_xor;

void dfs(int c, int p, int d) {
    if (d % 2 == 0) {
        even_xor ^= a[c];
        ++even_cnt[a[c]];
        ++total_even;
    } else {
        odd_xor ^= a[c];
        ++odd_cnt[a[c]];
        ++total_odd;
    }
    bool leaf = true;
    for (auto &i : adj[c]) {
        if (i != p) {
            leaf = false;
            dfs(i, c, d + 1);
        }
    }
    if (leaf) {
        leaf_depth = d % 2;
    }
}

int main() {
    setIO("1");
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        --p;
        adj[p].push_back(i);
        adj[i].push_back(p);
    }
    dfs(0, -1, 0);
    if (leaf_depth == 1) {
        swap(even_cnt, odd_cnt);
        swap(even_xor, odd_xor);
    }
    long long sol = 0;
    if (even_xor == 0) {
        sol += (total_even * (total_even - 1)) / 2;
        sol += (total_odd * (total_odd - 1)) / 2;
    }
    for (int i = 0; i < maxa; ++i) {
        if ((i ^ even_xor) < maxa) {
            sol += even_cnt[i] * odd_cnt[i ^ even_xor];
        }
    }
    cout << sol << "\n";
    return 0;
}

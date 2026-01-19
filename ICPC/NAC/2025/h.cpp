#include <bits/stdc++.h>

using namespace std;

const int mxn = 2e5+5;
typedef long long ll;
vector<int> adj[mxn];
ll val[mxn];
ll k, sol = 0;
bool bad = false;

ll dfs(int c, int p, ll v) {
  ll cons = k;
  if (val[c] != -1) {
    cons -= val[c];
  }
  for (auto u : adj[c]) {
    if (u!=p && val[u] != -1) {
      cons -= val[u];
    }
  }
  if (cons < 0) {
    bad = true;
    return 0;
  }
  for (auto i : adj[c]) {
    if (i != p) {
      bool sub = (val[i] == -1);
      dfs(i, c, cons);
      if (sub) {
        cons -= val[i];
      }
    }
  }
  if (val[c] == -1) {
    val[c] = min(v, cons);
  }
  sol += val[c];
  // cout << c << " " << val[c] << endl;
  return val[c];
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    int n;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
      cin >> val[i];
      }
    for (int i = 0; i < n-1; i++) {
      int u, v;
      cin >> u >> v;
      --u,--v;
      adj[u].push_back(v);
      adj[v].push_back(u);
      }
  dfs(0, -1, k);
  if (bad) {
    cout << -1 << "\n";
  }else {
    cout << sol << "\n";
  }
}
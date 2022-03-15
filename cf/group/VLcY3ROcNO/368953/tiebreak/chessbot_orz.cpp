//misaka will carry me to master
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <cassert>
#include <algorithm>
#include <vector>
#include <functional>
#include <numeric>
#include <set>
#include <map>

#define ll long long
#define lb long double
#define sz(vec) ((int)(vec.size()))
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

const lb eps = 1e-9;
const ll mod = 1e9 + 7, ll_max = 1e18;
//const ll mod = (1 << (23)) * 119 +1;
const int MX = 2e5 +10, int_max = 0x3f3f3f3f;

using namespace std;


int col[MX];
int in[MX], out[MX];
int tour[MX*2], BIT[MX*2];

int super[MX][30], arr[MX];
int par[MX], dep[MX], ans[MX], isq[MX];
int n, q;

vector<int> adj[MX];

void dfs(int u, int p){
	static int ind = 0;
	tour[++ind] = u;
	in[u] = ind;
	par[u] = p;
	dep[u] = dep[p] + 1;
	for(int v : adj[u]){
		if(v != p){
			dfs(v, u);
		}
	}
	tour[++ind] = -u;
	out[u] = ind;
}

vector<pair<int, pair<int, int>>> query[MX];

void precomp(){
	for(int i = 1; i<=n; i++){
		super[i][0] = par[i];
		//cout << i << " " << par[i] << "\n";
	}
	for(int j = 1; (1 << j) <=n; j++){
		for(int i = 1; i<=n; i++){
			super[i][j] = super[super[i][j-1]][j-1];
		}
	}
}

int k_up(int u, int k){
	for(int i = 25; ~i; i--){
		if(k&(1 << i)) u = super[u][i];
	}
	return u;
}

int lca(int a, int b){
	if(dep[a] < dep[b]) swap(a, b);
	a = k_up(a, dep[a] - dep[b]);
	if(a == b) return a;
	for(int i = 25; ~i; i--){
		if(super[a][i] != super[b][i]){
			a = super[a][i];
			b = super[b][i];
		}
	}
	assert(a != b&& par[a] && par[a] == par[b]);
	return par[a];
}

int S(int x){
	return (!x) ? 0 : (BIT[x] + S(x - (x&-x)));
}

void UU(int k, int v){
	for(; k<=n*2+2; k+=k&-k) BIT[k] += v;
}

void U(int u, int v){
	UU(in[u], v);
	UU(out[u], -v);
}

void solve(){
	cin >> n >> q;
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
		col[i] = arr[i];
		query[col[i]].pb(mp(0, mp(i, 1)));
	}
	for(int i = 1; i<n; i++){
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(1, 0);
	precomp();
	for(int i = 1; i<=q; i++){
		int op;
		cin >> op;
		if(op == 1){
			int a, b;
			cin >> a >> b ;
			if(col[a] == b) continue;
			query[col[a]].pb(mp(0, mp(a, -1)));
			query[b].pb(mp(0, mp(a, 1)));
			col[a] = b;
		}else{
			isq[i] = 1;
			int u, v, c;
			cin >> u >> v >> c;
			int l = lca(u, v);
			int p = par[l];
			query[c].pb(mp(-1, mp(i, l)));
			query[c].pb(mp(-1, mp(i, p)));
			query[c].pb(mp(1, mp(i, u)));
			query[c].pb(mp(1, mp(i, v)));
		}
	}
	for(int i = 1; i<=n; i++){
		query[col[i]].pb(mp(0, mp(i, -1)));
	}
	for(int c = 1; c<=1e5; c++){
		for(const auto&e : query[c]){
			if(e.first == 0){
				U(e.second.first, e.second.second);
			}else{
				ans[e.second.first] += e.first * S(in[e.second.second]);
			}
		}
	}
	for(int i = 1; i<=q; i++){
		if(isq[i]) cout << ans[i] << "\n";
	}
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);

  int T = 1;
  //cin >> T;
  while(T--){
		solve();
  }
  return 0;
}
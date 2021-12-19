#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define Foreach(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define rof(i,a,b) for(int (i)=(a);(i) > (b); --(i))
#define rep(i, c) for(auto &(i) : (c))
#define x first
#define y second
#define pb push_back
#define PB pop_back()
#define iOS ios_base::sync_with_stdio(false)
#define sqr(a) (((a) * (a)))
#define all(a) a.begin() , a.end()
#define error(x) cerr << #x << " = " << (x) <<endl
#define Error(a,b) cerr<<"( "<<#a<<" , "<<#b<<" ) = ( "<<(a)<<" , "<<(b)<<" )\n";
#define errop(a) cerr<<#a<<" = ( "<<((a).x)<<" , "<<((a).y)<<" )\n";
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
#define L(x) ((x)<<1)
#define R(x) (((x)<<1)+1)
#define umap unordered_map
#define double long double
typedef long long ll;
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef complex<double> point;
template <typename T> using os =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>  inline void smax(T &x,T y){ x = max((x), (y));}
template <class T>  inline void smin(T &x,T y){ x = min((x), (y));}
const int maxn = 1e5 + 10, maxl = 19;
const ll inf = 1LL << 60;
int st[maxn], ft[maxn], par[maxn][maxl], h[maxn], tim, sz[maxn], fst[maxn], stm[maxn], lst[maxn];
vi adj[maxn];
vi people[maxn];
typedef pair<ll, int> person;
person emp(inf, -1);
ll lz[maxn * 4], seg[maxn * 4];
person mn[maxn * 4];
int n, m, q;
inline void DFS(int v = 0, int p = -1){
	sz[v] = 1;
	rep(u, adj[v])	if(u - p){
		DFS(u, v);
		sz[v] += sz[u];
	}
}
inline void dfs(int v = 0, int p = -1, bool big = false){
	fst[v] = (big? fst[p]: v);
	stm[tim] = v;
	st[v] = tim ++;
	par[v][0] = p;
	if(~p)	h[v] = h[p] + 1;
	For(i,1,maxl)	if(~par[v][i-1])
		par[v][i] = par[par[v][i-1]][i-1];
	int mx = 0, I = -1;
	For(i,0,adj[v].size())	if(adj[v][i] - p && mx < sz[adj[v][i]])
		mx = sz[adj[v][i]], I  = i;
	if(~I)
		rotate(adj[v].begin(), adj[v].begin() + I, adj[v].end());
	For(i,0,adj[v].size())	if(adj[v][i] - p)
		dfs(adj[v][i], v, !i);
	ft[v] = tim;
	smax(lst[fst[v]],  st[v]);
}
inline void addtree(int x, int y, int val, int id = 1, int l = 0, int r = n){
	if(l >= y or x >= r)	return ;
	if(x <= l && r <= y){
		seg[id] += val;
		return ;
	}
	int mid = (l + r)/2;
	addtree(x, y, val, L(id), l, mid);
	addtree(x, y, val, R(id), mid, r);
}
inline ll asktree(int p, int id = 1, int l = 0, int r = n){
	ll ans = seg[id];
	if(r - l < 2)	return ans;
	int mid = (l + r)/2;
	if(p < mid)
		ans += asktree(p, L(id), l, mid);
	else
		ans += asktree(p, R(id), mid, r);
	return ans;
}
inline void upd(int id, ll val){
	lz[id] += val;
	mn[id].x += val;
	smin(mn[id], emp);
}
inline void shift(int id){
	upd(L(id), lz[id]);
	upd(R(id), lz[id]);
	lz[id] = 0;
}
inline void build(int id = 1, int l = 0, int r = n){
	if(r - l < 2){
		mn[id] = emp;
		int v = stm[l];
		if(!people[v].empty())
			mn[id] = {people[v].back() + lz[id], l};
		return ;
	}
	int mid = (l + r)/2;
	build(L(id), l, mid);
	build(R(id), mid, r);
	mn[id] = min(mn[L(id)], mn[R(id)]);
}
inline void add(int x, int y, int val, int id = 1, int l = 0, int r = n){
	if(x >= r or l >= y)	return ;
	if(x <= l && r <= y){
		upd(id, val);
		return ;
	}
	int mid = (l + r)/2;
	shift(id);
	add(x, y, val, L(id), l, mid);
	add(x, y, val, R(id), mid, r);
	mn[id] = min(mn[L(id)], mn[R(id)]);
}
inline void set_element(int p, int id = 1, int l = 0, int r = n){
	if(r - l < 2){
		mn[id] = emp;
		int v = stm[l];
		if(!people[v].empty())
			mn[id] = {people[v].back() + lz[id], l};
		return ;
	}
	int mid = (l + r)/2;
	shift(id);
	if(p < mid)
		set_element(p, L(id), l, mid);
	else
		set_element(p, R(id), mid, r);
	mn[id] = min(mn[L(id)], mn[R(id)]);
}
inline person ask(int x, int y, int id = 1, int l = 0, int r = n){
	if(x >= r or l >= y)	return emp;
	if(x <= l && r <= y)	return mn[id];
	int mid = (l + r)/2;
	shift(id);
	return min(ask(x, y, L(id), l, mid),
			ask(x, y, R(id), mid, r));
}
inline int lca(int v, int u){
	if(h[v] < h[u])	swap(v, u);
	rof(i,maxl-1,-1)	if(~par[v][i] && h[par[v][i]] >= h[u])
		v = par[v][i];
	if(v == u)	return v;
	rof(i,maxl-1,-1)	if(par[v][i] - par[u][i])
		v = par[v][i], u = par[u][i];
	return par[v][0];
}
inline person askchain(int v, int u){// u is ancestor of v
	//assert(fst[v] == fst[u]);
	ll val = asktree(st[fst[u]]);
	person ans = ask(st[u], st[v] + 1);
	ans.x += val;
	smin(ans, emp);
	return ans;
}
inline person hld(int v, int u){// us in ancestor of v
	auto ans = emp;
	while(fst[v] != fst[u]){
		smin(ans, askchain(v, fst[v]));
		v = par[fst[v]][0];
	}
	smin(ans, askchain(v, u));
	return ans;
}
inline int erase(person p){
	if(p.y == -1)	return -1;
	int v = stm[p.y];
	int ans = people[v].back();
	people[v].PB;
	set_element(st[v]);
	return ans;
}
vector<int> anss;
inline bool query(int v, int u, int w){
	person p = min(hld(v, w), hld(u, w));
	if(p.x == inf or p.y == -1)	return false;
	anss.pb(erase(p));
	return true;
}
inline void solve(int v, int u, int k){
	int w = lca(v, u);
	anss.clear();
	For(i,0,k)	if(!query(v, u, w))	break ;
	printf("%d ", (int)anss.size());
	rep(x, anss)	printf("%d ", x);
	puts("");
}
int main(){
	memset(par, -1, sizeof par);
	fill(mn, mn + 4 * maxn, emp);
	scanf("%d %d %d", &n, &m, &q);
	For(i,1,n){
		int v, u;
		scanf("%d %d", &v, &u);
		-- v, -- u;
		adj[v].pb(u), adj[u].pb(v);
	}
	For(i,1,m+1){
		int v;
		scanf("%d", &v);
		-- v;
		people[v].pb(i);
	}
	For(i,0,n)	reverse(all(people[i]));
	DFS();
	dfs();
	build();
	while(q--){
		int type, v, u, k;
		scanf("%d %d", &type, &v);
		if(type == 1){
			scanf("%d %d", &u, &k);
			-- v, -- u;
			solve(v, u, k);
		}
		else{
			scanf("%d", &k);
			-- v;
			addtree(st[v], ft[v], k);
			if(v != fst[v])	add(st[v], lst[fst[v]] + 1, k);
		}
	}
	return 0;
}

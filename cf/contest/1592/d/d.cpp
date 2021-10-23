//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <bitset>		//UWAGA - w czasie kompilacji musi byc znany rozmiar wektora - nie mozna go zmienic
#include <cassert>
#include <iomanip>		//do setprecision
#include <ctime>
#include <complex>
#include <chrono>
#include<unordered_map>
#include <random>
using namespace std;

#define FOR(i,b,e) for(int i=(b);i<(e);++i)
#define FORQ(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b)-1;i>=(e);--i)
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define ALL(u) (u).begin(),(u).end()

#define ST first
#define ND second
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define LL long long
#define ULL unsigned LL
#define LD long double

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef tuple<int, int, int> TIII;
typedef vector<int> VI;

const double pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342;

void fast_io() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

const int MR = 1e3 + 10;

vector<int> g[MR];

int best;

int cnt(int nr, int par)
{
	int res = 1;
	for (int i : g[nr])
		if (i != par)
			res += cnt(i, nr);

	return res;
}

vector<int> traverse(int nr, int par)
{
	vector<int> res;
	res.push_back(nr);
	for(int i : g[nr])
		if (i != par)
		{
			auto tmp = traverse(i, nr);
			for (int v : tmp)
				res.push_back(v);
		}

	return res;
}

// above - ile jest wierzcholkow nad nr
void dfs(int nr, int par, int above)
{
	if (par == -1 && (int)g[nr].size() == 1 && cnt(g[nr].front(), nr) == 1)
	{
		// mamy odpowiedz
		printf("! %d %d\n", nr + 1, g[nr].front() + 1);
		fflush(stdout);
		return;
	}

	map<int, int> children;
	int sumChildren = 0;
	int mxChild = -1;
	for (int i : g[nr])
		if (i != par)
		{
			int tmp = cnt(i, nr);
			children[i] = tmp;
			sumChildren += tmp;
			if (tmp > children[mxChild])
				mxChild = i;
		}

	int total = 1 + above + sumChildren;
	if (children[mxChild] > total / 2)
	{
		dfs(mxChild, nr, total - children[mxChild]);
		return;
	}

	int h1 = 0, h2 = total;
	int diff = abs(h1-h2);
	vector<int> cut;
	for (int i : g[nr])
		if (i != par)
		{
			if (abs((h2 - children[i]) - (children[i] + h1 + 1)) < diff)
			{
				h1 += children[i];
				h2 -= children[i];
				cut.push_back(i);
				diff = abs(h2 - (h1 + 1));
			}
			else
				break;
		}

	vector<int> query;
	query.push_back(nr);
	for (int i : cut)
	{
		auto tmp = traverse(i, nr);
		for (int v : tmp)
			query.push_back(v);
	}

	printf("? %d ", query.size());
	for (int q : query)
		printf("%d ", q + 1);
	printf("\n");
	fflush(stdout);

	int ans;
	scanf("%d", &ans);

	if (ans == best)
	{
		// odpalaj sie ponownie na obcietym drzewie
		g[nr] = cut;
		dfs(nr, -1, 0);
		return;
	}

	// odpowiedz jest w pozostalej czesci drzewa, musisz wyrzucic cut
	vector<int> left;
	for (int i : g[nr])
		if (find(cut.begin(), cut.end(), i) == cut.end())
			left.push_back(i);

	g[nr] = left;
	dfs(nr, -1, 0);
}

int main()
{
	// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	// int ind = uniform_int_distribution<int>(l,r)(rng);
	fast_io();

	int n;
	scanf("%d", &n);
	REP(i, n - 1)
	{
		int u, v;
		scanf("%d%d", &u, &v); u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	printf("? %d ", n);
	REP(i, n)
		printf("%d ", i + 1);
	printf("\n");
	fflush(stdout);
	scanf("%d", &best);

	dfs(0, -1, 0);

	return 0;
}

///* Author: izhang05
// * Time: 10-03-2021 10:35:04
//**/
//#include <bits/stdc++.h>
//
//using namespace std;
//
////#define DEBUG
//void setIO(const string &name) {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cin.exceptions(istream::failbit);
//#ifdef LOCAL
//    freopen(("in" + name + ".txt").c_str(), "r", stdin);
//    freopen("out.txt", "w", stdout);
//    freopen("out.txt", "w", stderr);
//#endif
//}
//const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e3 + 5;
//const long long INFL = 0x3f3f3f3f3f3f3f3f;
//vector<int> adj[maxn];
//
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//
//int guess(vector<int> &v) {
//    cout << "? " << v.size();
//    for (auto &i : v) {
//        cout << " " << i + 1;
//    }
//    cout << endl;
//    int res;
//    cin >> res;
//    return res;
//}
//
//long long sol;
//int sub[maxn];
//bool visited[maxn];
//vector<int> nodes;
//
//int find_size(int v, int p) {
//    sub[v] = 1;
//    for (auto &i : adj[v]) {
//        if (i != p && !visited[i]) {
//            sub[v] += find_size(i, v);
//        }
//    }
//    return sub[v];
//}
//
//int centroid(int v, int p, int s) {
//    for (auto &i : adj[v]) {
//        if (i != p && !visited[i] && sub[i] > s / 2) {
//            return centroid(i, v, s);
//        }
//    }
//    return v;
//}
//
//void dfs(int c, int p) {
//    nodes.push_back(c);
//    for (auto &i : adj[c]) {
//        if (i != p && !visited[i]) {
//            dfs(i, c);
//        }
//    }
//}
//
//struct state {
//    int ind, sz;
//    vector<int> nodes;
//};
//int val, cnt;
//
//void solve(int v) {
//    find_size(v, -1);
//    int c = centroid(v, -1, sub[v]);
//    if (cnt == 2) {
//        for (auto &i : adj[c]) {
//            if (!visited[i]) {
//                cout << "! " << c + 1 << " " << i + 1;
//                return;
//            }
//        }
//    }
//    vector<state> s;
//    for (auto &i : adj[c]) {
//        if (!visited[i]) {
//            nodes.clear();
//            dfs(i, c);
//            s.push_back({i, (int) nodes.size(), nodes});
//        }
//    }
////    shuffle(s.begin(), s.end(), rng);
//    sort(s.begin(), s.end(), [](auto left, auto right) {
//        return left.sz > right.sz;
//    });
//    vector<int> a, b;
//    int a_sz = 0, b_sz = 0;
//    for (auto &i : s) {
//        if (a_sz <= b_sz) {
//            a_sz += i.sz;
//            for (auto &j : i.nodes) {
//                a.push_back(j);
//            }
//        } else {
//            b_sz += i.sz;
//            for (auto &j : i.nodes) {
//                b.push_back(j);
//            }
//        }
//    }
//    a.push_back(c);
//    if (guess(a) == val) {
//        for (auto &i : b) {
//            visited[i] = true;
//            --cnt;
//        }
//    } else {
//        a.pop_back();
//        for (auto &i : a) {
//            visited[i] = true;
//            --cnt;
//        }
//    }
//    solve(c);
//}
//
//void solve() {
//    int n;
//    cin >> n;
//    cnt = n;
//    for (int i = 0; i < n - 1; ++i) {
//        int a, b;
//        cin >> a >> b;
//        --a, --b;
//        adj[a].push_back(b);
//        adj[b].push_back(a);
//    }
//    vector<int> nums(n);
//    for (int i = 0; i < n; ++i) {
//        nums[i] = i;
//    }
//    val = guess(nums);
//    solve(0);
//}
//
//int main() {
//    setIO("1");
//
//    int t = 1;
//    while (t--) {
//        solve();
//    }
//    return 0;
//}

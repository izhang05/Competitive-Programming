#include<bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b);++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi val, comp, z, cont;
int Time, ncomps;

template<class G, class F>
int dfs(int j, G &g, F &f) {
    int low = val[j] = ++Time, x;
    z.push_back(j);
    for (auto e: g[j])
        if (comp[e] < 0)
            low = min(low, val[e] ?: dfs(e, g, f));
    if (low == val[j]) {
        do {
            x = z.back();
            z.pop_back();
            comp[x] = ncomps;
            cont.push_back(x);
        } while (x != j);
        f(cont);
        cont.clear();
        ncomps++;
    }
    return val[j] = low;
}

template<class G, class F>
void scc(G &g, F f) {
    int n = sz(g);
    val.assign(n, 0);
    comp.assign(n, -1);
    Time = ncomps = 0;
    rep(i, 0, n) if (comp[i] < 0) dfs(i, g, f);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, m;
    cin >> n >> m;
    vector<long double> suc(n);
    for (int i = 0; i < n; ++i) {
        long double cur;
        cin >> cur;
        suc[i] = log10(1 - cur);
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[b].push_back(a);
    }
    scc(adj, [&](vi &v) {});
    vector<long double> comp_suc(ncomps);
    vector<int> in_deg(ncomps);
    for (int i = 0; i < n; ++i) {
        comp_suc[comp[i]] += suc[i];
        for (auto &j: adj[i]) {
            if (comp[i] != comp[j]) {
                ++in_deg[comp[j]];
            }
        }
    }
    long double sol = -1e100;
//    for (auto &i: comp_suc) {
//        cout << i << "\n";
//    }
//    cout << "\n";
//
//    for (auto &i: in_deg) {
//        cout << i << "\n";
//    }
//    cout << "\n";

    for (int i = 0; i < ncomps; ++i) {
        if (in_deg[i] == 0) {
            sol = max(sol, comp_suc[i]);
        }
    }
//    cout << sol << "\n";
    int ex = floor(sol);
    long double beg = sol - ex;
    cout << fixed << setprecision(18) <<  pow(10, beg) << "e" << ex << "\n";
}

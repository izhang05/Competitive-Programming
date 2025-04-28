#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i =a; i < (b);++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
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
    z.clear();
    cont.clear();
    val.assign(n, 0);
    comp.assign(n, -1);
    Time = ncomps = 0;
    rep(i, 0, n) if (comp[i] < 0) dfs(i, g, f);
}

const int mxn = 4e5 + 5;
vector<int> weak[mxn], strict[mxn];
int dp[mxn];

vector<pii> adj[mxn];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m, n;
    cin >> m >> n;
    int cur_ind = 0;
    map<string, int> ind;
    for (int i = 0; i < m; ++i) {
        string a, b;
        cin >> a >> b;
        if (ind.find(a) == ind.end()) {
            ind[a] = cur_ind++;
        }
        if (ind.find(b) == ind.end()) {
            ind[b] = cur_ind++;
        }
        weak[ind[a]].push_back(ind[b]);
//        cout << ind[a] << " " << ind[b] << "\n";
    }
    for (int i = 0; i < n; ++i) {
        string a, b;
        cin >> a >> b;
        if (ind.find(a) == ind.end()) {
            ind[a] = cur_ind++;
        }
        if (ind.find(b) == ind.end()) {
            ind[b] = cur_ind++;
        }
        strict[ind[a]].push_back(ind[b]);
    }
//    for (auto &i: ind) {
//        cout << i.first << " " << i.second << "\n";
//    }

    vector<vector<int>> weak_v(cur_ind);
    for (int i = 0; i < cur_ind; ++i) {
        weak_v[i] = weak[i];
    }
//    for (int i = 0; i < cur_ind; ++i) {
//        cout << i << ": ";
//        for (auto &j: weak_v[i]) {
//            cout << j << " ";
//        }
//        cout << "\n";
//    }


    scc(weak_v, [&](vi &v) {});
    for (int i = 0; i < cur_ind; ++i) {
        for (auto &j: strict[i]) {
            weak_v[i].push_back(j);
        }
    }
    int sol_a = ncomps;
    scc(weak_v, [&](vi &v) {});

    for (int i = 0; i < cur_ind; ++i) {
        dp[i] = 1;
//        cout << i << " " << comp[i] << "\n";
    }
    for (int i = 0; i < cur_ind; ++i) {
        for (auto &j: weak[i]) {
            adj[comp[i]].emplace_back(comp[j], 0);
        }
        for (auto &j: strict[i]) {
            adj[comp[i]].emplace_back(comp[j], 1);
        }
    }
    int mx = 1;
    for (int i = 0; i < cur_ind; ++i) {
        for (auto &j: adj[i]) {
            dp[i] = max(dp[i], dp[j.first] + j.second);
        }
        mx = max(mx, dp[i]);
//        cout << i << " " << dp[i] << "\n";
    }
    cout << mx << " " << sol_a << "\n";
}

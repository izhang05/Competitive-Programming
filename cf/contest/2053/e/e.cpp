/* Author: izhang
 * Time: 12-28-2024 10:43:20
**/
#include <bits/stdc++.h>

using namespace std;

#if defined LOCAL || defined DEBUG
#include <debug.h>
#else

struct dbg {
    template<class c>
    dbg &operator<<(const c &) { return *this; }
};

#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#endif

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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 2e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

vector<int> adj[mxn];
int deg[mxn], down[mxn], tot, par[mxn];
long long sol;
bool leaf[mxn], n_leaf[mxn];

int dfs1(int c, int p) {
    par[c] = p;
    if (!leaf[c] && !n_leaf[c]) {
        down[c] = 1;
        ++tot;
    }
    for (auto &i: adj[c]) {
        if (i != p) {
            down[c] += dfs1(i, c);
        }
    }
    return down[c];
}

void dfs2(int c, int p) {
    for (auto &i: adj[c]) {
        if (i != p) {
            dfs2(i, c);
            if (!leaf[c] && n_leaf[i]) {
                sol += down[i];
            }
        }
    }
    if (!leaf[c] && par[c] != -1 && n_leaf[par[c]]) {
        sol += tot - down[c];
    }
}


void test_case() {
    int n;
    cin >> n;
    tot = 0;
    for (int i = 0; i < n; ++i) {
        adj[i].clear();
        deg[i] = 0;
        down[i] = 0;
        sol = 0;
        leaf[i] = n_leaf[i] = false;
    }
    for (int i = 0; i < n - 1; ++i) {
        int node1, node2;
        cin >> node1 >> node2;
        --node1, --node2;
        ++deg[node1], ++deg[node2];
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }
    long long num_leaf = 0;
    for (int i = 0; i < n; ++i) {
        if (deg[i] == 1) {
            leaf[i] = true;
            ++num_leaf;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (auto &j: adj[i]) {
            if (leaf[j]) {
                n_leaf[i] = true;
            }
        }
    }
    sol = num_leaf * (n - num_leaf);
    dfs1(0, -1);
    dfs2(0, -1);

    cout << sol << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}

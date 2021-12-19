/* Author: izhang05
 * Time: 12-16-2021 18:08:46
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e6 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

int n;
vector<int> adj[maxn], radj[maxn];
bool leaf[maxn];
int comp[maxn];
bool vis[maxn];
vector<int> todo, components;
set<int> adj_comp[maxn];

void dfs1(int c) {
    vis[c] = true;
    for (auto &i : adj[c]) {
        if (!vis[i]) {
            dfs1(i);
        }
    }
    todo.push_back(c);
}
void dfs2(int c, int v) {
    comp[c] = v;
    for (auto &i : radj[c]) {
        if (comp[i] == -1) {
            dfs2(i, v);
        }
    }
}

void gen() {
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            dfs1(i);
        }
    }
    reverse(todo.begin(), todo.end());
    for (auto &i : todo) {
        if (comp[i] == -1) {
            dfs2(i, i);
            components.push_back(i);
        }
    }
}

void ae(int a, int b) {
    adj[a].push_back(b);
    radj[b].push_back(a);
}

void test_case() {
    int m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        adj[i].clear();
        radj[i].clear();
        vis[i] = false;
        comp[i] = -1;
        todo.clear();
        components.clear();
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        radj[b].push_back(a);
    }
    gen();
    if (components.size() == 1) {
        cout << "No\n";
        return;
    }
    for (auto &i : components) {
        leaf[i] = true;
    }
    for (int i = 0; i < n; ++i) {
        for (auto &j : adj[i]) {
            if (comp[j] != comp[i]) {
                leaf[comp[i]] = false;
            }
        }
    }
    vector<int> sol;
    for (auto &i : components) {
        if (leaf[i]) {
            for (int j = 0; j < n; ++j) {
                if (comp[j] == i) {
                    sol.push_back(j + 1);
                }
            }
            break;
        }
    }
    cout << "Yes"
         << "\n";
    cout << sol.size() << " " << n - sol.size() << "\n";
    vector<int> cats;
    int j = 0;
    for (int i = 1; i <= n; ++i) {
        if (j == sol.size() || sol[j] != i) {
            cats.push_back(i);
        } else {
            ++j;
        }
    }
    for (auto &i : sol) {
        cout << i << " ";
    }
    cout << "\n";
    for (auto &i : cats) {
        cout << i << " ";
    }
    cout << "\n";
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

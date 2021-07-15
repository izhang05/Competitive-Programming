/* Author: izhang05
 * Time: 07-15-2021 16:16:56
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;

int n;
vector<int> adj[maxn], radj[maxn];
int comp[maxn];
bool vis[maxn];
vector<int> todo, components;
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
    memset(comp, -1, sizeof(comp));
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

vector<int> graph[maxn];
queue<int> st[maxn], en[maxn];
int in_deg[maxn], weak_comp[maxn], out_deg[maxn];
void dfs3(int c, int v) {
    vis[c] = true;
    weak_comp[c] = v;
    for (auto &i : adj[c]) {
        if (!vis[i]) {
            dfs3(i, v);
        }
    }
    for (auto &i : radj[c]) {
        if (!vis[i]) {
            dfs3(i, v);
        }
    }
}

queue<int> fin_st, fin_en;

int main() {
    setIO("4");
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        --a;
        adj[i].push_back(a);
        radj[a].push_back(i);
    }
    gen();
    memset(vis, false, sizeof(vis));
    vector<int> weak;
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            weak.push_back(i);
            dfs3(i, i);
        }
    }
    for (int i = 0; i < n; ++i) {
#ifdef DEBUG
        cout << i << " " << comp[i] << "\n";
#endif
        for (auto &j : adj[i]) {
            if (comp[i] != comp[j]) {
                graph[comp[i]].push_back(comp[j]);
                ++in_deg[comp[j]];
                ++out_deg[comp[i]];
            }
        }
    }
    set<pair<int, int>> sol;
    for (int i = 0; i < n; ++i) {
        if (comp[i] == i) {
            if (in_deg[i] == 0) {
#ifdef DEBUG
                cout << "st: " << i << " " << weak_comp[i] << "\n";
#endif
                st[weak_comp[i]].push(i);
            }
            if (out_deg[i] == 0) {
#ifdef DEBUG
                cout << "en: " << i << " " << weak_comp[i] << "\n";
#endif
                en[weak_comp[i]].push(i);
            }
        }
    }
    int last_st, last_en;
    for (int i = 0; i < int(weak.size()); ++i) {
        sol.insert({en[weak[i]].front(), st[weak[(i + 1) % weak.size()]].front()});
        last_en = en[weak[i]].front(), last_st = st[weak[(i + 1) % weak.size()]].front();
        en[weak[i]].pop();
        st[weak[(i + 1) % weak.size()]].pop();
        while (!en[weak[i]].empty()) {
            fin_en.push(en[weak[i]].front());
            en[weak[i]].pop();
        }
        while (!st[weak[(i + 1) % weak.size()]].empty()) {
            fin_st.push(st[weak[(i + 1) % weak.size()]].front());
            st[weak[(i + 1) % weak.size()]].pop();
        }
    }
    if (fin_st.empty()) {
        fin_st.push(last_st);
    }
    if (fin_en.empty()) {
        fin_en.push(last_en);
    }
    while (fin_en.size() > 1) {
        int j = fin_en.front();
        fin_en.pop();
        sol.insert({j, fin_st.front()});
        if (fin_st.size() > 1) {
            fin_st.pop();
        }
    }
    while (!fin_st.empty()) {
        int j = fin_st.front();
        fin_st.pop();
        sol.insert({fin_en.front(), j});
    }
    vector<pair<int, int>> fin;
    for (auto &i : sol) {
        if (i.first != i.second) {
            fin.emplace_back(i.first, i.second);
        }
    }

    cout << fin.size() << "\n";
    for (auto &i : fin) {
        cout << i.first + 1 << " " << i.second + 1 << "\n";
    }

    return 0;
}

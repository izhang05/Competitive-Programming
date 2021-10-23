/* Author: izhang05
 * Time: 09-08-2021 20:25:48
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
/* Output */
template<typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p);
template<typename A>
ostream &operator<<(ostream &os, const set<A> &m) {
    os << "{";
    string sep = "";
    for (auto e : m) os << sep << e, sep = ", ";
    return os << "}";
}
template<typename A>
ostream &operator<<(ostream &os, const multiset<A> &m) {
    os << "{";
    string sep = "";
    for (auto e : m) os << sep << e, sep = ", ";
    return os << "}";
}
template<typename A, typename B>
ostream &operator<<(ostream &os, const map<A, B> &m) {
    os << "{";
    string sep = "";
    for (auto e : m) os << sep << e.first << ": " << e.second, sep = ", ";
    return os << "}";
}
template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    os << "[";
    string sep = "";
    for (auto e : v) os << sep << e, sep = ", ";
    return os << "]";
}
template<typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
    os << '(' << p.first << ", " << p.second << ')';
    return os;
}

template<class T>
void write(T x) { cout << x; }
template<class H, class... T>
void write(const H &h, const T &...t) {
    write(h);
    write(t...);
}

void print() { write('\n'); }
template<class H, class... T>
void print(const H &h, const T &...t) {
    write(h);
    if (sizeof...(t)) write(' ');
    print(t...);
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 5e3 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
int n;
vector<int> adj[maxn], radj[maxn];
set<int> adj2[maxn];
int comp[maxn], in_deg[maxn];
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

void ae(int a, int b) {
    adj[a].push_back(b);
    radj[b].push_back(a);
}

void solve() {
    int m, s;
    cin >> n >> m >> s;
    --s;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        ae(a, b);
    }
    gen();
    for (int i = 0; i < n; ++i) {
        for (auto &j : adj[i]) {
            if (comp[i] != comp[j]) {
                adj2[comp[i]].insert(comp[j]);
            }
        }
    }
    for (auto &i : components) {
        for (auto &j : adj2[i]) {
            ++in_deg[j];
        }
    }
    int sol = 0;
    for (auto &i : components) {
        if (!in_deg[i] && i != comp[s]) {
            ++sol;
        }
    }
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

#if defined LOCAL || DEBUG
#include <debug.h>
#include <ostream>
#else
struct dbg {
    template<class c>
    dbg &operator<<(const c &) { return *this; }
};
#endif

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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
vector<int> adj[maxn];
bool s[maxn];
int cost, root = -1;
priority_queue<int> chains;

bool prune(int cur, int p) {
    vector<int> n_adj;
    if (p != -1) {
        n_adj.push_back(p);
    }
    for (auto &i : adj[cur]) {
        if (i != p) {
            if (!prune(i, cur)) {
                n_adj.push_back(i);
            } else {
                --cost;
            }
        }
    }
    swap(adj[cur], n_adj);
    if (!s[cur] && adj[cur].size() == 1) {
        return true;
    }
    return false;
}

int cnt_special = 0;

void dfs(int cur, int p, int chain) {
    if (s[cur] || adj[cur].size() > 2) {
        chains.push(chain - 1);
        chain = 0;
        ++cnt_special;
    } else {
    }
    for (auto &i : adj[cur]) {
        if (i != p) {
            dfs(i, cur, chain + 1);
        }
    }
}

struct line {
    long long m, b;
    long long eval(long long x) const {
        return m * x + b;
    }
    long double intx(line l) {
        return (long double) (b - l.b) / (l.m - m);
    }
    friend ostream &operator<<(ostream &os, const line &line) {
        os << "m: " << line.m << " b: " << line.b;
        return os;
    }
};

int main() {
    setIO("1");
    int n;
    cin >> n;
    string tmp;
    cin >> tmp;
    for (int i = 0; i < n; ++i) {
        if (tmp[i] == '1') {
            s[i] = true;
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cost = n;
    for (int i = 0; i < n; ++i) {
        if (s[i]) {
            prune(i, -1);
            break;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (s[i] && adj[i].size() == 1) {
            root = i;
            break;
        }
    }
    assert(root != -1);
    dfs(root, -1, 1);

    //    assert(cnt_special < 1e4);
    vector<int> c(n); // c[i] = min size with exactly i + 1 components
    if (cnt_special > 5e4) {
        for (int i = 0; i < n; ++i) {
            c[i] = cost;
            if (!chains.empty()) {
                cost -= chains.top();
                chains.pop();
            }
        }
    } else {
    }
    dbg() << c;

    vector<line> cht;
    cht.push_back({0, INFL});
    for (int i = 0; i < n; ++i) {
        line cur = {i + 1, c[i]};
        int m = cht.size();
        while (m >= 2 && cur.intx(cht[m - 1]) >= cht[m - 1].intx(cht[m - 2])) {
            cht.pop_back();
            --m;
        }
        cht.push_back(cur);
    }
    dbg() << cht;
    for (int i = 1; i <= n; ++i) {
        int m = cht.size();
        while (m >= 2 && cht[m - 1].eval(i) >= cht[m - 2].eval(i)) {
            cht.pop_back();
            --m;
        }
        cout << cht[m - 1].eval(i) << "\n";
    }
    return 0;
}

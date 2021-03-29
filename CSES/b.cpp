#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
//#define DEBUG
void setIO(string name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}
template<class T>
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5;
vector<pair<int, int>> adj[maxn];
int down[maxn], up[maxn];

void dfs1(int c, int p) {
    for (auto i : adj[c]) {
        if (i.first != p) {
            down[c] += i.second;
            dfs1(i.first, c);
            down[c] += down[i.first];
        }
    }
}

void dfs2(int c, int p, int cost) {
    if (c != 0) {
        up[c] = up[p] + down[p] - down[c];
        if (cost == 1) {
            --up[c];
        } else {
            ++up[c];
        }
    }
    for (auto i : adj[c]) {
        if (i.first != p) {
            dfs2(i.first, c, i.second);
        }
    }
}

int main() {
    setIO("b");
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].emplace_back(b, 0);
        adj[b].emplace_back(a, 1);
    }
    dfs1(0, -1);
    dfs2(0, -1, 0);
#ifdef DEBUG
    cout << "down:"
         << "\n";
    for (int i = 0; i < n; ++i) {
        cout << down[i] << " ";
    }
    cout << "\n";
    cout << "up:"
         << "\n";
    for (int i = 0; i < n; ++i) {
        cout << up[i] << " ";
    }
    cout << "\n";
#endif
    pair<int, set<int>> sol;
    sol.first = inf;
    for (int i = 0; i < n; ++i) {
        int cur = down[i] + up[i];
        if (cur == sol.first) {
            sol.second.insert(i + 1);
        } else if (cur < sol.first) {
            sol.first = cur;
            sol.second = set<int>{i + 1};
        }
    }
    cout << sol.first << "\n";
    print(sol.second);
    return 0;
}

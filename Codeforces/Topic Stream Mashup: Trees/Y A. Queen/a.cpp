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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;
vector<int> sol;
vector<pair<int, int>> adj[maxn];

void dfs(int c, int p, int co) {
    bool cur = co;
    for (auto i : adj[c]) {
        if (p != i.first) {
            dfs(i.first, c, i.second);
            cur &= i.second;
        }
    }
    if (cur) {
        sol.push_back(c + 1);
    }
}

int main() {
    setIO("1");

    int n;
    cin >> n;
    int root;
    for (int i = 0; i < n; ++i) {
        int b, c;
        cin >> b >> c;
        --b;
        if (b >= 0) {
            adj[b].emplace_back(i, c);
        } else {
            root = i;
        }
    }
    dfs(root, -1, false);
    sort(sol.begin(), sol.end());
    if (sol.empty()) {
        cout << -1 << "\n";
    } else {
        print(sol);
    }
    return 0;
}

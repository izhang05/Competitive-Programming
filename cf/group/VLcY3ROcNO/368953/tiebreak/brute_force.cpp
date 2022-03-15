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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
vector<int> adj[maxn];
int co[maxn];
int sol = 0, end_p;
void dfs(int c, int p, int color, int cnt) {
    if (co[c] == color) {
        ++cnt;
    }
    if (c == end_p) {
        sol = cnt;
    }
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs(i, c, color, cnt);
        }
    }
}

void test_case() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> co[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int node1, node2;
        cin >> node1 >> node2;
        --node1, --node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int a, b;
            cin >> a >> b;
            --a;
            co[a] = b;
        } else {
            int a, c;
            cin >> a >> end_p >> c;
            --a, --end_p;
            sol = 0;
            dfs(a, -1, c, 0);
            cout << sol << "\n";
        }
    }
}
int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}

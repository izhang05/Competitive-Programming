/* Author: izhang
 * Time: 07-21-2023 22:29:58
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
vector<pair<int, int>> adj[mxn];
long long val[mxn];
bool pos = true;

void dfs(int c) {
    for (auto &i : adj[c]) {
        if (val[i.first] == INFL) {
            val[i.first] = val[c] + i.second;
            dfs(i.first);
        } else if (val[i.first] != val[c] + i.second) {
            pos = false;
        }
    }
}

void test_case() {
    pos = true;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        adj[i].clear();
        val[i] = INFL;
    }
    for (int i = 0; i < m; ++i) {
        int a, b, d;
        cin >> a >> b >> d;
        --a, --b;
        adj[a].emplace_back(b, d);
        adj[b].emplace_back(a, -d);
    }
    for (int i = 0; i < n; ++i) {
        if (val[i] != INFL) {
            continue;
        }
        val[i] = 0;
        dfs(i);
    }
    for (int i = 0; i < n; ++i) {
        dbg() << val[i] << " ";
    }
    cout << (pos ? "YES" : "NO") << "\n";
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

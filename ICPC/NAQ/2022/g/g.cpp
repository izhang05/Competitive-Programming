/* Author: izhang
 * Time: 09-09-2023 03:10:42
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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 1e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
int nxt[mxn], in_deg[mxn];
bool vis[mxn];
vector<int> adj[mxn];
long long dp[mxn];

long long dfs(int c) {
    vis[c] = true;
    long long &cur = dp[c];
    cur = 1;
    for (auto &i: adj[c]) {
        if (!vis[i]) {
            cur *= dfs(i);
            cur %= mod;
        }
    }
    cur = (cur + 1) % mod;
    return cur;
}


void test_case() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> nxt[i];
        --nxt[i];
        ++in_deg[nxt[i]];
        adj[nxt[i]].push_back(i);
    }
    long long sol = 1;
    for (int i = 0; i < n; ++i) {
        if (vis[i] || in_deg[i]) {
            continue;
        }
        int cur = i;
        vector<int> seen{cur};
        vis[cur] = true;
        while (!vis[nxt[cur]]) {
            cur = nxt[cur];
            seen.push_back(cur);
            vis[cur] = true;
        }
        seen.push_back(nxt[cur]);
        reverse(seen.begin(), seen.end());
        while (seen.back() != nxt[cur]) {
            vis[seen.back()] = false;
            seen.pop_back();
        }
        long long cur_sol = 1;
        for (auto &j: seen) {
            for (auto &k: adj[j]) {
                if (!vis[k]) {
                    cur_sol *= dfs(k);
                    cur_sol %= mod;
                }
            }
        }
        sol *= cur_sol + 1;
        sol %= mod;
    }
    // take care of cycles without additional edges
    for (int i = 0; i < n; ++i) {
        if (vis[i]) {
            continue;
        }
        sol *= 2;
        sol %= mod;
        int cur = i;
        vis[cur] = true;
        while (!vis[nxt[cur]]) {
            cur = nxt[cur];
            vis[cur] = true;
        }
    }
    cout << (sol - 1 + mod) % mod << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}

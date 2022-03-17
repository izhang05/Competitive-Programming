/* Author: izhang
 * Time: 03-17-2022 00:00:31
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
bool is_c[maxn];
int c[maxn], cnt[maxn], par[maxn];
vector<int> adj[maxn], child[maxn];

void dfs1(int node, int p) {
    cnt[node] = is_c[node];
    par[node] = p;
    for (auto &i : adj[node]) {
        if (i != p) {
            child[node].push_back(i);
            dfs1(i, node);
            cnt[node] += cnt[i];
        }
    }
}
vector<int> order;
int d;
void dfs2(int node, int p) {
    if (is_c[node]) {
        order.push_back(node);
    }
    for (auto &i : adj[node]) {
        if (i != p) {
            dfs2(i, node);
        }
    }
}

void test_case() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n - 1; ++i) {
        int node1, node2;
        cin >> node1 >> node2;
        --node1, --node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }
    for (int i = 0; i < 2 * k; ++i) {
        cin >> c[i];
        --c[i];
        is_c[c[i]] = true;
    }
    dfs1(0, -1);
    for (int i = 0; i < n; ++i) {
        bool good = true;
        for (auto &j : child[i]) {
            if (cnt[j] > k) {
                good = false;
                break;
            }
        }
        if (2 * k - cnt[i] > k) {
            good = false;
        }
        if (good) {
            cout << 1 << "\n";
            cout << i + 1 << "\n";
            if (is_c[i]) {
                order.push_back(i);
            }
            vector<pair<int, int>> cur;
            for (auto &j : child[i]) {
                cur.emplace_back(cnt[j], j);
            }
            if (par[i] != -1) {
                cur.emplace_back(2 * k - cnt[i], par[i]);
            }
            sort(cur.begin(), cur.end());
            reverse(cur.begin(), cur.end());
            for (auto &j : cur) {
                dfs2(j.second, i);
            }
            for (int j = 0; j < k; ++j) {
                cout << order[j] + 1 << " " << order[j + k] + 1 << " " << i + 1 << "\n";
            }
            return;
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

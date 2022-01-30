/* Author: izhang
 * Time: 01-29-2022 15:38:35
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
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long double PI = acos((long double) -1);
struct chash {                                       /// use most bits rather than just the lowest ones
    const uint64_t C = (long long) (2e18 * PI) + 71; // large odd number
    const int RANDOM = rng();
    long long operator()(long long x) const { /// https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
        return __builtin_bswap64((x ^ RANDOM) * C);
    }
};
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
gp_hash_table<int, null_type, chash> adj[maxn];
int deg[maxn], par[maxn];
vector<pair<int, int>> leafs[maxn];
void dfs1(int c, int p) {
    par[c] = p;
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs1(i, c);
        }
    }
}
pair<int, int> diam;
void dfs2(int c, int p, int d) {
    diam = max(diam, {d, c});
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs2(i, c, d + 1);
        }
    }
}
stack<int> st;
bool found = false;
int len;

int r = -1;
void dfs3(int c, int p) {
    st.push(c);
    if (c == diam.second) {
        len = int(st.size() + 1) / 2;
        while (int(st.size()) > len) {
            st.pop();
        }
        r = st.top();
        found = true;
        return;
    }
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs3(i, c);
            if (found) {
                return;
            }
        }
    }
    st.pop();
}

pair<int, pair<int, int>> mx1, mx2;
void dfs4(int c, int p, int d) {
    if ((int) adj[c].size() == 1 && leafs[c].size() >= 2) {
        if (d == len) {
            mx1 = max(mx1, make_pair(leafs[c][0].first + leafs[c][1].first, make_pair(leafs[c][0].second, leafs[c][1].second)));
        } else if (d == len - 1) {
            mx2 = max(mx2, make_pair(leafs[c][0].first + leafs[c][1].first, make_pair(leafs[c][0].second, leafs[c][1].second)));
        }
    }
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs4(i, c, d + 1);
        }
    }
}

void test_case() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int node1, node2;
        cin >> node1 >> node2;
        --node1, --node2;
        adj[node1].insert(node2);
        adj[node2].insert(node1);
        ++deg[node1], ++deg[node2];
    }
    for (int i = 0; i < n; ++i) {
        if (deg[i] >= 3) {
            dfs1(i, -1);
            r = i;
            break;
        }
    }
    if (r == -1) {
        vector<int> l;
        for (int i = 0; i < n; ++i) {
            if (deg[i] == 1) {
                l.push_back(i);
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << l[0] + 1 << " " << *adj[l[0]].begin() + 1 << "\n";
            for (auto &j : adj[*adj[l[0]].begin()]) {
                if (j != l[0]) {
                    cout << j + 1 << " " << l[1] + 1 << "\n";
                    return;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (deg[i] == 1) {
            int cur = i, cnt = 0;
            while (deg[cur] <= 2) {
                adj[cur].erase(par[cur]);
                adj[par[cur]].erase(cur);
                ++cnt;
                cur = par[cur];
            }
            leafs[cur].emplace_back(cnt, i);
        }
    }
    for (int i = 0; i < n; ++i) {
        sort(leafs[i].begin(), leafs[i].end());
        reverse(leafs[i].begin(), leafs[i].end());
    }
    dfs2(r, -1, 0);
    int a = diam.second;
    diam = {0, 0};
    dfs2(a, -1, 0);
    diam.first = a;
    dfs3(diam.first, -1);
    vector<pair<pair<int, pair<int, int>>, int>> res1, res2;
    if ((r == diam.first || r == diam.second) && leafs[r].size() >= 2) {
        res2.emplace_back(make_pair(leafs[r][0].first + leafs[r][1].first, make_pair(leafs[r][0].second, leafs[r][1].second)), r);
    }
    for (auto &i : adj[r]) {
        mx1 = mx2 = {0, {0, 0}};
        dfs4(i, r, 1);
        if (mx1 != make_pair(0, make_pair(0, 0))) {
            res1.emplace_back(mx1, i);
        }
        if (mx2 != make_pair(0, make_pair(0, 0))) {
            res2.emplace_back(mx2, i);
        }
    }
    sort(res1.begin(), res1.end());
    reverse(res1.begin(), res1.end());
    sort(res2.begin(), res2.end());
    reverse(res2.begin(), res2.end());
    if (int(res1.size()) >= 2) {
        cout << res1[0].first.second.first + 1 << " " << res1[1].first.second.first + 1 << "\n";
        cout << res1[0].first.second.second + 1 << " " << res1[1].first.second.second + 1 << "\n";
    } else if (res1.size() == 1) {
        if (res1[0].second != res2[0].second) {
            cout << res1[0].first.second.first + 1 << " " << res2[0].first.second.first + 1 << "\n";
            cout << res1[0].first.second.second + 1 << " " << res2[0].first.second.second + 1 << "\n";
        } else {
            cout << res1[0].first.second.first + 1 << " " << res2[1].first.second.first + 1 << "\n";
            cout << res1[0].first.second.second + 1 << " " << res2[1].first.second.second + 1 << "\n";
        }
    } else {
        cout << res2[0].first.second.first + 1 << " " << res2[1].first.second.first + 1 << "\n";
        cout << res2[0].first.second.second + 1 << " " << res2[1].first.second.second + 1 << "\n";
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

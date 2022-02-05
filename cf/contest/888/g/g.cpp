/* Author: izhang
 * Time: 02-02-2022 09:05:25
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5, maxs = 30;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
int par[maxn], depth[maxn], comps;

int get(int x) {
    return par[x] == x ? x : par[x] = get(par[x]);
}

bool merge(int x, int y) {
    int xroot = get(x), yroot = get(y);
    if (depth[xroot] > depth[yroot]) {
        swap(xroot, yroot);
    }
    if (xroot != yroot) {
        par[xroot] = yroot;
        depth[yroot] = max(depth[yroot], depth[xroot] + 1);
        --comps;
        if (xroot and yroot) {
            return true;
        }
        return true;
    }
    return false;
}

bool same(int x, int y) {
    return get(x) == get(y);
}
struct my_trie {
    int x[(int) 4e6][2]{}, t = 1, cnt[(int) 4e6];
    gp_hash_table<int, set<int>, chash> vals;

    void init() {
        memset(x, -1, sizeof(x));
    }
    void build(vector<int> &s, int ind) {
        int v = 0;
        for (auto &i : s) {
            if (x[v][i] == -1) {
                v = x[v][i] = t++;
            } else {
                v = x[v][i];
            }
            ++cnt[v];
        }
        vals[v].insert(ind);
    }
    void rem(vector<int> &s, int ind) {
        int v = 0;
        for (auto &i : s) {
            v = x[v][i];
            --cnt[v];
        }
        vals[v].erase(ind);
    }
};

void test_case() {
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    my_trie t;
    t.init();
    comps = n;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        vector<int> s(maxs);
        for (int j = 0; j < maxs; ++j) {
            s[maxs - j - 1] = bool(num & (1 << j));
        }
        a[i] = s;
        t.build(s, i);
        par[i] = i;
    }
    long long sol = 0;
    while (comps > 1) {
        vector<vector<int>> cur(n);
        for (int i = 0; i < n; ++i) {
            cur[get(i)].push_back(i);
        }
        vector<pair<int, pair<int, int>>> edges;
        for (auto &i : cur) {
            if (i.empty()) {
                continue;
            }
            for (auto &j : i) {
                t.rem(a[j], j);
            }
            pair<int, pair<int, int>> mn;
            mn.first = inf;
            for (auto &j : i) {
                int v = 0;
                int cost = 0;
                for (int k = 0; k < maxs; ++k) {
                    int &val = a[j][k];
                    if (t.x[v][val] != -1 && t.cnt[t.x[v][val]] > 0) {
                        v = t.x[v][val];
                    } else {
                        v = t.x[v][val ^ 1];
                        cost += 1 << (maxs - k - 1);
                    }
                }
                assert(!t.vals[v].empty());
                mn = min(mn, {cost, {j, *t.vals[v].begin()}});
            }
            edges.push_back(mn);
            for (auto &j : i) {
                t.build(a[j], j);
            }
        }
        sort(edges.begin(), edges.end());
        for (auto &i : edges) {
            if (merge(i.second.first, i.second.second)) {
                sol += i.first;
            }
        }
    }
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}

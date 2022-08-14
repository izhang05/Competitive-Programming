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
set<pair<int, int>> adj[maxn];
int par[maxn], depth[maxn], cnt[maxn];

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
        cnt[yroot] += cnt[xroot];
        return true;
    }
    return false;
}

bool same(int x, int y) {
    return get(x) == get(y);
}


void test_case() {
    int n, m, q;
    cin >> n >> m >> q;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> edges;

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        edges.push({c, {a, b}});
    }
    vector<int> que(q);
    for (int i = 0; i < n; ++i) {
        par[i] = i;
    }
    for (auto &i: que) {
        cin >> i;
        --i;
        ++cnt[i];
    }

    vector<int> sol;
    int good = 0, patience = 0;
    for (int i = q - 1; i >= 0; --i) {
        while (!good && !edges.empty()) {
            pair<int, pair<int, int>> cur = edges.top();
            edges.pop();
            patience = cur.first;
            if (!same(cur.second.first, cur.second.second) && cnt[get(cur.second.first)] > 1 &&
                cnt[get(cur.second.second)] > 1) {
                --good;
            }
            if (merge(cur.second.first, cur.second.second)) {
                if (cnt[get(cur.second.first)] > 1) {
                    ++good;
                }
            }
        }
        if (good) {
            sol.push_back(patience);
        } else {
            sol.push_back(-1);
        }
        if (--cnt[get(que[i])] == 1) {
            --good;
        }
    }
    reverse(sol.begin(), sol.end());
    for (auto &i: sol) {
        cout << i << "\n";
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

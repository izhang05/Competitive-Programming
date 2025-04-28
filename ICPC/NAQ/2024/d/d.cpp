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
int col[mxn], tot[mxn];
vector<pair<int, int>> adj[mxn];
long long sol[mxn];

map<int, long long> dfs(int c, int p, int ind) {
    map<int, long long> cur;
    cur[col[c]] = 1;
    for (auto &i: adj[c]) {
        if (i.first != p) {
            map<int, long long> nxt = dfs(i.first, c, i.second);
            if (cur.size() < nxt.size()) {
                swap(cur, nxt);
            }
            for (auto &j: nxt) {
                cur[j.first] += j.second;
            }
        }
    }
    if (p != -1) {
        for (auto &i: cur) {
            sol[ind] += (long long) i.second * (tot[i.first] - i.second);
        }
    }
    return cur;
}


void test_case() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> col[i];
        ++tot[col[i]];
    }
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].emplace_back(b, i);
        adj[b].emplace_back(a, i);
    }
    dfs(0, -1, -1);

    for (int i = 0; i < n - 1; ++i) {
        cout << sol[i] << "\n";
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

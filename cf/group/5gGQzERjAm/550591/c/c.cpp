/* Author: izhang
 * Time: 09-16-2024 19:17:23
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = (1ll << 18) + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
int par[mxn], val[mxn], depth[mxn];
pair<int, int> children[mxn];

void test_case() {
    int n, m;
    cin >> n >> m;
    vector<int> cur(1 << n);
    for (int i = 0; i < 1 << n; ++i) {
        cin >> val[i];
        cur[i] = i;
    }
    int cur_ind = 1 << n, cur_depth = 1;
    while (int(cur.size()) > 1) {
        vector<int> nxt;
        for (int i = 0; i < int(cur.size()); i += 2) {
            nxt.push_back(cur_ind);
            par[cur[i]] = par[cur[i + 1]] = cur_ind;
            children[cur_ind] = {cur[i], cur[i + 1]};
            depth[cur_ind] = cur_depth;
            if (cur_depth % 2 == 1) {
                val[cur_ind] = val[cur[i]] | val[cur[i + 1]];
            } else {
                val[cur_ind] = val[cur[i]] ^ val[cur[i + 1]];
            }
            ++cur_ind;
        }
        dbg() << cur;
        dbg() << nxt;
        ++cur_depth;
        swap(cur, nxt);
    }
    int root = cur_ind - 1;
    while (m--) {
        int node, v;
        cin >> node >> v;
        --node;
        val[node] = v;
        while (node != root) {
            node = par[node];
            if (depth[node] % 2 == 1) {
                val[node] = val[children[node].first] | val[children[node].second];
            } else {
                val[node] = val[children[node].first] ^ val[children[node].second];
            }
        }
        cout << val[root] << "\n";
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

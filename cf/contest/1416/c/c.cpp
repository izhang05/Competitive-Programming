/* Author: izhang05
 * Time: 10-30-2021 22:41:16
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = (3e5 + 5) * 30, maxs = 30;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

struct trie {
    int x[maxn][2]{}, t = 1;
    vector<int> child[maxn];

    void init() {
        memset(x, -1, sizeof(x));
    }
    void build(const int &s) {
        int v = 0;
        for (int i = 0; i < maxs; ++i) {
            if (x[v][s ^ (1 << i)] == -1) {
                child[v].push_back(t);
                v = x[v][s ^ (1 << i)] = t++;
            } else {
                v = x[v][s ^ (1 << i)];
            }
        }
//        for (auto &i : s) {
//            if (x[v][i - 'a'] == -1) {
//                child[v].push_back(t);
//                v = x[v][i - 'a'] = t++;
//            } else {
//                v = x[v][i - 'a'];
//            }
//        }
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    trie t;
    t.init();
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        t.build(a[i]);
    }

}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        solve();
    }
    return 0;
}

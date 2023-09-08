/* Author: izhang
 * Time: 09-04-2023 19:19:41
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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 105;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
vector<int> adj[mxn];

long long squaks[mxn], new_squaks[mxn];

void test_case() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; ++i) {
        int node1, node2;
        cin >> node1 >> node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }
    squaks[s] = 1;
    for (int i = 0; i < t; ++i) {
        memset(new_squaks, 0, sizeof(new_squaks));
        for (int j = 0; j < n; ++j) {
            for (auto &k: adj[j]) {
                new_squaks[k] += squaks[j];
            }
        }
        swap(squaks, new_squaks);
    }
    long long sol = 0;
    for (int i = 0; i < n; ++i) {
        sol += squaks[i];
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

/* Author: izhang
 * Time: 06-29-2025 16:10:36
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
int deg[mxn];
vector<pair<int, int>> sol;

void dfs(int c, int p, int d) {
    for (auto &i: adj[c]) {
        if (i.first != p) {
            if (d % 2 == 0) {
                sol[i.second] = {i.first, c};
            } else
                sol[i.second] = {c, i.first};
            dfs(i.first, c, d + 1);
        }
    }
}


void test_case() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        adj[i].clear();
        deg[i] = 0;
    }
    sol.clear();
    sol.resize(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        int node1, node2;
        cin >> node1 >> node2;
        --node1, --node2;
        ++deg[node1], ++deg[node2];
        adj[node1].emplace_back(node2, i);
        adj[node2].emplace_back(node1, i);
    }
    if (n == 2) {
        cout << "NO" << "\n";
        return;
    }
    bool found = false;
    for (int i = 0; i < n; ++i) {
        if (deg[i] == 2) {
            int cnt = 0;
            for (auto &j: adj[i]) {
                if (cnt == 0) {
                    sol[j.second] = {i, j.first};
                } else {
                    sol[j.second] = {j.first, i};
                }
                dfs(j.first, i, cnt++);
            }
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "NO" << "\n";
        return;
    }
    cout << "YES" << "\n";
    for (auto &i: sol) {
        cout << i.first + 1 << " " << i.second + 1 << "\n";
    }
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

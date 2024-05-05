/* Author: izhang
 * Time: 05-05-2024 00:19:22
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 2e3 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
vector<int> adj[mxn];
int pre[mxn];
pair<int, int> mx_dist;

void dfs(int c, int p, int d) {
    pre[c] = p;
    mx_dist = max(mx_dist, {d, c});
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs(i, c, d + 1);
        }
    }
}

void test_case() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        adj[i].clear();
    }
    mx_dist = {-1, 0};
    for (int i = 0; i < n - 1; ++i) {
        int node1, node2;
        cin >> node1 >> node2;
        --node1, --node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }
    dfs(0, -1, 0);
    pair<int, int> d_end{mx_dist.second, 0};
    mx_dist.first = -1;
    dfs(mx_dist.second, -1, 0);
    d_end.second = mx_dist.second;
    //    cout << diam.first << " " << diam.second << "\n";
    vector<int> diam;
    int cur = d_end.second;
    while (cur != d_end.first) {
        diam.push_back(cur);
        cur = pre[cur];
    }
    diam.push_back(d_end.first);
    if (diam.size() % 2 == 1) {
        cout << 1 + diam.size() / 2 << "\n";
        for (int i = 0; i < 1 + (int) diam.size() / 2; ++i) {
            cout << diam[diam.size() / 2] + 1 << " " << i << "\n";
        }
    } else if (diam.size() % 4 == 0) {
        cout << diam.size() / 2 << "\n";
        for (int i = 1; i < (int) diam.size() / 2; i += 2) {
            cout << diam[(int) diam.size() / 2 - 1] + 1 << " " << i << "\n";
        }
        for (int i = 1; i < (int) diam.size() / 2; i += 2) {
            cout << diam[(int) diam.size() / 2] + 1 << " " << i << "\n";
        }
    } else {
        cout << 1 + diam.size() / 2 << "\n";
        for (int i = 0; i < 1 + (int) diam.size() / 2; ++i) {
            cout << diam[diam.size() / 2] + 1 << " " << i << "\n";
        }
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

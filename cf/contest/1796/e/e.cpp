/* Author: izhang
 * Time: 08-28-2023 14:30:51
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
vector<int> adj[mxn];
pair<int, int> down[mxn], up[mxn];
pair<array<int, 3>, array<int, 2>> ans[mxn];
int sol = 0;

pair<int, int> dfs1(int c, int p) {
    vector<pair<int, int>> cur;
    for (auto &i : adj[c]) {
        if (i != p) {
            cur.push_back(dfs1(i, c));
        }
    }
    down[c] = {inf, inf};
    if (cur.empty()) {
        down[c] = {inf, 1};
    }
    for (auto &i : cur) {
        down[c].first = min(down[c].first, i.first);
        if (i.second + 1 < down[c].second) {
            down[c].second = i.second + 1;
            down[c].first = min(down[c].first, down[c].second - 1);
        } else {
            down[c].first = min(down[c].first, i.second);
        }
    }
    return down[c];
}

void dfs2(int c, int p) {
    if (p != -1) {
    }
    vector<pair<int, int>> cur{up[c]};
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs2(i, c);
            cur.push_back(down[c]);
        }
    }
    for (auto &i : cur) {
        if (i.first < ans[c].first[0]) {
            ans[c].first[2] = ans[c].first[1];
            ans[c].first[1] = ans[c].first[0];
            ans[c].first[0] = i.first;
        } else if (i.first < ans[c].first[1]) {
            ans[c].first[2] = ans[c].first[1];
            ans[c].first[1] = i.first;
        } else if (i.first < ans[c].first[2]) {
            ans[c].first[2] = i.first;
        }

        if (i.second + 1 < ans[c].second[0]) {
            down[c].second = i.second + 1;
            down[c].first = min(down[c].first, down[c].second - 1);
        } else {
            down[c].first = min(down[c].first, i.second);
        }
    }

}

void test_case() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        adj[i].clear();
        down[i] = up[i] = {};
        ans[i] = {{inf, inf, inf}, {inf, inf}};
    }
    for (int i = 0; i < n - 1; ++i) {
        int node1, node2;
        cin >> node1 >> node2;
        --node1, --node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }
    dfs1(0, -1);
    up[0] = {inf, inf};
    dfs2(0, -1);
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

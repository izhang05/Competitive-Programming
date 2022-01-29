/* Author: izhang
 * Time: 01-28-2022 11:21:11
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

vector<int> adj[maxn];
int k;
bool good;

int dfs(int c, int p) {
    vector<int> cur;
    for (auto &i : adj[c]) {
        if (i != p) {
            cur.push_back(dfs(i, c));
            if (!good) {
                return 0;
            }
        }
    }
    if (!cur.empty()) {
        sort(cur.begin(), cur.end());
        if (cur.back() >= k) {
            good = false;
            return 0;
        }
        if (cur.back() < k - 1) {
            return cur[0] + 1;
        }
        cur.pop_back();
        if (cur.empty() || cur.back() < k - 1) {
            return k;
        } else {
            good = false;
            return 0;
        }
    }
    return 0;
}

void test_case() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        adj[i].clear();
    }
    for (int i = 0; i < n - 1; ++i) {
        int node1, node2;
        cin >> node1 >> node2;
        --node1, --node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }
    int lo = 0, hi = n - 1, res;
    while (lo <= hi) {
        k = (lo + hi) / 2;
        good = true;
        dfs(0, -1);
        if (good) {
            res = k;
            hi = k - 1;
        } else {
            lo = k + 1;
        }
    }
    cout << res << "\n";
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

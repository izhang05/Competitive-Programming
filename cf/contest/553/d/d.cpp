/* Author: izhang
 * Time: 02-21-2022 01:12:37
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
vector<int> adj[maxn];
bool f[maxn];
long double good[maxn];

void test_case() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < k; ++i) {
        int a;
        cin >> a;
        --a;
        f[a] = true;
    }
    for (int i = 0; i < m; ++i) {
        int node1, node2;
        cin >> node1 >> node2;
        --node1, --node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }
    set<pair<long double, int>> rat;
    set<int> nums;
    for (int i = 0; i < n; ++i) {
        if (f[i]) {
            continue;
        }
        nums.insert(i);
        good[i] = adj[i].size();
        for (auto &j : adj[i]) {
            good[i] -= f[j];
        }
        rat.insert({good[i] / adj[i].size(), i});
    }
    long double mx = rat.begin()->first;
    set<int> sol(nums.begin(), nums.end());
    set<int> erased;
    while (!rat.empty()) {
        if (rat.begin()->first > mx) {
            mx = rat.begin()->first;
            for (auto &i : erased) {
                sol.erase(i);
            }
            erased.clear();
        } else {
            int cur = rat.begin()->second;
            nums.erase(cur);
            erased.insert(cur);
            rat.erase(rat.begin());
            for (auto &i : adj[cur]) {
                if (nums.find(i) != nums.end()) {
                    rat.erase({good[i] / adj[i].size(), i});
                    --good[i];
                    rat.insert({good[i] / adj[i].size(), i});
                }
            }
        }
    }
    cout << sol.size() << "\n";
    for (auto &i : sol) {
        cout << i + 1 << " ";
    }
    cout << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}

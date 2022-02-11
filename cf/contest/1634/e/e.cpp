/* Author: izhang
 * Time: 02-06-2022 09:35:02
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

namespace kactl {
#define rep(i, from, to) for (int(i) = from; (i) < (to); ++(i))
#define all(x) x.begin(), (x).end()
#define sz(x) (int) (x).size()
    typedef long long ll;
    typedef pair<int, int> pii;
    typedef vector<int> vi;

    /**
     * Author: Simon Lindholm
     * Date: 2019-12-31
     * License: CC0
     * Source: folklore
     * Description: Eulerian undirected/directed path/cycle algorithm.
     * Input should be a vector of (dest, global edge index), where
     * for undirected graphs, forward/backward edges have the same index.
     * Returns a list of nodes in the Eulerian path/cycle with src at both start and end, or
     * empty list if no cycle/path exists.
     * To get edge indices back, add .second to s and ret.
     * Time: O(V + E)
     * Status: stress-tested
     */

    vi eulerWalk(vector<vector<pii>> &gr, int nedges, int src = 0) {
        int n = sz(gr);
        vi D(n), its(n), eu(nedges), ret, s = {src};
        D[src]++; // to allow Euler paths, not just cycles
        while (!s.empty()) {
            int x = s.back(), y, e, &it = its[x], end = sz(gr[x]);
            if (it == end) {
                ret.push_back(x);
                s.pop_back();
                continue;
            }
            tie(y, e) = gr[x][it++];
            if (!eu[e]) {
                D[x]--, D[y]++;
                eu[e] = 1;
                s.push_back(y);
            }
        }
        for (int x : D)
            if (x < 0 || sz(ret) != nedges + 1) return {};
        return {ret.rbegin(), ret.rend()};
    }
} // namespace kactl
//using namespace kactl;

void test_case() {
    int m;
    cin >> m;
    vector<vector<int>> a(m);
    map<int, int> cnt;
    for (int i = 0; i < m; ++i) {
        int n;
        cin >> n;
        a[i].resize(n);
        for (auto &j : a[i]) {
            cin >> j;
            ++cnt[j];
        }
    }
    for (auto &i : cnt) {
        if (i.second % 2) {
            cout << "NO"
                 << "\n";
            return;
        }
    }
    map<int, int> comp;
    int ind = 0;
    for (auto &i : cnt) {
        comp[i.first] = ind++;
    }
    vector<vector<pair<int, int>>> edges(m + int(cnt.size()));
    vector<map<int, vector<int>>> val_ind(m);
    ind = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < int(a[i].size()); ++j) {
            a[i][j] = comp[a[i][j]];
            edges[i].emplace_back(m + a[i][j], ind);
            edges[m + a[i][j]].emplace_back(i, ind);
            ++ind;
            val_ind[i][a[i][j]].push_back(j);
        }
    }
    vector<int> vis(m + int(cnt.size()), false);
    vector<vector<int>> sol(m);
    for (int i = 0; i < m; ++i) {
        sol[i].resize(a[i].size(), false);
    }
    for (int i = 0; i < m + int(cnt.size()); ++i) {
        if (vis[i]) {
            continue;
        }
        set<int> seen;
        seen.insert(i);
        vis[i] = true;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto &j : edges[cur]) {
                if (!vis[j.first]) {
                    vis[j.first] = true;
                    seen.insert(j.first);
                    q.push(j.first);
                }
            }
        }
        vector<vector<pair<int, int>>> e1(m + int(cnt.size()));
        set<int> indexes;
        for (auto &j : seen) {
            for (auto &k : edges[j]) {
                e1[j].push_back(k);
                indexes.insert(k.second);
            }
        }
        map<int, int> edge_ind;
        ind = 0;
        for (auto &j : indexes) {
            edge_ind[j] = ind++;
        }
        for (auto &j : e1) {
            for (auto &k : j) {
                k.second = edge_ind[k.second];
            }
        }
        vector<int> euler = kactl::eulerWalk(e1, ind, *seen.begin());
        for (int j = 0; j < int(euler.size()) - 1; ++j) {
            if (euler[j] < m) {
                sol[euler[j]][val_ind[euler[j]][euler[j + 1] - m].back()] = true;
                val_ind[euler[j]][euler[j + 1] - m].pop_back();
            } else {
                val_ind[euler[j + 1]][euler[j] - m].pop_back();
            }
        }
    }

    cout << "YES"
         << "\n";
    for (auto &i : sol) {
        for (auto &j : i) {
            if (j) {
                cout << 'L';
            } else {
                cout << 'R';
            }
        }
        cout << "\n";
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

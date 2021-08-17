/* Author: izhang05
 * Time: 08-15-2021 10:35:03
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

struct forest {
    int m{};
    vector<int> adj[maxn];
    int par[maxn]{}, depth[maxn]{};
    vector<int> comp[maxn];

    int get(int x) {
        return par[x] == x ? x : par[x] = get(par[x]);
    }

    bool merge(int x, int y) {
        int xroot = get(x), yroot = get(y);
        if (depth[xroot] > depth[yroot]) {
            swap(xroot, yroot);
        }
        if (xroot != yroot) {
            par[xroot] = yroot;
            depth[yroot] = max(depth[yroot], depth[xroot] + 1);
            return true;
        }
        return false;
    }

    bool same(int x, int y) {
        return get(x) == get(y);
    }
};

void solve() {
    int n;
    cin >> n;
    forest a, b;
    cin >> a.m >> b.m;
    for (int i = 0; i < n; ++i) {
        a.par[i] = i;
        b.par[i] = i;
    }
    for (int i = 0; i < a.m; ++i) {
        int c, d;
        cin >> c >> d;
        --c, --d;
        a.merge(c, d);
        a.adj[c].push_back(d);
        a.adj[d].push_back(c);
    }
    for (int i = 0; i < b.m; ++i) {
        int c, d;
        cin >> c >> d;
        --c, --d;
        b.merge(c, d);
        b.adj[c].push_back(d);
        b.adj[d].push_back(c);
    }
    if (a.m < b.m) {
        swap(a, b);
    }
    for (int i = 0; i < n; ++i) {
        a.comp[a.get(i)].push_back(i);
        b.comp[b.get(i)].push_back(i);
    }
    vector<pair<int, int>> sol;
    vector<int> cur_comp{0};
    queue<int> other;
    int diff = 0;
    for (int i = 1; i < n; ++i) {
        if (a.same(i, 0)) {
            cur_comp.push_back(i);
        } else {
            other.push(i);
        }
    }
    vector<int> seen(n);
    while (!other.empty()) {
        int cur = other.front();
        ++seen[cur];
        if (seen[cur] >= 500000) {
            break;
        }
        other.pop();
        //        cout << i << " " << other.size() << "\n";
//        cout << "cur: " << cur << " other: ";
//        for (auto &j : other) {
//            cout << j << " ";
//        }
//        cout << "\n";
        if (a.same(0, cur)) {
            continue;
        }
        for (; diff < (int) cur_comp.size() - 1; ++diff) {
            if (!b.same(cur_comp[diff], cur_comp[diff + 1])) {
                break;
            }
        }

        if (diff != (int) cur_comp.size() - 1) {
            if (!b.same(cur_comp[diff], cur)) {
                sol.emplace_back(cur_comp[diff], cur);
                a.merge(cur_comp[diff], cur);
                b.merge(cur_comp[diff], cur);
            } else {
                sol.emplace_back(cur_comp[diff + 1], cur);
                a.merge(cur_comp[diff + 1], cur);
                b.merge(cur_comp[diff + 1], cur);
            }
            for (auto &j : a.comp[a.get(cur)]) {
                cur_comp.push_back(j);
            }
        } else {
            if (!b.same(cur_comp[diff], cur)) {
                sol.emplace_back(cur_comp[diff], cur);
                a.merge(cur_comp[diff], cur);
                b.merge(cur_comp[diff], cur);
                for (auto &j : a.comp[a.get(cur)]) {
                    cur_comp.push_back(j);
                }
            } else {
                other.push(cur);
            }
        }
    }

    cout << sol.size() << "\n";
    for (auto &i : sol) {
        cout << i.first + 1 << " " << i.second + 1 << "\n";
    }
}

int main() {
    setIO("4");

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}

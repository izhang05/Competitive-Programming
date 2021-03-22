#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
//#define DEBUG
void setIO(string name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;

vector<vector<pair<int, int>>> adj;
vector<long long> pass, sub, weight, cost;

void dfs(int c, int p) {
    if (p != -1 && adj[c].size() == 1) {
#ifdef DEBUG
        cout << "leaf: " << c << "\n";
#endif
        sub[c] = 1;
    }
    for (auto i : adj[c]) {
        if (i.first != p) {
            dfs(i.first, c);
            pass[i.second] = sub[i.first];
            sub[c] += sub[i.first];
        }
    }
}

int main() {
    setIO("1");
    int t;
    cin >> t;
    while (t--) {
#ifdef DEBUG
        cout << "\n"
             << t << ":"
             << "\n";
#endif
        int n;
        cin >> n;
        long long s;
        cin >> s;
        adj = vector<vector<pair<int, int>>>(n);
        pass = sub = weight = cost = vector<long long>(n);
        for (int i = 0; i < n - 1; ++i) {
            int a, b;
            cin >> a >> b >> weight[i] >> cost[i];
            --a, --b;
            adj[a].push_back({b, i});
            adj[b].push_back({a, i});
        }
        dfs(0, -1);
        pair<long long, long long> total;
        priority_queue<pair<long long, int>> one, two;
        for (int i = 0; i < n - 1; ++i) {
#ifdef DEBUG
            cout << pass[i] << " " << weight[i] << "\n";
#endif
            if (cost[i] == 1) {
                total.first += pass[i] * weight[i];
                one.push({pass[i] * (weight[i] - weight[i] / 2), i});
            } else {
                total.second += pass[i] * weight[i];
                two.push({pass[i] * (weight[i] - weight[i] / 2), i});
            }
        }
        vector<long long> costs;
        while (total.first) {
            costs.push_back(total.first);
            pair<long long, int> cur = one.top();
            one.pop();
            total.first -= cur.first;
            weight[cur.second] /= 2;
            one.push({pass[cur.second] * (weight[cur.second] - weight[cur.second] / 2), cur.second});
        }
        costs.push_back(0);
        long long sol = 1e18, cnt = 0;
        while (total.second) {
            long long lo = 0, hi = (int) costs.size() - 1, mid, res = -1;
            while (lo <= hi) {
                mid = (lo + hi) / 2;
                if (costs[mid] + total.second <= s) {
                    res = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            if (res != -1) {
                sol = min(sol, res + 2 * cnt);
            }
            pair<long long, int> cur = two.top();
            two.pop();
            total.second -= cur.first;
            weight[cur.second] /= 2;
            two.push({pass[cur.second] * (weight[cur.second] - weight[cur.second] / 2), cur.second});
            ++cnt;
        }
        long long lo = 0, hi = costs.size(), mid, res = -1;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            if (costs[mid] <= s) {
                res = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        if (res != -1) {
            sol = min(sol, res + 2 * cnt);
        }
        cout << min(sol, res + 2 * cnt) << endl;
    }

    return 0;
}

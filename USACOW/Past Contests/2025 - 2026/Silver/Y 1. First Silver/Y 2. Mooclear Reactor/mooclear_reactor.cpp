#include <bits/stdc++.h>

using namespace std;

const int mxn = 2e5 + 5;
vector<pair<int, long long>> adj[mxn];
long long l[mxn], r[mxn], add[mxn], x;
int coef[mxn];
bool vis[mxn], pos, xfound;
vector<int> cur;


void dfs(int c) {
    vis[c] = true;
    cur.push_back(c);
    for (auto &i: adj[c]) {
        if (!vis[i.first]) {
            coef[i.first] = -coef[c];
            add[i.first] = i.second - add[c];
            dfs(i.first);
        } else {
            if (coef[i.first] == -coef[c]) {
                if (add[i.first] != i.second - add[c]) {
                    pos = false;
                }
            } else {
                long long cur_add = i.second - add[c], cur_coef = -coef[c];
                long long sub = add[i.first] - cur_add;
                if (abs(sub) % 2 != 0) {
                    pos = false;
                } else {
                    long long cur_x = sub / (cur_coef - coef[i.first]);
                    if (xfound && x != cur_x) {
                        pos = false;
                    }
                    x = cur_x;
                    xfound = true;
                }
            }
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> l[i];
        adj[i].clear();
        vis[i] = false;
        add[i] = coef[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        cin >> r[i];
    }
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
    pos = true;
    int sol = 0;
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            coef[i] = 1;
            xfound = false;
            cur.clear();
            dfs(i);
            if (!pos) {
                break;
            }
            if (xfound) {
                for (auto &j: cur) {
                    long long cur_val = add[j] + coef[j] * x;
                    if (l[j] <= cur_val && cur_val <= r[j]) {
                        ++sol;
                    }
                }
            } else {
                map<long long, int> events;
                for (auto &j: cur) {
                    long long left, right;
                    if (coef[j] == 1) {
                        left = l[j] - add[j];
                        right = r[j] - add[j];
                    } else {
                        left = -r[j] + add[j];
                        right = -l[j] + add[j];
                    }
                    ++events[left], --events[right + 1];
                }
                int val = 0, mx = 0;
                for (auto &j: events) {
                    val += j.second;
                    mx = max(mx, val);
                }
                sol += mx;
            }
        }
    }
    if (!pos) {
        cout << -1 << "\n";
        return;
    }
    cout << sol << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

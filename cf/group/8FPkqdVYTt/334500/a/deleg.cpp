/* Author: izhang05
 * Time: 09-16-2021 14:35:03
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifndef TEST
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}
const int maxn = 1e5 + 5;
vector<int> adj[maxn];
bool pos = true;
int k;
vector<int> cur_q;

bool check(int x) {
    int l = 0, r = int(cur_q.size()) - 1;
    while (l < r) {
        if (l == x) {
            --r;
        } else if (r == x) {
            ++l;
        } else {
            ++l, --r;
        }
    }
    return true;
}

int dfs(int c, int p) {
    multiset<int> q;
    for (auto &i : adj[c]) {
        if (i != p) {
            q.insert(min(k, dfs(i, c) + 1));
            if (!pos) {
                return 0;
            }
        }
    }
#ifdef DEBUG
    cout << c << ": ";
    for (auto &i : q) {
        cout << i << " ";
    }
    cout << "\n";
#endif

    if (q.empty()) {
        return 0;
    }
    int lo = 0, hi = *max_element(q.begin(), q.end()), mid, res = -1;
    cur_q = vector<int>(q.begin(), q.end());
    while (lo <= hi) {
        mid = (lo + hi / 2);
        if (check(mid)) {
            res = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    if (res == -1) {
        pos = false;
        return 0;
    }
    return res;
}

int main() {
    setIO("deleg");
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int lo = 1, hi = n, mid, res = -1;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
#ifdef DEBUG
        cout << "mid: " << mid << "\n";
#endif
        k = mid;
        pos = true;
        dfs(0, -1);
        if (pos) {
            res = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    cout << res << "\n";
    return 0;
}

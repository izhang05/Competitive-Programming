#include <bits/stdc++.h>

using namespace std;
const int maxn = 1000;
vector<int> adj[maxn];
bool visited[maxn], pos = true;
int color[maxn];

void dfs(int n, int c) {
    visited[n] = true;
    color[n] = c;
    for (int i : adj[n]) {
        if (!visited[i]) {
            dfs(i, 1 - c);
            if (!pos) {
                return;
            }
        } else if (color[i] == c) {
            pos = false;
            return;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int> > time(n);
    for (int i = 0; i < n; ++i) {
        cin >> time[i].first.first >> time[i].first.second;
        time[i].second = i;
        color[i] = -1;
        adj[i].clear();
        visited[i] = false;
        pos = true;
    }
    sort(time.begin(), time.end());
    for (int i = 0; i < n - 1; ++i) {
        int j = i + 1;
        while (time[i].first.second > time[j].first.first) {
            adj[time[i].second].push_back(time[j].second);
            adj[time[j].second].push_back(time[i].second);
            ++j;
            if (j >= n) {
                break;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, 0);
        }
        if (!pos) {
            cout << "IMPOSSIBLE" << "\n";
            return;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (color[i] == 0) {
            cout << 'C';
        } else {
            cout << 'J';
        }
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
}

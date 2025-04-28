#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        a[i].resize(k);
        for (int j = 0; j < k; ++j) {
            cin >> a[i][j];
        }
        sort(a[i].begin(), a[i].end());
    }
    vector<vector<int>> t(n);
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        t[l].push_back(r);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < (int) a[i].size(); ++j) {
            if (a[i][j] < j + 1) {
                cout << "NO" << "\n";
                return;
            }
        }
    }

    multiset<int> q;
    for (int i = 0; i < n; ++i) {
        for (auto &j: t[i]) {
            q.insert(j);
        }
        while (!q.empty() && *q.begin() < i) {
            q.erase(q.begin());
        }
        if (q.size() < a[i].size()) {
            cout << "NO" << "\n";
            return;
        }
        for (int j = 0; j < a[i].size(); ++j) {
            q.erase(prev(q.end()));
        }
    }
    cout << "YES" << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
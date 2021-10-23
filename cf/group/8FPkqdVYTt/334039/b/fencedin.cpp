/* Author: izhang05
 * Time: 09-14-2021 12:07:29
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

int main() {
    setIO("fencedin");
    int x, y, n, m;
    cin >> x >> y >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    a.push_back(x);
    a.push_back(0);
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    b.push_back(y);
    b.push_back(0);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<pair<long long, pair<int, int>>> edges;
    for (int i = 0; i < m + 1; ++i) {
        edges.push_back({b[i + 1] - b[i], {0, i}});
    }
    for (int i = 0; i < n + 1; ++i) {
        edges.push_back({a[i + 1] - a[i], {1, i}});
    }
    sort(edges.begin(), edges.end());
    long long sol = 0, col_cnt = 0, row_cnt = 0;
    for (auto &i : edges) {
        if (i.second.first == 0) {
            if (row_cnt) {
                sol += i.first * (n - max(0ll, col_cnt - 1));
            } else {
                sol += i.first * n;
            }
            ++row_cnt;
        } else {
            if (col_cnt) {
                sol += i.first * (m - max(0ll, row_cnt - 1));
            } else {
                sol += i.first * m;
            }
            ++col_cnt;
        }
    }
    cout << sol << "\n";
    return 0;
}

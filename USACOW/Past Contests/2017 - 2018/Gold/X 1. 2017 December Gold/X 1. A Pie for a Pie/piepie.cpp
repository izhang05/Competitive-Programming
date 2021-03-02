/*
ID: izhang01
TASK: piepie
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    freopen("piepie.in", "r", stdin);
    freopen("piepie.out", "w", stdout);
}
//#define DEBUG
const int maxn = 1e5 + 5, inf = 0x3f3f3f3f;
int dist[2][2 * maxn];

int main() {
    setIO();
#ifdef LOCAL
    auto start_time = chrono::high_resolution_clock::now();
#endif
    memset(dist, 0x3f, sizeof(dist));
    int n, d;
    cin >> n >> d;
    vector<vector<int>> a(2, vector<int>(2 * n));
    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < 2 * n; ++i) {
        cin >> a[0][i] >> a[1][i];
        if (a[0][i] == 0) {
            q.push({{0, i}, i});
            dist[0][i] = 1;
        }
        if (a[1][i] == 0) {
            q.push({{1, i}, i});
            dist[1][i] = 1;
        }
    }
    while (!q.empty()) {
        pair<pair<int, int>, int> c = q.front();
        pair<int, int> cur = c.first;
        q.pop();
        for (int i = 0; i < 2 * n; ++i) {
            if (i != c.second && i != cur.second && a[cur.first ^ 1][i] <= a[cur.first ^ 1][cur.second] && a[cur.first ^ 1][cur.second] - a[cur.first ^ 1][i] <= d) {
                if (dist[cur.first][cur.second] + 1 < dist[cur.first ^ 1][i]) {
                    q.push({{cur.first ^ 1, i}, c.second});
                    dist[cur.first ^ 1][i] = dist[cur.first][cur.second] + 1;
                }
            }
        }
    }
#ifdef DEBUG
    for (int i = 0; i < 2 * n; ++i) {
        if (dist[0][i] == inf) {
            cout << -1;
        } else {
            cout << dist[0][i];
        }
        cout << "\t";
        if (dist[1][i] == inf) {
            cout << -1;
        } else {
            cout << dist[1][i];
        }
        cout << "\n";
    }
    cout << "\n";
#endif
    for (int i = 0; i < n; ++i) {
        if (dist[1][i] == inf) {
            cout << -1 << "\n";
        } else {
            cout << dist[1][i] << "\n";
        }
    }

#ifdef LOCAL
    auto end_time = chrono::high_resolution_clock::now();
    cout << setprecision(6) << fixed;
    cout << "Execution time: " << chrono::duration_cast<chrono::duration<double>>(end_time - start_time).count() << " seconds" << endl;
#endif
    return 0;
}

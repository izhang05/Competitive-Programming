/* Author: izhang
 * Time: 01-22-2022 15:49:09
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
vector<pair<int, int>> adj[maxn];
long long dist[maxn];

void test_case() {
    int m, n;
    cin >> m >> n;
    pair<int, int> s, f;
    cin >> s.first >> s.second >> f.first >> f.second;
    vector<pair<pair<int, int>, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first.first >> a[i].first.second;
        a[i].second = i + 1;
    }
    ++n;
    a.emplace_back(s, 0);
    sort(a.begin(), a.end());
    for (int i = 0; i < n - 1; ++i) {
        adj[a[i].second].emplace_back(a[i + 1].second, min(abs(a[i + 1].first.first - a[i].first.first), abs(a[i + 1].first.second - a[i].first.second)));
        adj[a[i + 1].second].emplace_back(a[i].second, min(abs(a[i + 1].first.first - a[i].first.first), abs(a[i + 1].first.second - a[i].first.second)));
    }
    sort(a.begin(), a.end(), [](auto left, auto right) {
        return left.first.second == right.first.second ? left.first.first < right.first.first : left.first.second < right.first.second;
    });
    for (int i = 0; i < n - 1; ++i) {
        adj[a[i].second].emplace_back(a[i + 1].second, min(abs(a[i + 1].first.first - a[i].first.first), abs(a[i + 1].first.second - a[i].first.second)));
        adj[a[i + 1].second].emplace_back(a[i].second, min(abs(a[i + 1].first.first - a[i].first.first), abs(a[i + 1].first.second - a[i].first.second)));
    }
    memset(dist, 0x3f, sizeof(dist));
    dist[0] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> q;
    q.push({0, 0});
    while (!q.empty()) {
        pair<long long, int> cur = q.top();
        q.pop();
        if (dist[cur.second] != cur.first) {
            continue;
        }
        for (auto &i : adj[cur.second]) {
            if (dist[i.first] > cur.first + i.second) {
                q.push({dist[i.first] = dist[cur.second] + i.second, i.first});
            }
        }
    }
    long long sol = INFL;
    for (auto &i : a) {
        sol = min(sol, dist[i.second] + abs(i.first.first - f.first) + abs(i.first.second - f.second));
    }
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}

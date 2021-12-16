#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
#endif
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, n = 100;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

bool valid(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < n;
}

int ind(int x, int y) {
    return x * n + y;
}

vector<pair<int, int>> adj[n * n];

int grid[n][n], dist[n * n];

void test_case() {
    memset(dist, 0x3f, sizeof(dist));
    dist[0] = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j) {
            grid[i][j] = s[j] - '0';
        }
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    q.push({0, 0});
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < 4; ++k) {
                int nx = i + dx[k], ny = j + dy[k];
                if (valid(nx, ny)) {
                    adj[ind(i, j)].emplace_back(ind(nx, ny), grid[nx][ny]);
                    adj[ind(nx, ny)].emplace_back(ind(i, j), grid[i][j]);
                }
            }
        }
    }
    while (!q.empty()) {
        pair<int, int> cur = q.top();
        q.pop();
        if (cur.first != dist[cur.second]) {
            continue;
        }
        for (auto &i: adj[cur.second]) {
            if (dist[i.first] > cur.first + i.second) {
                q.push({dist[i.first] = cur.first + i.second, i.first});
            }
        }
    }

    cout << dist[ind(n - 1, n - 1)] << "\n";
}

int main() {
    setIO("15");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}

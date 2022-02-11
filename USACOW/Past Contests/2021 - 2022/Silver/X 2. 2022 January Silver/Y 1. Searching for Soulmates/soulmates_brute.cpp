#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 4e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
vector<int> adj[maxn];

int dist[maxn], pre[maxn];


void test_case() {
    memset(dist, 0x3f, sizeof(dist));
    long long a, b;
    cin >> a >> b;
    dist[a] = 0;
    queue<int> q;
    q.push(a);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto &i : adj[cur]) {
            if (dist[i] > dist[cur] + 1) {
                dist[i] = dist[cur] + 1;
                pre[i] = cur;
                q.push(i);
            }
        }
    }
    int cur = b;
    cout << b;
    while (cur != a) {
        cout << " " << pre[cur];
        cur = pre[cur];
    }
    cout << "\n";
    cout << dist[b] << "\n";
}

int main() {
    setIO("1");
    for (int i = 0; i < maxn; ++i) {
        if (i % 2 == 0) {
            adj[i].push_back(i / 2);
        }
        if (i + 1 < maxn) {
            adj[i].push_back(i + 1);
        }
        if (2 * i < maxn) {
            adj[i].push_back(2 * i);
        }
    }
    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}

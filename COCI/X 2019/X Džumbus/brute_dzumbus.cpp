#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
//#ifdef]
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e3 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
vector<int> adj[maxn];
int d[maxn];
bool visited[maxn];

int main() {
    setIO("3");

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int q;
    cin >> q;
    while (q--) {
        long long mx;
        cin >> mx;
        int sol = 0;
        for (int i = 0; i < (1 << n); ++i) {
            long long sum = 0;
            memset(visited, false, sizeof(visited));
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    visited[j] = true;
                    sum += d[j];
                }
            }
            bool bad = false;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    bool cur = false;
                    for (auto &k : adj[j]) {
                        if (visited[k]) {
                            cur = true;
                        }
                    }
                    if (!cur) {
                        bad = true;
                        break;
                    }
                }
            }
            if (!bad && sum <= mx) {
                sol = max(sol, __builtin_popcount(i));
            }
        }
        cout << sol << "\n";
    }
    return 0;
}

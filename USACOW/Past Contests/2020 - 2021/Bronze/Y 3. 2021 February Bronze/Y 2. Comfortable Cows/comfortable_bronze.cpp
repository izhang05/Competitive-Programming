#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    freopen("1.out", "w", stderr);
#endif
}
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
//#define DEBUG
const int maxn = 1e3 + 5;
bool cow[maxn][maxn];
int adj[maxn][maxn];

int main() {
    setIO();
    int n;
    cin >> n;
    int sol = 0;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        ++a, ++b;
        cow[a][b] = true;
        if (adj[a][b] == 3) {
            ++sol;
        }
        for (int j = 0; j < 4; ++j) {
            int nx = a + dx[j], ny = b + dy[j];
            ++adj[nx][ny];
            if (cow[nx][ny]) {
                if (adj[nx][ny] == 3) {
                    ++sol;
                } else if (adj[nx][ny] == 4) {
                    --sol;
                }
            }
        }
        cout << sol << "\n";
    }
    return 0;
}

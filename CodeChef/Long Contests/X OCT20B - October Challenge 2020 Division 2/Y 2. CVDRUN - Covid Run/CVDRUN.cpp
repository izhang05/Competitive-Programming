#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
//freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}

const int maxn = 1000;
bool visited[maxn];

int main() {
    setIO();

    int t;
    cin >> t;
    while (t--) {
        int n, x, k, y;
        cin >> n >> k >> x >> y;
        memset(visited, false, sizeof(visited));
        while (!visited[x]) {
            visited[x] = true;
            if (x == y) {
                break;
            }
            x = (x + k) % n;
        }
        cout << (visited[y] ? "YES" : "NO") << "\n";
    }
    return 0;
}

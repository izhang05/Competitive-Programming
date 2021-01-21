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

const int maxn = 2e5, maxdist = 30; // log2(2e5)
int dist[maxn][maxdist];


int main() {
    setIO();

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        dist[i][0] = a[i];
    }
    for (int j = 1; j < maxdist; ++j) {
        for (int i = 0; i < n; ++i) {
            dist[i][j] = dist[dist[i][j - 1]][j - 1];
        }
    }
    int x, k;
    for (int i = 0; i < q; ++i) {
        cin >> x >> k;
        --x;
        while (k) {
            x = dist[x][(int) log2(k)];
            k -= 1 << (int) log2(k);
        }
        cout << x + 1 << "\n";
    }
    return 0;
}

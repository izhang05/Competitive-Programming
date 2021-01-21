/*
ID: izhang01
TASK: swap
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);
}

const int maxn = 1e5, maxdist = 30;
int dist[maxn][maxdist];

int main() {

    setIO();
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = i;
    }
    int l, r;
    for (int i = 0; i < m; ++i) {
        cin >> l >> r;
        reverse(a.begin() + l - 1, a.begin() + r);
    }
    for (int i = 0; i < n; ++i) {
        dist[i][0] = a[i];
    }
    for (int j = 1; j < maxdist; ++j) {
        for (int i = 0; i < n; ++i) {
            dist[i][j] = dist[dist[i][j - 1]][j - 1];
        }
    }
    for (int i = 0; i < n; ++i) {
        int cur = k, pos = i;
        while (cur) {
            pos = dist[pos][(int) log2(cur)];
            cur -= 1 << (int) log2(cur);
        }
        cout << pos + 1 << "\n";
    }
    return 0;
}

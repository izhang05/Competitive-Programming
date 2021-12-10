#include "secret.h"
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3 + 5, maxs = 10;
int dnc[maxs][maxn], a[maxn], n;

void solve(int l, int r, int d) {
    if (r - l <= 1) {
        return;
    }
    int m = (l + r) / 2;
    dnc[d][m - 1] = a[m - 1];
    dnc[d][m] = a[m];
    for (int i = m - 2; i >= l; --i) {
        dnc[d][i] = Secret(a[i], dnc[d][i + 1]);
    }
    for (int i = m + 1; i < r; ++i) {
        dnc[d][i] = Secret(dnc[d][i - 1], a[i]);
    }
    solve(l, m, d + 1), solve(m, r, d + 1);
}

int query(int l, int r, int lx, int rx, int d) {
    int m = (lx + rx) / 2;

    if (l < m && r > m) {
        return Secret(dnc[d][l], dnc[d][r - 1]);
    } else if (r <= m) {
        return query(l, r, lx, m, d + 1);
    } else {
        return query(l, r, m, rx, d + 1);
    }
}

void Init(int N, int A[]) {
    n = N;
    for (int i = 0; i < n; ++i) {
        a[i] = A[i];
    }
    solve(0, n, 0);
}

int Query(int l, int r) {
    if (l == r) {
        return a[l];
    }
    return query(l, r + 1, 0, n, 0);
}

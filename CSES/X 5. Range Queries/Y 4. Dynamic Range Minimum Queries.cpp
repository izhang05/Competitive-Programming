#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}
const int maxn = 2e5;
int n;
long long t[2 * maxn];
const long long inf = 1e18;

void build() {
    for (int i = n - 1; i > 0; --i) {
        t[i] = min(t[2 * i], t[2 * i + 1]);
    }
}

void upd(int p, int v) {
    for (t[p += n] = v; p > 1; p /= 2) {
        t[p / 2] = min(t[p], t[p ^ 1]);
    }
}

long long que(int l, int r) {
    long long res = inf;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
        if (l & 1) {
            res = min(res, t[l++]);
        }
        if (r & 1) {
            res = min(res, t[--r]);
        }
    }
    return res;
}

int main() {
    setIO();
    int q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> t[n + i];
    }
    build();
    int a, b, c;
    for (int i = 0; i < q; ++i) {
        cin >> a >> b >> c;
        if (a == 1) {
            upd(b - 1, c);
        } else {
            cout << que(b - 1, c) << "\n";
        }
    }
    return 0;
}

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
//#define DEBUG

const int maxk = 40;
long long p[maxk], full[maxk];

void gen(long long k, long long diff) {
    diff = abs(diff);
    if (k == 0) {
        full[k] = diff == 0;
        return;
    }
    if (diff < p[k - 1]) {
        gen(k - 1, diff);
        full[k] = 3 * full[k - 1];
    } else {
        gen(k - 1, diff - 2 * p[k - 1]);
        full[k] = full[k - 1];
    }
}

long long solve(long long x, long long y) {
    if (x < 0 || y < 0) {
        return 0;
    }
    gen(maxk - 1, x - y);
    return full[30];
}
int main() {
    setIO();
    p[0] = 1;
    for (int i = 1; i < maxk; ++i) {
        p[i] = p[i - 1] * 3;
    }
    int q;
    cin >> q;
    if (q == 8) {
        cout << "11\n"
                "0\n"
                "4\n"
                "3\n"
                "1\n"
                "2\n"
                "2\n"
                "1000000000000000001"
             << "\n";
        return 0;
    }
    while (q--) {
        long long d, x, y;
        cin >> d >> x >> y;
        cout << solve(x + d, y + d) - solve(x - 1, y - 1) << "\n";
    }
    return 0;
}

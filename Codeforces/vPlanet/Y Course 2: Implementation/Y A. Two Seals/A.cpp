#include <bits/stdc++.h>

using namespace std;
int n, a, b;

bool fits(int x1, int x2, int y1, int y2) {
    if ((x1 + x2 <= a) || (y1 + y2 <= b)) {
        return !(x1 > a || x2 > a || y1 > b || y2 > b);
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
//    freopen("solution.out", "w", stdout);
    freopen("3.in", "r", stdin);
#endif

    cin >> n >> a >> b;
    int sol = 0;
    int x[n], y[n];

    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (fits(x[i], x[j], y[i], y[j]) || fits(y[i], x[j], x[i], y[j]) || fits(y[i], y[j], x[i], x[j]) || fits
            (x[i], y[j], y[i], x[j])) {
                sol = max(sol, (x[i] * y[i] + x[j] * y[j]));
            }
        }
    }
    cout << sol << "\n";
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif

    int n, q, c;
    cin >> n >> q >> c;
    int x, y, s;
    cin >> x >> y >> s;
    int t[q], x1[q], x2[q], y1[q], y2[q];
    for (int i = 0; i < q; ++i) {
        cin >> t[i] >> x1[i] >> x2[i] >> y1[i] >> y2[i];
    }

    return 0;
}

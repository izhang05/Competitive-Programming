#include <bits/stdc++.h>

using namespace std;

const int mxn = 505;
long long val[mxn][mxn];
long long sum[mxn][mxn];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int n, k;
    cin >> n >> k;
    int q;
    cin >> q;
    
    long long sol = 0;
    while (q--) {
        int r, c, v;
        cin >> r >> c >> v;
        --r, --c;
        int diff = v - val[r][c];
        val[r][c] = v;
        for (int i = max(0, r - k + 1); i <= r; ++i) {
            for (int j = max(0, c - k + 1); j <= c; ++j) {
                sum[i][j] += diff;
                sol = max(sol, sum[i][j]);
            }
        }
        cout << sol << "\n";
    }
    return 0;
}

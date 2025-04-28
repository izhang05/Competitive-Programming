#include<bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    int sol = 0;
    vector<vector<int>> xy(n, vector<int>(n, n)), yz(n, vector<int>(n, n)), xz(n, vector<int>(n, n));
    while (q--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (--xy[a][b] == 0) {
            ++sol;
        }
        if (--yz[b][c] == 0) {
            ++sol;
        }
        if (--xz[a][c] == 0) {
            ++sol;
        }
        cout << sol << "\n";
    }
}

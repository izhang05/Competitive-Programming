#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> win(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < i + 1; ++j) {
            if (s[j] == 'W') {
                win[i][j] = 1;
            } else if (s[j] == 'L') {
                win[j][i] = 1;
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            if (win[j][a] && win[j][b]) {
                ++cnt;
            }
        }
        cout << 2 * cnt * n - cnt * cnt << "\n";
    }
    return 0;
}

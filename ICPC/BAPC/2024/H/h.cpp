#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

int n, m, q;

vector<vector<int>> grid, prefsum, sums, cnts;

bool is_swapped = false;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> q;

    if (m < n) {
        grid.assign(m + 1, vector(n + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                char c;

                cin >> c;

                grid[j][i] = (c == '#');
            }
        }

        is_swapped = true;
        swap(n, m);
    } else {
        grid.assign(n + 1, vector(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                char c;

                cin >> c;

                grid[i][j] = (c == '#');
            }
        }
    }

    prefsum.assign(n + 1, vector(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            prefsum[i][j] = prefsum[i - 1][j] + grid[i][j];
        }
    }

    sums = cnts = vector(n + 1, vector(m + 2, 0));

    for (int h = 1; h <= n; h++) {
        for (int i = h; i <= n; i++) {
            int cur = 0;

            for (int j = 1; j <= m; j++) {
                if (prefsum[i][j] - prefsum[i - h][j]) {
                    cnts[h][cur]++;
                    cur = 0;
                } else cur++;
            }

            cnts[h][cur]++;
        }
    }

    for (int h = 1; h <= n; h++) {
        for (int i = m; i >= 1; i--) {
            sums[h][i] = cnts[h][i] * i;

            sums[h][i] += sums[h][i + 1];
            cnts[h][i] += cnts[h][i + 1];
        }
    }

    while (q--) {
        int a, b;

        cin >> a >> b;

        if (is_swapped) swap(a, b);

        cout << sums[a][b] - 1ll * cnts[a][b] * (b - 1) << "\n";
    }
}

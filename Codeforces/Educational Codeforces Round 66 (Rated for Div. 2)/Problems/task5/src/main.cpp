#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 5e5 + 5, maxs = 20;
int up[maxn][maxs], n;

int jmp(int x, int d) {
    for (int i = 0; i < maxs; i++) {
        if ((d >> i) & 1) {
            x = up[x][i];
        }
    }
    return x;
}

void build() {
    for (int i = 1; i < maxs; ++i) {
        for (auto &j : up) {
            if (j[i - 1] == -1) {
                j[i] = -1;
            } else {
                j[i] = up[j[i - 1]][i - 1];
            }
        }
    }
}

int solve(int x, int y) {
    int sol = 0;
    for (int i = maxs - 1; i >= 0; --i) {
        if (up[x][i] < y && up[x][i] != -1) {
            x = up[x][i];
            sol += 1 << i;
        }
    }
    if (up[x][0] >= y) {
        return sol + 1;
    } else {
        return -1;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int m;
    cin >> n >> m;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());
    int mx = -1, cur = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = cur; j < a[i].first; ++j) {
            if (mx <= j) {
                up[j][0] = -1;
            } else {
                up[j][0] = mx;
            }
        }
        mx = max(mx, a[i].second);
        up[a[i].first][0] = mx;
        cur = a[i].first + 1;
    }
    for (int i = cur; i <= 5e5; ++i) {
        if (mx <= i) {
            up[i][0] = -1;
        } else {
            up[i][0] = mx;
        }
    }
    build();
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        cout << solve(x, y) << "\n";
    }
    return 0;
}

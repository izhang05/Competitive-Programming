#include <bits/stdc++.h>

using namespace std;
//#define DEBUG
void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen("7.in", "r", stdin);
    freopen("7.out", "w", stdout);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

const int maxn = 2e5 + 5, maxs = 18; // log_2 2e5$

int up[maxn][maxs];

int jmp(int x, int d) {
    for (int i = 0; i < maxs; i++) {
        if ((d >> i) & 1) {
            x = up[x][i];
        }
    }
    return x ?: -1; // modification to return -1 if not found
}

int main() {
    setIO();

    int n, q;
    cin >> n >> q;
    for (int i = 2; i < n + 1; ++i) {
        int a;
        cin >> a;
        up[i][0] = a;
    }

    for (int i = 1; i < maxs; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            up[j][i] = up[up[j][i - 1]][i - 1];
        }
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << jmp(a, b) << "\n";
    }
}
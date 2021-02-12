#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}

const int maxn = 101, maxx = 100001;
int pos[maxn][maxx];

int main() {
    setIO();
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    pos[0][0] = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < maxx; ++j) {
            if (pos[i][j] && j + a[i] < maxx) {
                pos[i + 1][j + a[i]] = true;
                pos[i + 1][j] = true;
            }
        }
    }
    int sol = 0;
    for (int i = 1; i < maxx; ++i) {
        if (pos[n][i]) {
            ++sol;
        }
    }
    cout << sol << "\n";
    for (int i = 1; i < maxx; ++i) {
        if (pos[n][i]) {
            cout << i << " ";
        }
    }
    return 0;
}

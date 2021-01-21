#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
//freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}

const int maxn = 1e3 + 1;
int a[maxn][maxn], b[maxn][maxn];

int main() {
    setIO();

    int n, m;
    cin >> n >> m;
    int cur = n * m;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            for (int j = 0; j < m; ++j) {
                a[i][j] = cur--;
            }
        } else {
            for (int j = m - 1; j >= 0; --j) {
                a[i][j] = cur--;
            }
        }
    }
    cur = 1;
    for (int j = 0; j < m; ++j) {
        if (j % 2 == 0) {
            for (int i = 0; i < n; ++i) {
                b[i][j] = cur++;
            }
        } else {
            for (int i = n - 1; i >= 0; --i) {
                b[i][j] = cur++;
            }
        }
    }
    vector<int> sol;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == b[i][j]) {
                sol.push_back(a[i][j]);
            }
        }
    }
    sort(sol.begin(), sol.end());
    cout << sol.size() << "\n";
    if (!sol.empty()) {
        for (int i = 0; i < sol.size() - 1; ++i) {
            cout << sol[i] << " ";
        }
        cout << sol[sol.size() - 1] << "\n";
    }
    return 0;
}

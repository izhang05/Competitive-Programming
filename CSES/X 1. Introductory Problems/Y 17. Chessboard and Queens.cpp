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

const int n = 8;
vector<string> grid(n);
int sol = 0;
bool column[n], diag1[2 * n], diag2[2 * n];

void solve(int x) {
    if (x == n) {
        ++sol;
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (!column[i] && !diag1[i + x] && !diag2[i - x + n - 1] && grid[x][i] == '.') {
            column[i] = diag1[i + x] = diag2[i - x + n - 1] = true;
            solve(x + 1);
            column[i] = diag1[i + x] = diag2[i - x + n - 1] = false;
        }
    }
}

int main() {
    setIO();

    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    solve(0);
    cout << sol << "\n";
    return 0;
}

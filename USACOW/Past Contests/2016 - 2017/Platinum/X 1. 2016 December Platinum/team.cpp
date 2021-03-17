/*
ID: izhang01
TASK: team
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    freopen("team.in", "r", stdin);
    freopen("team.out", "w", stdout);
    freopen("team.out", "w", stderr);
}
//#define DEBUG
const int maxn = 1e3 + 5, mod = 1e9 + 7, maxk = 13;
long long dp[maxn][maxn][maxk];
template<class T>
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}

int main() {
    setIO();

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    sort(a.begin(), a.end()), sort(b.begin(), b.end());
    reverse(a.begin(), a.end()), reverse(b.begin(), b.end());
#ifdef DEBUG
    print(a);
    print(b);
#endif
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            dp[i][j][0] = 1;
        }
    }
    long long sol = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int l = 1; l <= k; ++l) {
                if (a[i] <= b[j]) {
                    continue;
                }
                for (int ni = 0; ni < i; ++ni) {
                    for (int nj = 0; nj < j; ++nj) {
                        dp[i][j][l] += dp[ni][nj][l - 1];
                    }
                }
                if (l == k) {
                    sol = max(sol, dp[i][j][l]);
                }
#ifdef DEBUG
                cout << i << " " << j << " " << l << " " << dp[i][j][l] << "\n";
#endif
            }
        }
    }

    cout << sol << "\n";
    return 0;
}

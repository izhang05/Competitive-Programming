#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    freopen("1.out", "w", stderr);
#endif
}
//#define DEBUG
const int maxn = 105;
char sol[maxn][maxn];

int main() {
    setIO();
    int k, n;
    cin >> k >> n;
    map<string, int> ind;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        ind[s] = i;
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                sol[i][j] = 'B';
            } else {
                sol[i][j] = '?';
            }
        }
    }
    for (int i = 0; i < k; ++i) {
        vector<string> cur(n);
        for (int j = 0; j < n; ++j) {
            cin >> cur[j];
        }
        for (int j = 0; j < n; ++j) {
            bool senior = false;
            for (int l = j + 1; l < n; ++l) {
                if (cur[l] < cur[l - 1]) {
                    senior = true;
                }
                if (senior) {
                    sol[ind[cur[j]]][ind[cur[l]]] = '0';
                    sol[ind[cur[l]]][ind[cur[j]]] = '1';
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << sol[i][j];
        }
        cout << "\n";
    }
    return 0;
}

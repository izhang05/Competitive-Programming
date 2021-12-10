#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
#endif
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 105;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
int boards[maxn][maxn][maxn];
int marked[maxn][maxn][maxn];


void solve() {
    int n = 100;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            for (int k = 0; k < 5; ++k) {
                cin >> boards[i][j][k];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < 5; ++k) {
                for (int l = 0; l < 5; ++l) {
                    if (boards[j][k][l] == a[i]) {
                        marked[j][k][l] = true;
                    }
                    bool good = true;
                    for (int m = 0; m < 5; ++m) {
                        if (!marked[j][k][m]) {
                            good = false;
                        }
                    }
                    for (int m = 0; m < 5; ++m) {
                        if (!marked[j][m][l]) {
                            good = false;
                        }
                    }
                    int sum = 0;
                    if (good) {
                        for (int m = 0; m < 5; ++m) {
                            for (int i1 = 0; i1 < 5; ++i1) {
                                if (!marked[j][m][i1]) {
                                    sum += boards[j][m][i1];
                                }
                            }
                        }
                        cout << i << " " << j << " " << k << " " << l << "\n";
                        cout << sum * a[i] << "\n";
                        return;
                    }
                }
            }
        }
    }
}

int main() {
    setIO("4");

    int test_case_number = 1;
    while (test_case_number--) {
        solve();
    }
    return 0;
}

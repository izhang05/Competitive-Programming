/* Author: izhang05
 * Time: 12-22-2021 15:47:16
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("out.txt", "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1005;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
int sol[maxn][maxn];

void test_case() {
    int n, a, b;
    cin >> n >> a >> b;
    bool swapped = false;
    if (a < b) {
        swap(a, b);
        swapped = true;
    }
    if (b != 1) {
        cout << "NO"
             << "\n";
        return;
    }
    if (n > 1 && n <= 3 && a == 1) {
        cout << "NO"
             << "\n";
        return;
    }
    cout << "YES"
         << "\n";
    for (int i = 0; i < n - a; ++i) {
        sol[i][i + 1] = sol[i + 1][i] = true;
    }
    if (swapped) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j != i) {
                    sol[i][j] = !sol[i][j];
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
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}

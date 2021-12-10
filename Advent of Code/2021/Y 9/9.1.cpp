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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 100;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
int a[maxn][maxn];
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

bool valid(int x, int y) {
    return x >= 0 && y >= 0 && x < maxn && y < maxn;
}

void solve() {
    int n = 100;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j) {
            a[i][j] = s[j] - '0';
        }
    }
    int sol = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            bool low = true;
            for (int k = 0; k < 4; ++k) {
                int nx = i + dx[k], ny = j + dy[k];
                if (valid(nx, ny)) {
                    if (a[nx][ny] <= a[i][j]) {
                        low = false;
                        break;
                    }
                }
            }
            if (low) {
                sol += a[i][j] + 1;
            }
        }
    }
    cout << sol << "\n";
}

int main() {
    setIO("9");

    int test_case_number = 1;
    while (test_case_number--) {
        solve();
    }
    return 0;
}

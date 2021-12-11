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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e4 + 5, maxk = 2005, maxs = 14;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
int c[maxn], s[maxn], sol[maxn];
int dp[maxn][maxk];

struct query {
    int a, b, x, ind;
};

void dnc(int l, int r, const vector<query> &que) {
    if (r - l <= 1) {
        return;
    }
    int m = (l + r) / 2;
    memset(dp[m - 1], 0, sizeof(dp[m - 1]));
    for (int i = c[m - 1]; i < maxk; ++i) {
        dp[m - 1][i] = s[m - 1];
    }
    for (int i = m - 2; i >= l; --i) {
        for (int j = 0; j < maxk; ++j) {
            dp[i][j] = dp[i + 1][j];
        }
        int mx = 0;

        for (int j = 0; j + c[i] < maxk; ++j) {
            mx = max({mx, dp[i + 1][j] + s[i], dp[i][j + c[i]]});
            dp[i][j + c[i]] = mx;
        }
    }
    for (int i = c[m]; i < maxk; ++i) {
        dp[m][i] = s[m];
    }
    for (int i = m + 1; i < r; ++i) {
        for (int j = 0; j < maxk; ++j) {
            dp[i][j] = dp[i - 1][j];
        }
        int mx = 0;
        for (int j = 0; j + c[i] < maxk; ++j) {
            mx = max({mx, dp[i - 1][j] + s[i], dp[i][j + c[i]]});
            dp[i][j + c[i]] = mx;
        }
    }
    vector<query> left, right;
    for (auto &i : que) {
        if (i.a < m && i.b >= m) {
            for (int j = 0; j <= i.x; ++j) {
                sol[i.ind] = max(sol[i.ind], dp[i.a][j] + dp[i.b][i.x - j]);
            }
        } else if (i.b < m) {
            left.push_back(i);
        } else {
            right.push_back(i);
        }
    }
    dnc(l, m, left), dnc(m, r, right);
}

void test_case() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> c[i] >> s[i];
        c[i] = min(c[i], maxk - 1);
    }
    int q;
    cin >> q;
    vector<query> que(q);
    for (int i = 0; i < q; ++i) {
        cin >> que[i].a >> que[i].b >> que[i].x;
        --que[i].a, --que[i].b;
        que[i].ind = i;
        if (que[i].a == que[i].b) {
            if (que[i].x >= c[que[i].a]) {
                sol[i] = s[que[i].a];
            }
        }
    }
    dnc(0, n, que);
    for (int i = 0; i < q; ++i) {
        cout << sol[i] << "\n";
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

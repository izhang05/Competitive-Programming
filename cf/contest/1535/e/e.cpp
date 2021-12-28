/* Author: izhang05
 * Time: 12-27-2021 22:10:55
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 3e5 + 5, maxs = 20;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
int up[maxn][maxs], depth[maxn];
vector<int> child[maxn];
int a[maxn], cnt[maxn];

int jmp(int x, int d) {
    for (int i = 0; i < maxs; i++) {
        if ((d >> i) & 1) {
            x = up[x][i];
        }
    }
    return x;
}

void test_case() {
    int q;
    cin >> q >> cnt[0] >> a[0];
    memset(up, -1, sizeof(up));
    for (int i = 1; i <= q; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            int p;
            cin >> p >> cnt[i] >> a[i];
            up[i][0] = p;
            child[p].push_back(i);
            depth[i] = depth[p] + 1;
            for (int j = 1; j < maxs; ++j) {
                if (up[i][j - 1] == -1) {
                    break;
                }
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        } else {
            int v, w;
            cin >> v >> w;
            int cur = v, dist = 0;
            for (int j = maxs - 1; j >= 0; --j) {
                if (up[cur][j] != -1 && cnt[up[cur][j]] != 0) {
                    cur = up[cur][j];
                    dist |= 1 << j;
                }
            }
            pair<int, long long> sol;
            while (w) {
                long long sub = min(w, cnt[cur]);
                cnt[cur] -= sub, w -= sub;
                sol.first += sub;
                sol.second += sub * a[cur];
                if (cur == v) {
                    break;
                }
                cur = jmp(v, --dist);
            }
            cout << sol.first << " " << sol.second << endl;
        }
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
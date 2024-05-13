#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

/**
 * Author: Lukas Polacek
 * Date: 2009-10-26
 * License: CC0
 * Source: folklore
 * Description: Disjoint-set data structure.
 * Time: $O(\alpha(N))$
 */

struct UF {
    vi e;

    UF(int n) : e(n, -1) {}

    bool sameSet(int a, int b) { return find(a) == find(b); }

    int size(int x) { return -e[find(x)]; }

    int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }

    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b];
        e[b] = a;
        return true;
    }
};

int n, m, k;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
vector<vector<long long>> pre;

bool valid(int x, int y, int mid) {
    return x >= 0 && y >= 0 && x + mid - 1 < n && y + mid - 1 < m &&
           pre[x + mid][y + mid] - pre[x + mid][y] - pre[x][y + mid] + pre[x][y] == 0;
}


int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cin >> n >> m >> k;
    vector<vector<int>> b(n, vector<int>(m));
    pre.resize(n + 1);
    for (int i = 0; i <= n; ++i) {
        pre[i].resize(m + 1);
    }
    vector<pair<int, int>> a(k);
    for (auto &i: a) {
        cin >> i.first >> i.second;
        --i.first, --i.second;
        b[i.first][i.second] = true;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            pre[i][j] = b[i - 1][j - 1] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
        }
    }
    int lo = 1, hi = n, mid, sol = -1;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        vector<vector<long long>> cover(n + 2, vector<long long>(m + 2));

        UF dsu(n * m);
        vector<long long> cur;
        for (int i = 0; i + mid - 1 < n; ++i) {
            for (int j = 0; j + mid - 1 < m; ++j) {
                if (valid(i, j, mid)) {
//                    cout << i << " " << j << " " << mid << "\n";
                    ++cover[i + 1][j + 1];
                    --cover[i + 1][j + mid + 1];
                    --cover[i + mid + 1][j + 1];
                    ++cover[i + mid + 1][j + mid + 1];
                    cur.push_back(i * m + j);
                    for (int l = 0; l < 4; ++l) {
                        int nx = i + dx[l], ny = j + dy[l];
                        if (valid(nx, ny, mid)) {
                            dsu.join(i * m + j, nx * m + ny);
                        }
                    }
                }
            }
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cover[i][j] += cover[i - 1][j] + cover[i][j - 1] - cover[i - 1][j - 1];
            }
        }
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < m; ++j) {
//                cout << pre[i + 1][j + 1] << " ";
//            }
//            cout << "\n";
//        }
//        cout << "\n";
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < m; ++j) {
//                cout << cover[i + 1][j + 1] << " ";
//            }
//            cout << "\n";
//        }
        bool good = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!b[i][j] && !cover[i + 1][j + 1]) {
                    good = false;
                }
            }
        }
//        cout << mid << " " << good << "\n";
        for (int i = 1; i < int(cur.size()); ++i) {
            if (!dsu.sameSet(cur[0], cur[i])) {
                good = false;
            }
        }
        if (!good) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
            sol = mid;
        }
    }
    cout << sol << "\n";
}
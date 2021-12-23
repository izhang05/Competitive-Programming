/* Author: izhang05
 * Time: 12-23-2021 13:24:14
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e3 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
char grid[maxn][maxn];
int n, m;
int nxt[maxn * maxn], len[maxn * maxn];
bool visited[maxn * maxn];
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
bool valid(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}
int ind(int x, int y) {
    return x * m + y;
}

map<char, int> d{{'L', 3}, {'R', 1}, {'U', 2}, {'D', 0}};
void test_case() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            int nx = i + dx[d[grid[i][j]]], ny = j + dy[d[grid[i][j]]];
            if (!valid(nx, ny)) {
                nxt[ind(i, j)] = ind(i, j);
            } else {
                nxt[ind(i, j)] = ind(nx, ny);
            }
        }
    }
    for (int i = 0; i < n * m; ++i) {
        visited[i] = false;
        len[i] = -1;
    }
    pair<int, pair<int, int>> sol;
    for (int i = 0; i < n * m; ++i) {
        int cur = i;
        vector<int> past;
        while (!visited[cur]) {
            past.push_back(cur);
            visited[cur] = true;
            cur = nxt[cur];
        }
        if (len[cur] != -1) {
            // hit cycle
            int cur_len = len[cur];
            while (!past.empty()) {
                len[past.back()] = ++cur_len;
                past.pop_back();
            }
        } else {
            int cur_len = -1;
            for (int j = 0; j < int(past.size()); ++j) {
                if (past[j] == cur) {
                    cur_len = int(past.size()) - j;
                    break;
                }
            }
            assert(cur_len != -1);
            bool found = false;
            while (!past.empty()) {
                len[past.back()] = cur_len;
                if (past.back() == cur) {
                    found = true;
                }
                past.pop_back();
                cur_len += found;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            sol = max(sol, {len[ind(i, j)], {i + 1, j + 1}});
        }
    }
    cout << sol.second.first << " " << sol.second.second << " " << sol.first << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}

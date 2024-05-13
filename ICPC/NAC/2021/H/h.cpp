#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int mxn = 1 << 11;

int grid[mxn][mxn];
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int n;

bool valid(int x, int y) {
    return x >= 0 && y >= 0 && x < (1 << n) && y < (1 << n);
}


int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 0; j < (1 << n); ++j) {
            cin >> grid[i][j];
            ++cnt[grid[i][j]];
        }
    }
    if (cnt[0] != 1) {
        cout << 0 << "\n";
        return 0;
    }
    for (auto &i: cnt) {
        if (i.first != 0 && i.second != 3) {
            cout << 0 << "\n";
            return 0;
        }
    }
    set<int> good;
    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 0; j < (1 << n); ++j) {
            set<int> cur;
            for (int k = 0; k < 4; ++k) {
                int nx = i + dx[k], ny = j + dy[k];
                if (valid(nx, ny) && grid[i][j] == grid[nx][ny]) {
                    cur.insert(k);
                }
            }
            if (cur.size() == 2 && *cur.rbegin() - *cur.begin() != 2) {
                good.insert(grid[i][j]);
            }
        }
    }
    for (auto &i: cnt) {
        if (i.first != 0 && good.find(i.first) == good.end()) {
            cout << 0 << "\n";
            return 0;
        }
    }

    cout << 1 << "\n";
}
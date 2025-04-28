#include <bits/stdc++.h>

using namespace std;

#if defined LOCAL || defined DEBUG
#include <debug.h>
#else

struct dbg {
    template<class c>
    dbg &operator<<(const c &) { return *this; }
};

#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#endif

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

const int mxn = 2e3 + 5;

int grid[mxn][mxn], n;

int cost(pair<int, int> cur) {
    int x = cur.first, y = cur.second;
    map<char, int> cnt;
    ++cnt[grid[x][y]];
    ++cnt[grid[x][n - 1 - y]];
    ++cnt[grid[n - 1 - x][y]];
    ++cnt[grid[n - 1 - x][n - 1 - y]];
    if (cnt.size() == 1) {
        return 0;
    }
    if (cnt.begin()->second == 2) {
        return 2;
    }
    return 1;
}

pair<int, int> left(int x, int y) {
    pair<int, int> res{x, y};
    if (x >= n / 2) {
        res.first = n - 1 - x;
    }
    if (y >= n / 2) {
        res.second = n - 1 - y;
    }
    return res;
}

int main() {
    setIO("1");
    int u;
    cin >> n >> u;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j) {
            grid[i][j] = s[j];
        }
    }
    int sol = 0;
    for (int i = 0; i < n / 2; ++i) {
        for (int j = 0; j < n / 2; ++j) {
            sol += cost({i, j});
        }
    }
    cout << sol << "\n";
    for (int i = 0; i < u; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        sol -= cost(left(x, y));
        if (grid[x][y] == '.') {
            grid[x][y] = '#';
        } else {
            grid[x][y] = '.';
        }
        sol += cost(left(x, y));
        cout << sol << "\n";
    }
    return 0;
}

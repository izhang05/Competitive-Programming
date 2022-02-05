/* Author: izhang
 * Time: 01-18-2022 22:55:17
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 105;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
int grid[maxn][maxn];

struct state {
    int x, y, d;
};

int n, l;
map<int, int> x_ind, y_ind;
bool valid(pair<int, int> loc) {
    return loc.first >= 0 && loc.second >= 0 && loc.first < (int) x_ind.size() && loc.second < (int) y_ind.size();
}
void test_case() {
    cin >> n >> l;
    vector<state> a(n);
    set<int> xs, ys;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y >> a[i].d;
        xs.insert(a[i].x);
        ys.insert(a[i].y);
    }
    xs.insert(1), ys.insert(1);
    xs.insert(l), ys.insert(l);
    int cur = 0;
    for (auto &i : xs) {
        x_ind[i] = cur++;
    }
    cur = 0;
    for (auto &i : ys) {
        y_ind[i] = cur++;
    }
    for (auto &i : a) {
        i.x = x_ind[i.x];
        i.y = y_ind[i.y];
        grid[i.x][i.y] = i.d;
    }
    int dx = 0, dy = 1;
    pair<int, int> loc{0, 0};
    while (valid(loc)) {
        if (grid[loc.first][loc.second] == 1) {
            swap(dx, dy);
        } else if (grid[loc.first][loc.second] == 2) {
            swap(dx, dy);
            dx *= -1, dy *= -1;
        }
        loc.first += dx, loc.second += dy;
    }
    pair<int, int> sol;
    for (auto &i : x_ind) {
        if (i.second == loc.first - dx) {
            sol.first = i.first;
            break;
        }
    }
    for (auto &i : y_ind) {
        if (i.second == loc.second - dy) {
            sol.second = i.first;
            break;
        }
    }
    cout << sol.first << " " << sol.second << " " << (dx != 0 ? 1 : 0) << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}

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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
bool grid[205][205];

int correct(int r) {
    int cnt = 0;
    for (int i = -r; i <= r; ++i) {
        for (int j = -r; j <= r; ++j) {
            if (round(sqrt(i * i + j * j)) <= r) {
                ++cnt;
            }
        }
    }
    return cnt;
}
map<pair<int, int>, int> occ;
int off = 100;
void perim(int r) {
    for (int i = -r; i <= r; ++i) {
        int y = round(sqrt(r * r - i * i));
        grid[i + off][y + off] = true;
        grid[i + off][-y + off] = true;
        grid[y + off][i + off] = true;
        grid[-y + off][i + off] = true;
        ++occ[{i, y}];
        ++occ[{i, -y}];
        ++occ[{y, i}];
        ++occ[{-y, i}];
    }
}

int wrong(int r) {
    occ.clear();
    for (int i = 0; i <= r; ++i) {
        perim(i);
    }
    return occ.size();
}

void test_case() {
    int r;
    cin >> r;
    cout << correct(r) - wrong(r) << "\n";
}

int main() {
    setIO("1");
    wrong(off);
    for (int i = 0; i <= 2 * off; ++i) {
        for (int j = 0; j < 2 * off; ++j) {
            cout << grid[i][j];
        }
        cout << "\n";
    }
    return 0;
    int test_case_number = 1;
    cin >> test_case_number;
    for (int i = 1; i <= test_case_number; ++i) {
        dbg() << imie(i);
        cout << "Case #" << i << ": ";
        test_case();
    }
}

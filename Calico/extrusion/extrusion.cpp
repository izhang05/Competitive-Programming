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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 4000;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
char grid[maxn][maxn];

void solve(int h, int w, int d, vector<vector<char>> base) {
    for (int i = 0; i < h + d + 1; ++i) {
        for (int j = 0; j < w + d + 1; ++j) {
            grid[i][j] = ' ';
        }
    }
    vector<pair<int, int>> vertex;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            grid[i][j] = base[i][j];
            if (base[i][j] == '+') {
                vertex.emplace_back(i, j);
            }
        }
    }
    for (int i = 1; i <= d; ++i) {
        for (auto &j: vertex) {
            grid[j.first + i][j.second + i] = '\\';
        }
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (base[i][j] != ' ') {
                grid[i + d + 1][j + d + 1] = base[i][j];
            }
        }
    }
    for (int i = 0; i < h + d + 1; ++i) {
        for (int j = 0; j < w + d + 1; ++j) {
            cout << grid[i][j];
        }
        cout << "\n";
    }
}

int main() {
    setIO("1");
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int H, W, D;
        cin >> H >> W >> D;
        vector<vector<char>> base(H);
        cin.ignore();
        for (int j = 0; j < H; j++) {
            string temp;
            getline(cin, temp);
            vector<char> row(temp.begin(), temp.end());
            while ((int)& row.size() < W) {
                row.push_back(' ');
            }
            base[j] = row;
        }
        solve(H, W, D, base);
    }
}
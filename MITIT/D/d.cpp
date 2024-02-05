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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 2e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
vector<int> adj[mxn];
int dp[mxn];

int dfs(int c, int p) {
//    dbg() << c << " " << color << " " << p_c;
//    cout << c << "\n";
    int &cur = dp[c];
    if (cur != -1) {
        return cur;
    }
    cur = 0;
    if (color == 1) {
        for (auto &i: adj[c]) {
            if (i != p) {
                cur += max(dfs(i, c, 0, 1), dfs(i, c, 1, 1));
            }
        }
    } else {
        cur = 1;
        vector<int> diff;
        for (auto &i: adj[c]) {
            if (i != p) {
                cur += dfs(i, c, 0, 0) - 1;
                diff.push_back(dfs(i, c, 1, 0) - dfs(i, c, 0, 0) + 1);
            }
        }
        sort(diff.begin(), diff.end());
        reverse(diff.begin(), diff.end());
        if ((int) diff.size() >= 1) {
            cur += max(0, diff[0]);
            if (int(diff.size() >= 2) && p_c == 0) {
                cur += max(0, diff[1]);
            }
        }
    }
//    dbg() << c << " " << color << " " << p_c << " " << cur;
    return cur;
}


void test_case() {
    int n;
    cin >> n;
    for (int i = 0; i < n + 1; ++i) {
        adj[i].clear();
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                dp[i][j][k] = -1;
            }
        }
    }
//    cout << n << "\n";
    for (int i = 1; i < n + 1; ++i) {
        int p;
        cin >> p;
        --p;
        adj[i].push_back(p);
        adj[p].push_back(i);
//        cout << i << " " << p << "\n";
    }
    cout << max(dfs(0, -1, 0, 0), dfs(0, -1, 1, 0)) << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1, x;
    cin >> test_case_number >> x;
    while (test_case_number--) {
        test_case();
//        dbg();
    }
    return 0;
}

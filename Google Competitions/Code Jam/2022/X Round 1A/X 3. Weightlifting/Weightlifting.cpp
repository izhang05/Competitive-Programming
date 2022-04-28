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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 11;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
map<string, int> dp[maxn];
vector<string> pos;

int cost(const string &a, const string &b) {
    int n = int(a.size()), m = int(b.size());
    for (int i = 0; i < min(n, m); ++i) {
        if (a[i] != b[i]) {
            return n - i + m - i;
        }
    }
    return abs(m - n);
}

void gen(int a, int b, int c, string s) {
    if (a == 0 && b == 0 && c == 0) {
        pos.push_back(s);
        return;
    }
    if (a) {
        s.push_back('0');
        gen(a - 1, b, c, s);
        s.pop_back();
    }
    if (b) {
        s.push_back('1');
        gen(a, b - 1, c, s);
        s.pop_back();
    }
    if (c) {
        s.push_back('2');
        gen(a, b, c - 1, s);
        s.pop_back();
    }
}

void test_case() {
    int n, w;
    cin >> n >> w;
    for (int i = 0; i <= n; ++i) {
        dp[i].clear();
    }
    vector<int> cur(w);
    for (int i = 0; i < w; ++i) {
        cin >> cur[i];
    }
    pos.clear();
    gen(cur[0], cur[1], cur[2], "");
    for (auto &i : pos) {
        dp[0][i] = cur[0] + cur[1] + cur[2];
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> cur[j];
        }
        pos.clear();
        gen(cur[0], cur[1], cur[2], "");
        for (auto &j : pos) {
            int cur_cost = inf;
            for (auto &k : dp[i - 1]) {
                cur_cost = min(cur_cost, k.second + cost(k.first, j));
            }
            dp[i][j] = cur_cost;
        }
    }
    int sol = inf;
    for (auto &i : dp[n - 1]) {
        sol = min(sol, i.second);
    }
    cout << sol + cur[0] + cur[1] + cur[2] << "\n";
}

int main() {
    setIO("1");
    int test_case_number = 1;
    cin >> test_case_number;
    for (int i = 1; i <= test_case_number; ++i) {
        dbg() << imie(i);
        cout << "Case #" << i << ": ";
        test_case();
    }
}

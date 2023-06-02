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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

void test_case() {
    long long n, p;
    cin >> n >> p;
    vector<long long> c(10), r(n);
    for (int i = 0; i < n; ++i) {
        char s;
        cin >> s >> r[i];
    }
    for (int i = 0; i < 10; ++i) {
        cin >> c[i];
    }
    vector<vector<long long>> cost(10, vector<long long>(10)); // cost[i][j] = cost to split digit i into j partitions
    for (int i = 0; i < 10; ++i) {
        cost[i][1] = c[i] + p;
    }
    for (int j = 2; j < 10; ++j) {
        for (int i = 0; i < 10; ++i) {
            cost[i][j] = cost[i][j - 1];
            for (int k = 0; k < i; ++k) {
                cost[i][j] = min(cost[i][j], cost[k][j - 1] + c[i - k] + p);
            }
        }
    }
    dbg() << cost;
    long long sol = 0;
    for (auto &i: r) {
        long long mn = INFL;
        vector<int> digits;
        while (i) {
            digits.push_back(int(i % 10));
            i /= 10;
        }
        dbg() << digits;
        for (int j = 1; j < 10; ++j) {
            long long cur = 0;
            for (auto &k: digits) {
                cur += cost[k][j];
            }
            mn = min(mn, cur);
        }
        sol += mn;
    }
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}

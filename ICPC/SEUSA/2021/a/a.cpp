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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 22;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

long double dp[1 << mxn];

void test_case() {
    int n;
    cin >> n;
    vector<long double> a(n);
    for (auto &i: a) {
        cin >> i;
    }
    for (int i = 1; i < (1 << n); ++i) {
        if (__builtin_popcount(i) <= 2) {
            continue;
        }
        vector<int> cur;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                cur.push_back(j);
            }
        }
        long double same = 0, white = 1;
        for (auto &j: cur) {
            white *= a[j];
        }
        same += white;
        long double black = 1;
        for (auto &j: cur) {
            black *= 1 - a[j];
        }
        same += black;
        dp[i] = 1;
        long double sum = 0;
        for (auto &j: cur) {
            long double cur_prob = white / a[j] * (1 - a[j]) + black / (1 - a[j]) * a[j];
            sum += cur_prob;
            dp[i] += cur_prob * dp[i ^ (1 << j)];
        }
        dp[i] /= sum;
    }
    cout << fixed << setprecision(16) << dp[(1 << n) - 1] << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}

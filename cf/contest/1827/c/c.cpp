/* Author: izhang
 * Time: 05-25-2023 21:31:04
**/
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

namespace kactl {
#define rep(i, from, to) for (int(i) = from; (i) < (to); ++(i))
#define all(x) x.begin(), (x).end()
#define sz(x) (int) (x).size()
    typedef long long ll;
    typedef pair<int, int> pii;
    typedef vector<int> vi;
    /**
     * Author: Simon Lindholm
     * Date: 2015-03-15
     * License: CC0
     * Source: own work
     * Description: Various self-explanatory methods for string hashing.
     * Use on Codeforces, which lacks 64-bit support and where solutions can be hacked.
     * Status: stress-tested
     */

    typedef uint64_t ull;
    static int C; // initialized below

    // Arithmetic mod two primes and 2^32 simultaneously.
    // "typedef uint64_t H;" instead if Thue-Morse does not apply.
    template<int M, class B>
    struct A {
        int x;
        B b;
        A(int x = 0) : x(x), b(x) {}
        A(int x, B b) : x(x), b(b) {}
        A operator+(A o) {
            int y = x + o.x;
            return {y - (y >= M) * M, b + o.b};
        }
        A operator-(A o) {
            int y = x - o.x;
            return {y + (y < 0) * M, b - o.b};
        }
        A operator*(A o) { return {(int) (1LL * x * o.x % M), b * o.b}; }
        explicit operator ull() { return x ^ (ull) b << 21; }
    };
    //    typedef A<1000000007, A<1000000009, unsigned>> H;
    typedef uint64_t H;
    struct HashInterval {
        vector<H> ha, pw;
        HashInterval(string &str) : ha(sz(str) + 1), pw(ha) {
            pw[0] = 1;
            rep(i, 0, sz(str))
                    ha[i + 1] = ha[i] * C + str[i],
                           pw[i + 1] = pw[i] * C;
        }
        H hashInterval(int a, int b) { // hash [a, b)
            return ha[b] - ha[a] * pw[b - a];
        }
    };

    vector<H> getHashes(string &str, int length) {
        if (sz(str) < length) return {};
        H h = 0, pw = 1;
        rep(i, 0, length)
                h = h * C + str[i],
                pw = pw * C;
        vector<H> ret = {h};
        rep(i, length, sz(str)) {
            ret.push_back(h = h * C + str[i] - pw * str[i - length]);
        }
        return ret;
    }

    H hashString(string &s) {
        H h{};
        for (char c : s) h = h * C + c;
        return h;
    }

#include <sys/time.h>
    int main() {
        timeval tp;
        gettimeofday(&tp, nullptr);
        C = (int) tp.tv_usec; // (less than modulo)
        assert((ull) (H(1) * 2 + 1 - 3) == 0);
        return 0;
    }
} // namespace kactl
//using namespace kactl;

void test_case() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string s_rev = s;
    reverse(s_rev.begin(), s_rev.end());
    dbg() << s << " " << s_rev;
    kactl::HashInterval forward(s), backward(s_rev);
    long long sol = 0;
    vector<unordered_map<unsigned long long, long long>> occ(2);
    vector<int> furthest(n); // furthest[i] = j -> [i, j) is the right side of a palindrome
    for (int i = 0; i < n; ++i) {
        int lo = i, hi = n, mid, res = i;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            int left = n - (i - (mid - i));
            if (left > n) {
                hi = mid - 1;
                continue;
            }
            if (forward.hashInterval(i, mid) == backward.hashInterval(n - i, left)) {
                res = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        furthest[i] = res;
    }
    dbg() << furthest;
    set<pair<int, long long>> mx;
    vector<long long> dp(n + 1, 1);
    for (int i = 0; i < n; ++i) {
        while (!mx.empty() && furthest[i] >= mx.begin()->first) {
            mx.erase(mx.begin());
        }
        mx.insert({furthest[i], i});
        dbg() << i;
        dbg() << mx;
        auto it = mx.lower_bound({i, INFL});
        dbg() << *it << " " << it->second - (i - it->second + 1);
        if (it != mx.end()) {
            dp[i + 1] += dp[it->second - (i - it->second + 1)];
        }
        sol += dp[i + 1] - 1;
    }
    dbg() << dp;
    cout << sol << "\n";
}

int main() {
    setIO("1");
    kactl::main();
    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
        dbg();
    }
    return 0;
}

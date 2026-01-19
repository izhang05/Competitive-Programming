/* Author: izhang
 * Time: 10-19-2025 11:58:29
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

namespace kactl {
#define rep(i, from, to) for (long long(i) = from; (i) < (to); ++(i))
#define all(x) x.begin(), (x).end()
#define sz(x) (long long) (x).size()
    typedef long long ll;
    typedef pair<long long, long long> pii;
    typedef vector<long long> vi;

/**
 * Author: Unknown
 * Date: 2002-09-15
 * Source: predates tinyKACTL
 * Description: Finds two long longegers  and , such that $ax+by=\gcd(a,b)$. If
 * you just need gcd, use the built in \texttt{\_\_gcd} instead.
 * If  and  are coprime, then  is the inverse of $a \pmod{b}$.
 */

    ll euclid(ll a, ll b, ll &x, ll &y) {
        if (!b) return x = 1, y = 0, a;
        ll d = euclid(b, a % b, y, x);
        return y -= a / b * x, d;
    }

    /**
     * Author: Simon Lindholm
     * Date: 2019-05-22
     * License: CC0
     * Description: Chinese Remainder Theorem.
     *
     * \texttt{crt(a, m, b, n)} computes  such that $x\equiv a \pmod m$, $x\equiv b \pmod n$.
     * If $|a| < m$ and $|b| < n$,  will obey $0 \le x < \text{lcm}(m, n)$.
     * Assumes $mn < 2^{62}$.
     * Time: $\log(n)$
     * Status: Works
     */

    ll crt(ll a, ll m, ll b, ll n) {
        if (n > m) swap(a, b), swap(m, n);
        ll x, y, g = euclid(m, n, x, y);
        assert((a - b) % g == 0); // else no solution
        x = (b - a) % n * x % n / g * m + a;
        return x < 0 ? x + m * n / g : x;
    }

}
//using namespace kactl;

const long long inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
long long m;
long long sol = INFL;
vector<pair<long long, vector<long long>>> nums;

long long get_num(long long a, long long o, long long b, long long n) {
    long long cur_num = kactl::crt(a, o, b, n);
    long long cur_prod = o * n;

    cur_num %= cur_prod;
    long long da = a / cur_prod, db = b / cur_prod;
    cur_num += cur_prod * max(da, db);
    while (cur_num < a || cur_num < b) {
        cur_num += cur_prod;
    }
    return cur_num;
}

void gen(vector<long long> cnt) {

}


void test_case() {
    long long n;
    cin >> n;
    map<long long, map<long long, int>> val;
    map<pair<long long, long long>, long long> biggest;
    for (long long i = 0; i < n; ++i) {
        long long x, d;
        cin >> x >> d;
        ++val[d][x % d];
        biggest[{d, x % d}] = max(biggest[{d, x % d}], x);
    }
    int total_number = 0;
    for (auto &i: val) {
        int mx = 0;
        for (auto &j: i.second) {
            mx = max(mx, j.second);
        }
        nums.push_back({i.first, vector<long long>{}});
        for (auto &j: i.second) {
            if (j.second == mx) {
                nums.back().second.push_back(biggest[{i.first, j.first}]);
            }
        }
        total_number += mx;
    }
    m = val.size();

    if (m == 1) {
        sort(nums[0].second.begin(), nums[0].second.end());
        cout << nums[0].second[0] << " " << total_number << "\n";
        return;
    }

    vector<long long> cnt(m);

    while (true) {
        long long cur_num = get_num(nums[0].second[cnt[0]], nums[0].first, nums[1].second[cnt[1]], nums[1].first);
        long long cur_prod = nums[0].first * nums[1].first;
//    cout << "\n";
//        for (auto &i: cnt) {
//            cout << i << " ";
//        }
//        cout << "\n";
//    cout << "\n";
//    cout << cur_num << " " << cur_prod << "\n";
        for (long long i = 2; i < m; ++i) {
            cur_num = get_num(cur_num, cur_prod, nums[i].second[cnt[i]], nums[i].first);
            cur_prod *= nums[i].first;
        }
        sol = min(sol, cur_num);

        bool found = false;
        for (long long ind = m - 1; ind >= 0; --ind) {
            if (cnt[ind] + 1 < (long long) nums[ind].second.size()) {
                ++cnt[ind];
                found = true;
                break;
            } else {
                cnt[ind] = 0;
            }
        }
        if (!found) {
            break;
        }
    }

//    gen(cnt);
    cout << sol << " " << total_number << "\n";
}

int main() {
    setIO("1");

    long long test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}

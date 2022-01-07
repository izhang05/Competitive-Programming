/* Author: izhang
 * Time: 01-06-2022 11:08:44
**/
#include <bits/stdc++.h>

#include <random>

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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long rnd(long long l, long long r) {
    return uniform_int_distribution<long long>(l, r)(rng);
}
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
const long double PI = acos((long double) -1);
struct chash {                                       /// use most bits rather than just the lowest ones
    const uint64_t C = (long long) (2e18 * PI) + 71; // large odd number
    const int RANDOM = rng();
    long long operator()(long long x) const { /// https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
        return __builtin_bswap64((x ^ RANDOM) * C);
    }
};
long long binpow(long long x, long long n, long long m) {
    assert(n >= 0);
    x %= m;
    long long res = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            res = res * x % m;
        }
        x = x * x % m;
        n /= 2;
    }
    return res;
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
int u, v, p;
gp_hash_table<int, vector<int>, chash> occ;
int num;
void add() {
    ++num;
    if (num >= p) {
        num -= p;
    }
}
void sub() {
    --num;
    if (num < 0) {
        num += p;
    }
}
void inv() {
    num = binpow(num, p - 2, p);
}
void (*op[])() = {add, sub, inv};

void (*inv_op[])() = {sub, add, inv};

void test_case() {
    cin >> u >> v >> p;
    for (int i = 0; i < 5e4; ++i) {
        vector<int> cur(100);
        num = u;
        for (int j = 0; j < 100; ++j) {
            cur[j] = rnd(0, 2);
            op[cur[j]]();
        }
        occ[num] = cur;
    }
    while (true) {
        vector<int> cur(100);
        num = v;
        for (int j = 0; j < 100; ++j) {
            cur[j] = rnd(0, 2);
            inv_op[cur[j]]();
        }
        if (occ.find(num) != occ.end()) {
            cout << occ[num].size() + cur.size() << "\n";
            for (auto &i : occ[num]) {
                cout << i + 1 << " ";
            }
            reverse(cur.begin(), cur.end());
            for (auto &i : cur) {
                cout << i + 1 << " ";
            }
            cout << "\n";
            return;
        }
    }
}

int main() {
    setIO("3");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}

// left side row 3 Duke
#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

const long long mod = 998244353;

ull modmul(ull a, ull b, ull M) {
    ll ret = a * b - M * ull(1.L / M * a * b);
    return ret + M * (ret < 0) - M * (ret >= (ll) M);
}

ull modpow(ull b, ull e, ull mod) {
    ull ans = 1;
    for (; e; b = modmul(b, b, mod), e /= 2)
        if (e & 1) ans = modmul(ans, b, mod);
    return ans;
}

ull pollard(ull n) {
    auto f = [n](ull x) { return modmul(x, x, n) + 1; };
    ull x = 0, y = 0, t = 30, prd = 2, i = 1, q;
    while (t++ % 40 || __gcd(prd, n) == 1) {
        if (x == y) x = ++i, y = f(x);
        if ((q = modmul(prd, max(x, y) - min(x, y), n))) prd = q;
        x = f(x), y = f(f(y));
    }
    return __gcd(prd, n);
}

bool isPrime(ull n) {
    if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
    ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
            s = __builtin_ctzll(n - 1), d = n >> s;
    for (ull a: A) {
        ull p = modpow(a % n, d, n), i = s;
        while (p != 1 && p != n - 1 && a % n && i--) p = modmul(p, p, n);
        if (p != n - 1 && i != s) return 0;
    }
    return 1;
}

vector<ull> factor(ull n) {
    if (n == 1) return {};
    if (isPrime(n)) return {n};
    ull x = pollard(n);
    auto l = factor(x), r = factor(n / x);
    l.insert(l.end(), all(r));
    return l;
}

map<vector<int>, ull> mem;

ull b(vector<int> &fact) {
    if (mem.find(fact) != mem.end()) {
        return mem[fact];
    }
    ull res = 0;
//    vector<ull> cur_primes;
//    for (auto &i: fact) {
//        cur_primes.push_back(i.first);
//    }
    int cnt = int(fact.size());
//    cout << "cnt: ";
//    for (int i = 0; i < cnt; ++i) {
//        cout << fact[i] << " ";
//    }
//    cout << "\n";
    for (long long i = 0; i < (1ll << cnt); ++i) {
//        ull cur = 1;
        int num_factors = 0;
        for (int j = 0; j < cnt; ++j) {
            if ((1ll << j) & i) {
//                cur *= cur_primes[j];
                --fact[j];
                ++num_factors;
            }
        }
        // cur = k/d
        ull mobius = 1;
        if (num_factors % 2 == 1) {
            mobius *= -1;
        }
        mobius = (mobius + mod) % mod;
        ull tau = 1;
        for (auto &j: fact) {
            tau = modmul(tau, j + 1, mod);
        }
        ull a_k = (modpow(2, tau, mod) - 1 + mod) % mod;
//        cout << "tau: " << i << " " << tau << " " << a_k << "\n";
        res += modmul(mobius, a_k, mod);
        res %= mod;
        res = (res + mod) % mod;
//        cout << res << "\n";
        for (int j = 0; j < cnt; ++j) {
            if ((1ll << j) & i) {
//                cur *= cur_primes[j];
                ++fact[j];
            }
        }
    }
//    cout << k << " " << res << "\n";
//    for (auto &i: fact) {
//        cout << i.first << " " << i.second << "\n";
//    }
//    cout << "\n";
//    cout << res << "\n";
    mem[fact] = res;
    return res % mod;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    ull m;
    cin >> m;
    vector<ull> f = factor(m);
    unordered_map<ull, int> fact;
    for (auto i: f) {
        ++fact[i];
    }
    vector<ull> cur_primes;
    for (auto &i: fact) {
        cur_primes.push_back(i.first);
    }
    int cnt = int(fact.size());
    ull sol = 0;
    for (long long i = 0; i < (1ll << cnt); ++i) {
//        ull cur = 1;
        int num_factors = 0;
        vector<int> degrees;
        for (int j = 0; j < cnt; ++j) {
            if ((1ll << j) & i) {
                ++num_factors;
//                cur *= cur_primes[j];
//                --fact[cur_primes[j]];
                if (fact[cur_primes[j]] != 1) {
//                    fact.erase(cur_primes[j]);
//                } else {
                    degrees.push_back(fact[cur_primes[j]] - 1);
                }
            } else {
                degrees.push_back(fact[cur_primes[j]]);
            }
        }
//        cout << "degrees: " << i << " ";
//        for (auto &j: degrees) {
//            cout << j << " ";
//        }
//        cout << "\n";
        // cur = k/d
        ull mobius = 1;
        if (num_factors % 2 == 1) {
            mobius *= -1;
        }
        mobius = (mobius + mod) % mod;
//        cout << i << "\n\n";
        sort(degrees.begin(), degrees.end());
        sol += modmul(mobius, b(degrees), mod);
        sol %= mod;
        sol = (sol + mod) % mod;
//        for (int j = 0; j < cnt; ++j) {
//            if ((1ll << j) & i) {
//                ++fact[cur_primes[j]];
//            }
//        }
    }
    cout << sol << "\n";
}

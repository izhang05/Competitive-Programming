//////#include<bits/stdc++.h>
//////
////////#pragma GCC optimize("O3,unroll-loops")
////////#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
////////#pragma GCC optimize "-Ofast"
////////#pragma GCC optimize "-funroll-loops"
//////
//////using namespace std;
//////
//////#define rep(i, a, b) for(int i = a; i < (b); ++i)
//////#define all(x) begin(x), end(x)
//////#define sz(x) (int)(x).size()
//////typedef long long ll;
//////typedef pair<int, int> pii;
//////typedef vector<int> vi;
//////
//////typedef unsigned long long ull;
//////
////////ull modmul(ull a, ull b, ull M) {
////////    ll ret = a * b - M * ull(1.L / M * a * b);
////////    return ret + M * (ret < 0) - M * (ret >= (ll) M);
////////}
//////
//////ull modmul(ull a, ull b, ull M) {
//////    return (__int128) a * b % M;
//////    ll ret = a * b - M * ull(1.L / M * a * b);
//////    return ret + M * (ret < 0) - M * (ret >= (ll) M);
//////}
//////
//////ull modpow(ull b, ull e, ull mod) {
//////    ull ans = 1;
//////    for (; e; b = modmul(b, b, mod), e /= 2)
//////        if (e & 1) ans = modmul(ans, b, mod);
//////    return ans;
//////}
//////
//////bool isPrime(ull n) {
//////    if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
//////    ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
//////            s = __builtin_ctzll(n - 1), d = n >> s;
//////    for (ull a: A) {
//////        ull p = modpow(a % n, d, n), i = s;
//////        while (p != 1 && p != n - 1 && a % n && i--)
//////            p = modmul(p, p, n);
//////        if (p != n - 1 && i != s) return 0;
//////    }
//////    return 1;
//////}
//////
//////ull pollard(ull n) {
//////    auto f = [n](ull x) { return modmul(x, x, n) + 1; };
//////    ull x = 0, y = 0, t = 30, prd = 2, i = 1, q;
//////    while (t++ % 40 || __gcd(prd, n) == 1) {
//////        if (x == y) x = ++i, y = f(x);
//////        if ((q = modmul(prd, max(x, y) - min(x, y), n))) prd = q;
//////        x = f(x), y = f(f(y));
//////    }
//////    return __gcd(prd, n);
//////}
//////
//////vector<ull> factor(ull n) {
//////    if (n == 1) return {};
//////    if (isPrime(n)) return {n};
//////    ull x = pollard(n);
//////    auto l = factor(x), r = factor(n / x);
//////    l.insert(l.end(), all(r));
//////    return l;
//////}
//////
//////bool pos(ull x) {
//////    while (x % 2 == 0) {
//////        x /= 2;
//////    }
//////    if (x == 0 || x == 1) {
//////        return true;
//////    }
//////    vector<ull> f = factor(x);
//////
//////
//////
////////    map<ull, int> cnt;
////////    for (auto &i: f) {
////////        ++cnt[i];
////////    }
////////    for (auto &i: cnt) {
////////        if (i.first % 4 == 3 && i.second % 2 == 1) {
////////            return false;
////////        }
////////    }
//////
//////    sort(f.begin(), f.end());
//////    int m = int(f.size());
//////    int i = 0;
//////    if (f[i] % 4 == 1) {
//////        ++i;
//////    }
//////    for (int j = 1; j < m; ++j) {
//////        if (f[j] != f[i]) {
//////            if ((j - i) % 2 == 1) {
//////                return false;
//////            }
//////            i = j;
//////        }
//////        if (f[i] % 4 == 1) {
//////            i = j + 1;
//////        }
//////    }
//////    return true;
//////}
//////
//////map<ll, ll> squares;
//////
//////mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//////
//////long long rnd(long long l, long long r) { // [l, r]
//////    return uniform_int_distribution<long long>(l, r)(rng);
//////}
//////
//////int main() {
//////    cin.tie(0)->sync_with_stdio(0);
////////    cout << (ll)999996 * 999996 + 1298*1298 + 2513 * 2513;
//////
//////    for (ll i = 0; i * i <= (ll) 1e12; ++i) {
//////        squares[i * i] = i;
//////    }
//////    ll n;
//////    cin >> n;
//////    ll mul_pow = 1;
//////    while (n % 4 == 0) {
//////        n /= 4;
//////        mul_pow *= 2;
//////    }
//////    if (n % 8 == 7) {
//////        cout << -1 << "\n";
//////        return 0;
//////    }
//////    ll mx = 0;
//////    for (; mx * mx <= n; ++mx) {}
//////    --mx;
////////    vector<long long> nums(mx + 1);
////////    for (int i = 0; i <= mx; ++i) {
////////        nums[i] = i;
////////    }
////////    reverse(nums.begin(), nums.end());
////////    shuffle(nums.begin(), nums.end(), rng);
////////    cout << mx << " " << mx * mx << "\n";
//////
//////    for (long long j = mx;; --j) {
//////        ll rest = n - j * j;
//////        if (pos(rest)) {
//////            for (ll i = 0; j * j <= rest; ++i) {
//////                if (squares.find(rest - i * i) != squares.end()) {
//////                    cout << j * mul_pow << " " << i * mul_pow << " " << squares[rest - i * i] * mul_pow << "\n";
//////                    return 0;
//////                }
//////            }
//////        }
//////    }
//////}
////
////#include<bits/stdc++.h>
////
////#pragma GCC optimize("O3,unroll-loops")
////#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
////
////
////using namespace std;
////
////#define rep(i, a, b) for(int i = a; i < (b); ++i)
////#define all(x) begin(x), end(x)
////#define sz(x) (int)(x).size()
////typedef long long ll;
////typedef pair<int, int> pii;
////typedef vector<int> vi;
////
////typedef unsigned long long ull;
////
////ull modmul(ull a, ull b, ull M) {
////    ll ret = a * b - M * ull(1.L / M * a * b);
////    return ret + M * (ret < 0) - M * (ret >= (ll) M);
////}
////
//////ull modmul(ull a, ull b, ull M) {
//////    return (__int128) a * b % M;
//////    ll ret = a * b - M * ull(1.L / M * a * b);
//////    return ret + M * (ret < 0) - M * (ret >= (ll) M);
//////}
////
////ull modpow(ull b, ull e, ull mod) {
////    ull ans = 1;
////    for (; e; b = modmul(b, b, mod), e /= 2)
////        if (e & 1) ans = modmul(ans, b, mod);
////    return ans;
////}
////
////bool isPrime(ull n) {
////    if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
////    ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
////            s = __builtin_ctzll(n - 1), d = n >> s;
////    for (ull a: A) {
////        ull p = modpow(a % n, d, n), i = s;
////        while (p != 1 && p != n - 1 && a % n && i--)
////            p = modmul(p, p, n);
////        if (p != n - 1 && i != s) return 0;
////    }
////    return 1;
////}
////
////ull pollard(ull n) {
////    auto f = [n](ull x) { return modmul(x, x, n) + 1; };
////    ull x = 0, y = 0, t = 30, prd = 2, i = 1, q;
////    while (t++ % 40 || __gcd(prd, n) == 1) {
////        if (x == y) x = ++i, y = f(x);
////        if ((q = modmul(prd, max(x, y) - min(x, y), n))) prd = q;
////        x = f(x), y = f(f(y));
////    }
////    return __gcd(prd, n);
////}
////
////vector<ull> factor(ull n) {
////    if (n == 1) return {};
////    if (isPrime(n)) return {n};
////    ull x = pollard(n);
////    auto l = factor(x), r = factor(n / x);
////    l.insert(l.end(), all(r));
////    return l;
////}
////
////bool pos(ull x) {
////    while (x % 2 == 0) {
////        x /= 2;
////    }
////    if (x == 0 || x == 1) {
////        return true;
////    }
////    vector<ull> f = factor(x);
////    sort(f.begin(), f.end());
////    int m = int(f.size());
////    int i = 0;
////    if (f[i] % 4 == 1) {
////        ++i;
////    }
////    for (int j = 1; j < m; ++j) {
////        if (f[j] != f[i]) {
////            if ((j - i) % 2 == 1) {
////                return false;
////            }
////            i = j;
////        }
////        if (f[i] % 4 == 1) {
////            i = j + 1;
////        }
////    }
////    return true;
////}
////
////map<ll, ll> squares;
////
////mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
////
////long long rnd(long long l, long long r) { // [l, r]
////    return uniform_int_distribution<long long>(l, r)(rng);
////}
////
////int main() {
////    cin.tie(0)->sync_with_stdio(0);
//////    cout << (ll)999996 * 999996 + 1298*1298 + 2513 * 2513;
////
////    for (ll i = 0; i * i <= (ll) 1e12; ++i) {
////        squares[i * i] = i;
////    }
////    ll n;
////    cin >> n;
////    ll mul_pow = 1;
////    while (n % 4 == 0) {
////        n /= 4;
////        mul_pow *= 2;
////    }
////    if (n % 8 == 7) {
////        cout << -1 << "\n";
////        return 0;
////    }
////    ll mx = 0;
////    for (; mx * mx <= n; ++mx) {}
////    --mx;
////    vector<long long> nums(mx + 1);
////    for (int i = 0; i <= mx; ++i) {
////        nums[i] = i;
////    }
//////    reverse(nums.begin(), nums.end());
////    shuffle(nums.begin(), nums.end(), rng);
//////    cout << mx << " " << mx * mx << "\n";
////    for (auto &j: nums) {
////        ll rest = n - j * j;
////        if (pos(rest)) {
////            for (ll i = 0; j * j <= rest; ++i) {
////                if (squares.find(rest - i * i) != squares.end()) {
////                    cout << j * mul_pow << " " << i * mul_pow << " " << squares[rest - i * i] * mul_pow << "\n";
////                    return 0;
////                }
////            }
////        }
////    }
////}
//
//
//
//
//
//
//#include<bits/stdc++.h>
//
////#pragma GCC optimize("O3,unroll-loops")
////#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
////#pragma GCC optimize "-Ofast"
////#pragma GCC optimize "-funroll-loops"
//
//using namespace std;
//
//#define rep(i, a, b) for(int i = a; i < (b); ++i)
//#define all(x) begin(x), end(x)
//#define sz(x) (int)(x).size()
//typedef long long ll;
//typedef pair<int, int> pii;
//typedef vector<int> vi;
//
//typedef unsigned long long ull;
//
//ull modmul(ull a, ull b, ull M) {
//    ll ret = a * b - M * ull(1.L / M * a * b);
//    return ret + M * (ret < 0) - M * (ret >= (ll) M);
//}
//
////ull modmul(ull a, ull b, ull M) {
////    return (__int128) a * b % M;
////    ll ret = a * b - M * ull(1.L / M * a * b);
////    return ret + M * (ret < 0) - M * (ret >= (ll) M);
////}
//
//ull modpow(ull b, ull e, ull mod) {
//    ull ans = 1;
//    for (; e; b = modmul(b, b, mod), e /= 2)
//        if (e & 1) ans = modmul(ans, b, mod);
//    return ans;
//}
//
//bool isPrime(ull n) {
//    if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
//    ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
//            s = __builtin_ctzll(n - 1), d = n >> s;
//    for (ull a: A) {
//        ull p = modpow(a % n, d, n), i = s;
//        while (p != 1 && p != n - 1 && a % n && i--)
//            p = modmul(p, p, n);
//        if (p != n - 1 && i != s) return 0;
//    }
//    return 1;
//}
//
//ull pollard(ull n) {
//    auto f = [n](ull x) { return modmul(x, x, n) + 1; };
//    ull x = 0, y = 0, t = 30, prd = 2, i = 1, q;
//    while (t++ % 40 || __gcd(prd, n) == 1) {
//        if (x == y) x = ++i, y = f(x);
//        if ((q = modmul(prd, max(x, y) - min(x, y), n))) prd = q;
//        x = f(x), y = f(f(y));
//    }
//    return __gcd(prd, n);
//}
//
//vector<ull> factor(ull n) {
//    if (n == 1) return {};
//    if (isPrime(n)) return {n};
//    ull x = pollard(n);
//    auto l = factor(x), r = factor(n / x);
//    l.insert(l.end(), all(r));
//    return l;
//}
//
//bool pos(ull x) {
//    while (x % 2 == 0) {
//        x /= 2;
//    }
//    if (x == 0 || x == 1) {
//        return true;
//    }
//    vector<ull> f = factor(x);
//    map<ull, int> cnt;
//    for (auto &i: f) {
//        ++cnt[i];
//    }
//    for (auto &i: cnt) {
//        if (i.first % 4 == 3 && i.second % 2 == 1) {
//            return false;
//        }
//    }
//
////    sort(f.begin(), f.end());
////    int m = int(f.size());
////    int i = 0;
////    if (f[i] % 4 == 1) {
////        ++i;
////    }
////    for (int j = 1; j < m; ++j) {
////        if (f[j] != f[i]) {
////            if ((j - i) % 2 == 1) {
////                return false;
////            }
////            i = j;
////        }
////        if (f[i] % 4 == 1) {
////            i = j + 1;
////        }
////    }
//    return true;
//}
//
//map<ll, ll> squares;
//
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//
//long long rnd(long long l, long long r) { // [l, r]
//    return uniform_int_distribution<long long>(l, r)(rng);
//}
//
//int main() {
//    cin.tie(0)->sync_with_stdio(0);
////    cout << (ll)999996 * 999996 + 1298*1298 + 2513 * 2513;
//
//    for (ll i = 0; i * i <= (ll) 1e12; ++i) {
//        squares[i * i] = i;
//    }
//    ll n;
//    cin >> n;
//    ll mul_pow = 1;
//    while (n % 4 == 0) {
//        n /= 4;
//        mul_pow *= 2;
//    }
//    if (n % 8 == 7) {
//        cout << -1 << "\n";
//        return 0;
//    }
//    ll mx = 0;
//    for (; mx * mx <= n; ++mx) {}
//    --mx;
//    vector<long long> nums(mx + 1);
//    for (int i = 0; i <= mx; ++i) {
//        nums[i] = i;
//    }
////    reverse(nums.begin(), nums.end());
////    shuffle(nums.begin(), nums.end(), rng);
////    cout << mx << " " << mx * mx << "\n";
//    for (auto &j: nums) {
//        ll rest = n - j * j;
//        if (pos(rest)) {
//            for (ll i = 0; j * j <= rest; ++i) {
//                if (squares.find(rest - i * i) != squares.end()) {
//                    cout << j * mul_pow << " " << i * mul_pow << " " << squares[rest - i * i] * mul_pow << "\n";
//                    return 0;
//                }
//            }
//        }
//    }
//}



#include<bits/stdc++.h>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef unsigned long long ull;

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

bool isPrime(ull n) {
    if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
    ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
            s = __builtin_ctzll(n - 1), d = n >> s;
    for (ull a: A) {
        ull p = modpow(a % n, d, n), i = s;
        while (p != 1 && p != n - 1 && a % n && i--)
            p = modmul(p, p, n);
        if (p != n - 1 && i != s) return 0;
    }
    return 1;
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

vector<ull> factor(ull n) {
    if (n == 1) return {};
    if (isPrime(n)) return {n};
    ull x = pollard(n);
    auto l = factor(x), r = factor(n / x);
    l.insert(l.end(), all(r));
    return l;
}

bool pos(ull x) {
    while (x % 2 == 0) {
        x /= 2;
    }
    if (x == 0 || x == 1) {
        return true;
    }
    vector<ull> f = factor(x);
    sort(f.begin(), f.end());
    int m = int(f.size());
    int i = 0;
    if (f[i] % 4 == 1) {
        ++i;
    }
    for (int j = 1; j < m; ++j) {
        if (f[j] != f[i]) {
            if ((j - i) % 2 == 1) {
                return false;
            }
            i = j;
        }
        if (f[i] % 4 == 1) {
            i = j + 1;
        }
    }

    return true;
}

//bool pos(ull x) {
//    while (x % 2 == 0) {
//        x /= 2;
//    }
//    if (x == 0 || x == 1) {
//        return true;
//    }
//    vector<ull> f = factor(x);
//    map<ull, int> cnt;
//    for (auto &i: f) {
//        ++cnt[i];
//    }
//    for (auto &i: cnt) {
//        if (i.first % 4 == 3 && i.second % 2 == 1) {
//            return false;
//        }
//    }
//
////    sort(f.begin(), f.end());
////    int m = int(f.size());
////    int i = 0;
////    if (f[i] % 4 == 1) {
////        ++i;
////    }
////    for (int j = 1; j < m; ++j) {
////        if (f[j] != f[i]) {
////            if ((j - i) % 2 == 1) {
////                return false;
////            }
////            i = j;
////        }
////        if (f[i] % 4 == 1) {
////            i = j + 1;
////        }
////    }
//    return true;
//}


map<ll, ll> squares;

int main() {
    cin.tie(0)->sync_with_stdio(0);
//    cout << (ll)999996 * 999996 + 1298*1298 + 2513 * 2513;

    for (ll i = 0; i * i <= (ll) 1e12; ++i) {
        squares[i * i] = i;
    }
    ll n;
    cin >> n;
    ll num = n;
    while (num % 4 == 0) {
        num /= 4;
    }
    if (num % 8 == 7) {
        cout << -1 << "\n";
        return 0;
    }
//    for (;mx * mx <= n; ++mx) {}
//    --mx;
//    cout << mx << " " << mx * mx << "\n";
    for (ll mx = max(0ll, (ll) round(sqrt(n / 3)) - 10);; ++mx) {
        ll rest = n - mx * mx;
        if (pos(rest)) {
            for (ll i = 0; i * i <= rest; ++i) {
                if (squares.find(rest - i * i) != squares.end()) {
                    cout << mx << " " << i << " " << squares[rest - i * i] << "\n";
                    return 0;
                }
            }
        }
    }
}
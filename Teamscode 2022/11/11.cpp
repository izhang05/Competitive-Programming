#include <bits/stdc++.h>


using namespace std;

typedef long long ll;
#define FFT
namespace kactl {
#define rep(i, from, to) for (int(i) = from; (i) < (to); ++(i))
#define all(x) x.begin(), (x).end()
#define sz(x) (int) (x).size()
    typedef long long ll;
    typedef pair<int, int> pii;
    typedef vector<int> vi;
    /**
 * Author: Andrew He
 * Description: FFT/NTT, polynomial mod/log/exp
 * Source: http://neerc.ifmo.ru/trains/toulouse/2017/fft2.pdf
 * Papers about accuracy: http://www.daemonology.net/papers/fft.pdf, http://www.cs.berkeley.edu/~fateman/papers/fftvsothers.pdf
 * For integers rounding works if $(|a| + |b|)\max(a, b) < \mathtt{\sim} 10^9$, or in theory maybe $10^6$.
 */

    namespace fft {
#if defined FFT
        long long mod = 1e9 + 7;
        // FFT
        using dbl = double;

        struct num { /// start-hash
            dbl x, y;

            num(dbl x_ = 0, dbl y_ = 0) : x(x_), y(y_) {}
        };

        inline num operator+(num a, num b) { return num(a.x + b.x, a.y + b.y); }

        inline num operator-(num a, num b) { return num(a.x - b.x, a.y - b.y); }

        inline num operator*(num a, num b) { return num(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x); }

        inline num conj(num a) { return num(a.x, -a.y); }

        inline num inv(num a) {
            dbl n = (a.x * a.x + a.y * a.y);
            return num(a.x / n, -a.y / n);
        }
        /// end-hash
#else
        // NTT
                const int mod = 998244353, g = 3;

        // For p < 2^30 there is also (5 << 25, 3), (7 << 26, 3),
        // (479 << 21, 3) and (483 << 21, 5). Last two are > 10^9.
                struct num { /// start-hash
                    int v;

                    num(ll v_ = 0) : v(int(v_ % mod)) { if (v < 0) v += mod; }

                    explicit operator int() const { return v; }
                };

                inline num operator+(num a, num b) { return num(a.v + b.v); }

                inline num operator-(num a, num b) { return num(a.v + mod - b.v); }

                inline num operator*(num a, num b) { return num(1ll * a.v * b.v); }

                inline num pow(num a, int b) {
                    num r = 1;
                    do {
                        if (b & 1)r = r * a;
                        a = a * a;
                    } while (b >>= 1);
                    return r;
                }

                inline num inv(num a) { return pow(a, mod - 2); }
        /// end-hash
#endif

        using vn = vector<num>;
        vi rev({0, 1});
        vn rt(2, num(1)), fa, fb;

        inline void init(int n) { /// start-hash
            if (n <= sz(rt)) return;
            rev.resize(n);
            rep(i, 0, n) rev[i] = (rev[i >> 1] | ((i & 1) * n)) >> 1;
            rt.reserve(n);
            for (int k = sz(rt); k < n; k *= 2) {
                rt.resize(2 * k);
#if defined FFT
                double a = M_PI / k;
                num z(cos(a), sin(a)); // FFT
#else
                num z = pow(num(g), (mod - 1) / (2 * k)); // NTT
#endif
                rep(i, k / 2, k) rt[2 * i] = rt[i], rt[2 * i + 1] = rt[i] * z;
            }
        } /// end-hash

        inline void fft(vector<num> &a, int n) { /// start-hash
            init(n);
            int s = __builtin_ctz(sz(rev) / n);
            rep(i, 0, n) if (i < rev[i] >> s) swap(a[i], a[rev[i] >> s]);
            for (int k = 1; k < n; k *= 2)
                for (int i = 0; i < n; i += 2 * k)
                    rep(j, 0, k) {
                        num t = rt[j + k] * a[i + j + k];
                        a[i + j + k] = a[i + j] - t;
                        a[i + j] = a[i + j] + t;
                    }
        } /// end-hash

// Complex/NTT
        vn multiply(vn a, vn b) { /// start-hash
            int s = sz(a) + sz(b) - 1;
            if (s <= 0) return {};
            int L = s > 1 ? 32 - __builtin_clz(s - 1) : 0, n = 1 << L;
            a.resize(n), b.resize(n);
            fft(a, n);
            fft(b, n);
            num d = inv(num(n));
            rep(i, 0, n) a[i] = a[i] * b[i] * d;
            reverse(a.begin() + 1, a.end());
            fft(a, n);
            a.resize(s);
            return a;
        } /// end-hash

// Complex/NTT power-series inverse
// Doubles b as b[:n] = (2 - a[:n] * b[:n/2]) * b[:n/2]
        vn inverse(const vn &a) { /// start-hash
            if (a.empty()) return {};
            vn b({inv(a[0])});
            b.reserve(2 * a.size());
            while (sz(b) < sz(a)) {
                int n = 2 * sz(b);
                b.resize(2 * n, 0);
                if (sz(fa) < 2 * n) fa.resize(2 * n);
                fill(fa.begin(), fa.begin() + 2 * n, 0);
                copy(a.begin(), a.begin() + min(n, sz(a)), fa.begin());
                fft(b, 2 * n);
                fft(fa, 2 * n);
                num d = inv(num(2 * n));
                rep(i, 0, 2 * n) b[i] = b[i] * (2 - fa[i] * b[i]) * d;
                reverse(b.begin() + 1, b.end());
                fft(b, 2 * n);
                b.resize(n);
            }
            b.resize(a.size());
            return b;
        } /// end-hash

#if defined FFT
        // Double multiply (num = complex)
        using vd = vector<double>;

        vd multiply(const vd &a, const vd &b) { /// start-hash
            int s = sz(a) + sz(b) - 1;
            if (s <= 0) return {};
            int L = s > 1 ? 32 - __builtin_clz(s - 1) : 0, n = 1 << L;
            if (sz(fa) < n) fa.resize(n);
            if (sz(fb) < n) fb.resize(n);

            fill(fa.begin(), fa.begin() + n, 0);
            rep(i, 0, sz(a)) fa[i].x = a[i];
            rep(i, 0, sz(b)) fa[i].y = b[i];
            fft(fa, n);
            for (auto &x: fa) {

                x = x * x;
            }
            rep(i, 0, n) fb[i] = fa[(n - i) & (n - 1)] - conj(fa[i]);
            fft(fb, n);
            vd r(s);
            rep(i, 0, s) r[i] = fb[i].y / (4 * n);
            return r;
        } /// end-hash

        // Integer multiply mod m (num = complex) /// start-hash
        vi multiply_mod(const vi &a, const vi &b, int m) {
            int s = sz(a) + sz(b) - 1;
            if (s <= 0) return {};
            int L = s > 1 ? 32 - __builtin_clz(s - 1) : 0, n = 1 << L;
            if (sz(fa) < n) fa.resize(n);
            if (sz(fb) < n) fb.resize(n);

            rep(i, 0, sz(a)) fa[i] = num(a[i] & ((1 << 15) - 1), a[i] >> 15);
            fill(fa.begin() + sz(a), fa.begin() + n, 0);
            rep(i, 0, sz(b)) fb[i] = num(b[i] & ((1 << 15) - 1), b[i] >> 15);
            fill(fb.begin() + sz(b), fb.begin() + n, 0);

            fft(fa, n);
            fft(fb, n);
            double r0 = 0.5 / n; // 1/2n
            rep(i, 0, n / 2 + 1) {
                int j = (n - i) & (n - 1);
                num g0 = (fb[i] + conj(fb[j])) * r0;
                num g1 = (fb[i] - conj(fb[j])) * r0;
                swap(g1.x, g1.y);
                g1.y *= -1;
                if (j != i) {
                    swap(fa[j], fa[i]);
                    fb[j] = fa[j] * g1;
                    fa[j] = fa[j] * g0;
                }
                fb[i] = fa[i] * conj(g1);
                fa[i] = fa[i] * conj(g0);
            }
            fft(fa, n);
            fft(fb, n);
            vi r(s);
            rep(i, 0, s) r[i] = int((ll(fa[i].x + 0.5)
                                     + (ll(fa[i].y + 0.5) % m << 15)
                                     + (ll(fb[i].x + 0.5) % m << 15)
                                     + (ll(fb[i].y + 0.5) % m << 30)) % m);
            return r;
        } /// end-hash
#endif

    } // namespace fft

// For multiply_mod, use num = modnum, poly = vector<num>
    using fft::num;
    using poly = fft::vn;
    using fft::multiply;
    using fft::inverse;

/// start-hash
    poly &operator+=(poly &a, const poly &b) {
        if (sz(a) < sz(b)) a.resize(b.size());
        rep(i, 0, sz(b)) a[i] = a[i] + b[i];
        return a;
    }

    poly operator+(const poly &a, const poly &b) {
        poly r = a;
        r += b;
        return r;
    }

    poly &operator-=(poly &a, const poly &b) {
        if (sz(a) < sz(b)) a.resize(b.size());
        rep(i, 0, sz(b)) a[i] = a[i] - b[i];
        return a;
    }

    poly operator-(const poly &a, const poly &b) {
        poly r = a;
        r -= b;
        return r;
    }

    poly operator*(const poly &a, const poly &b) {
        // TODO: small-case?
        return multiply(a, b);
    }

    poly &operator*=(poly &a, const poly &b) { return a = a * b; }

/// end-hash
    poly &operator*=(poly &a, const num &b) { // Optional
        for (auto &x: a) {
            x = x * b;
        }
        return a;
    }

    poly operator*(const poly &a, const num &b) {
        poly r = a;
        r *= b;
        return r;
    }

// Polynomial floor division; no leading 0's plz
    poly operator/(poly a, poly b) { /// start-hash
        if (sz(a) < sz(b)) return {};
        int s = sz(a) - sz(b) + 1;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        a.resize(s);
        b.resize(s);
        a = a * inverse(move(b));
        a.resize(s);
        reverse(a.begin(), a.end());
        return a;
    } /// end-hash
    poly &operator/=(poly &a, const poly &b) { return a = a / b; }

    poly &operator%=(poly &a, const poly &b) { /// start-hash
        if (sz(a) >= sz(b)) {
            poly c = (a / b) * b;
            a.resize(sz(b) - 1);
            rep(i, 0, sz(a)) a[i] = a[i] - c[i];
        }
        return a;
    } /// end-hash
    poly operator%(const poly &a, const poly &b) {
        poly r = a;
        r %= b;
        return r;
    }

// Log/exp/pow
    poly deriv(const poly &a) { /// start-hash
        if (a.empty()) return {};
        poly b(sz(a) - 1);
        rep(i, 1, sz(a)) b[i - 1] = a[i] * i;
        return b;
    } /// end-hash
    poly integ(const poly &a) { /// start-hash
        poly b(sz(a) + 1);
        b[1] = 1; // mod p
        rep(i, 2, sz(b)) b[i] = b[fft::mod % i] * (-fft::mod / i); // mod p
        rep(i, 1, sz(b)) b[i] = a[i - 1] * b[i]; // mod p
        //rep(i,1,sz(b)) b[i]=a[i-1]*inv(num(i)); // else
        return b;
    } /// end-hash
    poly log(const poly &a) { // a[0] == 1 /// start-hash
        poly b = integ(deriv(a) * inverse(a));
        b.resize(a.size());
        return b;
    } /// end-hash
    poly exp(const poly &a) { // a[0] == 0 /// start-hash
        poly b(1, num(1));
        if (a.empty()) return b;
        while (sz(b) < sz(a)) {
            int n = min(sz(b) * 2, sz(a));
            b.resize(n);
            poly v = poly(a.begin(), a.begin() + n) - log(b);
            v[0] = v[0] + num(1);
            b *= v;
            b.resize(n);
        }
        return b;
    } /// end-hash
//    poly pow(const poly &a, int m) { // m >= 0 /// start-hash
//        poly b(a.size());
//        if (!m) {
//            b[0] = 1;
//            return b;
//        }
//        int p = 0;
//        while (p < sz(a) && a[p].v == 0) ++p;
//        if (1ll * m * p >= sz(a)) return b;
//        num mu = pow(a[p], m), di = inv(a[p]);
//        poly c(sz(a) - m * p);
//        rep(i, 0, sz(c)) c[i] = a[i + p] * di;
//        c = log(c);
//        for (auto &v: c) {
//
//            v = v * m;
//        }
//
//        c = exp(c);
//        rep(i, 0, sz(c)) b[i +
//                           m * p
//                         ] = c[i] *
//                             mu;
//        return
//                b;
//    } /// end-hash

// Multipoint evaluation/interpolation
/// start-hash
    vector<num> eval(const poly &a, const vector<num> &x) {
        int n = sz(x);
        if (!n) return {};
        vector<poly> up(2 * n);
        rep(i, 0, n) up[i + n] = poly({0 - x[i], 1});
        for (int i = 1; i < n; ++i) {
            up[i] = up[2 * i] * up[2 * i + 1];
        }
        vector<poly> down(2 * n);
        down[1] = a % up[1];
        rep(i, 2, 2 * n) down[i] = down[i / 2] % up[i];
        vector<num> y(n);
        rep(i, 0, n) y[i] = down[i + n][0];
        return y;
    } /// end-hash
/// start-hash
    poly interp(const vector<num> &x, const vector<num> &y) {
        int n = sz(x);
        assert(n);
        vector<poly> up(n * 2);
        rep(i, 0, n) up[i + n] = poly({0 - x[i], 1});
        for (int i = 1; i < n; ++i) {
            up[i] = up[2 * i] * up[2 * i + 1];
        }
        vector<num> a = eval(deriv(up[1]), x);
        vector<poly> down(2 * n);
        rep(i, 0, n) down[i + n] = poly({y[i] * inv(a[i])});
        for (int i = 1; i < n; ++i) {
            down[i] = down[i * 2] * up[i * 2 + 1] + down[i * 2 + 1] * up[i * 2];
        }
        return down[1];
    } /// end-hash
}
//using namespace kactl;

int N, M, K;

const int MAX_N = 1e7 + 5, MAX_M = 1e6 + 5;

const ll MOD = 1e9 + 7;

ll mod_pow(ll b, ll p) {
    b %= MOD;
    ll ans = 1;
    while (p != 0) {
        if (p % 2) ans = ans * b % MOD;
        p /= 2;
        b = b * b % MOD;
    }
    return ans;
}

ll inv(ll b) { return mod_pow(b, MOD - 2); }

ll fact[MAX_N];
ll inv_fact[MAX_N];
ll arr[MAX_N];
ll inv_comp[MAX_N];

int mobius[MAX_M];

ll choose(int n, int k) {
    return fact[n] * inv_fact[n - k] % MOD * inv_fact[k] % MOD;
}

vector<int> primes;
vector<int> p_div;  // largest prime divisor
void sieve(int n) {
    p_div.resize(n + 1);
    fill(p_div.begin(), p_div.end(), -1);
    for (int i = 2; i < n + 1; ++i) {
        if (p_div[i] == -1) {
            primes.push_back(i);
            p_div[i] = i;
        }
        for (int j = 0; j < (int) primes.size() && (primes[j] * i <= n); ++j) {
            p_div[primes[j] * i] = primes[j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll ans = 0;

    cin >> N >> M >> K;

    fact[0] = 1;
    inv_fact[0] = 1;

    inv_comp[1] = 1;
    for (int i = 2; i <= N; ++i)
        inv_comp[i] = MOD - (MOD / i) * inv_comp[MOD % i] % MOD;

    // O(N)

    for (int i = 1; i <= N; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
        inv_fact[i] = inv_fact[i - 1] * inv_comp[i] % MOD;
    }

    // O(N)

    for (int i = 1; i <= N; ++i) {
        // i is number of non-zero
        int alr = i + K * (i - 1);
        if (alr > N) break;
        arr[i] = choose(i + (N - alr), N - alr);
        //  cerr << (i + N - alr) << " " << N - alr << "\n";
        //   cerr << arr[i] << "\n";
    }
    // cerr << "\n";

    // O(M)

    sieve(M + 1);

    for (int i = 1; i < M + 1; ++i) {
        set<int> s;
        int copy = i;
        int cnt = 0;
        int val = 1;
        while (copy != 1) {
            if (s.find(p_div[copy]) != s.end()) {
                val = 0;
                break;
            } else {
                cnt++;
                s.insert(p_div[copy]);
                copy /= p_div[copy];
            }
        }

        mobius[i] = val * (cnt % 2 ? -1 : 1);
    }

    vector<pair<pair<int, int>, int>> add;
    vector<pair<pair<int, int>, int>> sub;

    for (int i = 1; i < M + 1; ++i) {
        // cerr << M / i << "\n";

        if (M / i == 0) break;

        if (mobius[i] == 1) {
            if (add.size() && add.back().first.first == M / i) {
                add.back().second++;
            } else {
                add.push_back({{M / i, M / i}, 1});
            }
        }
        if (mobius[i] == -1) {
            if (sub.size() && sub.back().first.first == M / i) {
                sub.back().second++;
            } else {
                sub.push_back({{M / i, M / i}, 1});
            }
        }
    }
    vector<int> p(N + 1);
    for (int i = 0; i <= N; ++i) {
        p[i] = arr[i];
    }
    kactl::poly po(p.begin(), p.end());
    vector<kactl::fft::num> a = kactl::eval(po, add);
//    cout << << "\n";
    /*
      for (int i = 1; i <= N; ++i) {
          for (pair<pair<int, int>, int>& a : add) {
              // cerr << "add " << a << "\n";
              ans += arr[i] * (a.first.first * a.second);
              a.first.first *= a.first.second;
              a.first.first %= MOD;
              ans %= MOD;
          }
          for (pair<pair<int, int>, int>& a : sub) {
              // cerr << "sub " << a << "\n";
              ans -= arr[i] * (a.first.first * a.second);
              a.first.first *= a.first.second;
              a.first.first %= MOD;
              ans %= MOD;
          }
          // cerr << ans << "\n";
      }
      */
    ans %= MOD;

    cout << (ans + MOD) % MOD << "\n";
}
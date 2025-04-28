#include <bits/stdc++.h>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC optimize "-Ofast"
#pragma GCC optimize "-funroll-loops"
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
const int maxn = 1e6 + 10;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define allin(a, x) for(auto a : x)
#define sz(x) (int)(x).size()
#define trav(a, x) for(auto& a : x)
typedef long long ll;
#define int ll
const int inf = LLONG_MAX;
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
    for (ull a: A) {   // ^ count trailing zeroes
        ull p = modpow(a % n, d, n), i = s;
        while (p != 1 && p != n - 1 && a % n && i--)
            p = modmul(p, p, n);
        if (p != n - 1 && i != s) return 0;
    }
    return 1;
}

ull pollard(ull n) {
    ull x = 0, y = 0, t = 30, prd = 2, i = 1, q;
    auto f = [&](ull x) { return modmul(x, x, n) + i; };
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

void rec(vector<int> &p, vector<int> &e, vector<int> &vdiv, int cur = 0, int prod = 1) {
    if (cur == p.size()) {
        vdiv.pb(prod);
        return;
    }
    int aux = prod;
    for (int i = 0; i <= e[cur]; i++, prod *= p[cur])
        rec(p, e, vdiv, cur + 1, prod);
    prod = aux;
}

constexpr ll adamsqrt(ll x) {
    ll ret = sqrtl(x);

    if (ret * ret < x)
        ret++;
    if (ret * ret > x)
        ret--;

    return ret;
}

int isprime[maxn];

int n;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> primos_filtrar;
    for (int i = 2; i < maxn; i++)
        isprime[i] = 1;
    for (int i = 2; i < maxn; i++) {
        if (isprime[i]) {
            if (i % 4 != 3) {
                primos_filtrar.pb(i);
                if (primos_filtrar.size() == 50)
                    break;
            }
            for (int j = i * i; j < maxn; j += i) {
                isprime[j] = 0;
            }
        }
    }


    cin >> n;

    int nn = n;
    while (nn % 4 == 0) {
        nn /= 4;
    }
    if (nn % 8 == 7) {
        cout << "-1\n";
        return 0;
    }

    int lo = 0, hi = 1e6;
    while (hi > lo) {
        int mid = (lo + hi) / 2;
        if (3 * mid * mid >= n)
            hi = mid;
        else
            lo = mid + 1;
    }
    int minmax = lo; // menor x tq 3*x*x >= n
    int maxmin = minmax;
    while (3 * maxmin * maxmin > n)
        maxmin--;
    int gx = -1;
    // for(int x=0; x <= maxmin; x++)
    for (int x = minmax; x * x <= n; x++) {
        int a = n - x * x;
        if (a % 4 == 3)
            continue;
        if (a == 0) {
            cout << x << " " << 0 << " " << 0 << "\n";
            return 0;
        }
        if (a == 1) {
            cout << x << " " << 1 << " " << 0 << "\n";
            return 0;
        }
        int aa = a;
        for (int p: primos_filtrar) {
            while (aa % p == 0) {
                aa /= p;
            }
        }
        if (aa == 0 || aa == 1) {
            gx = x;
            break;
        }
        auto vec = factor(aa);
        sort(vec.begin(), vec.end());
        vector<int> p;
        for (int x: vec) p.pb(x);
        p.erase(unique(p.begin(), p.end()), p.end());
        vector<int> e(p.size());
        int cur = 0;
        e[cur] = 1;
        for (int i = 1; i < vec.size(); i++) {
            if (vec[i] == vec[i - 1])
                e[cur]++;
            else {
                cur++;
                e[cur] = 1;
            }
        }
        bool good = true;
        for (int i = 0; i < vec.size(); i++)
            if (p[i] % 4 == 3 && e[i] % 2 == 1)
                good = false;
        if (good) {
            gx = x;
            break;
        }
    }
    if (gx == -1) {
        cout << "-1\n";
        return 0;
    }
    int ga = n - gx * gx;
    for (int y = 0; y * y <= ga; y++) {
        int b = ga - y * y;
        int c = adamsqrt(b);
        if (c * c == b) {
            cout << gx << " " << y << " " << c << "\n";
            return 0;
        }
    }
    assert(false);

    return 0;
}
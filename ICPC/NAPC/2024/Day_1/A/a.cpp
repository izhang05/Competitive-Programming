#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

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

long long solve(long long a, long long p) {
    if (a % 2 == 1) {
        return 1;
    }
    long long ax = 1, mod = 1 << p, ans = 0;
    for (int i = 1; i < p; ++i) {
        ax = (ax * a) % mod;
        long long xa = binpow(i, a, mod);
        if (xa == ax) {
            ++ans;
        }
    }
    long long pow = (p + a - 1) / a;
    long long factor = 1 << pow;
    long long other_vals = (1 << p) / factor - (p + factor - 1) / factor + 1;
    return ans + other_vals;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int t;
    cin >> t;
    while (t--) {
        long long a, p;
        cin >> a >> p;
        cout << solve(a, p) << "\n";
    }
}
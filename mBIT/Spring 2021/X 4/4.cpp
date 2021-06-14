#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define nl "\n"
#define pb push_back

ll n, k;

ll modpower(ll x, ll pow,
            ll mod) { // x^pow mod (mod) in O(logn) time, recursive
    if (pow == 0) {
        return 1 % mod;
    }
    ll ret = modpower(x, pow / 2, mod);
    ret %= mod;
    ret = (ret * ret) % mod;
    if (pow % 2 == 1) {
        ret = (ret * (x % mod)) % mod;
    }
    return ret;
}

ll power(ll a, ll b) {
    ll product = 1;
    for (int i = 0; i < b; i++) {
        product *= a;
    }
    return product;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    ll num = n;
    for (int i = 0; i < 63; i++) {
        if (power(2, i) <= n) {
            num--;
        }
    }
    ll num1 = num;
    num = modpower(2, num, MOD);
    if (n > 64) {
        cout << (num * ((k + 1) % MOD)) % MOD << nl;
    } else {
        if (n - num1 >= 63) {
            cout << (num * ((k + 1) % MOD)) % MOD << nl;
        } else if (power(2, n - num1) - 1 <= k) {
            cout << (num * (modpower(2, n - num1, MOD))) % MOD << nl;
        } else {
            cout << (num * ((k + 1) % MOD)) % MOD << nl;
        }
    }
}
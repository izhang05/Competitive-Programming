#include <bits/stdc++.h>

using namespace std;

#define rep(i, from, to) for (int(i) = from; (i) < (to); ++(i))
#define all(x) x.begin(), (x).end()
#define sz(x) (int) (x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
/**
 * Author: Noam527
 * Date: 2019-04-24
 * License: CC0
 * Source: folklore
 * Description:
 * Status: tested
 */

const ll mod = 1000000007; // faster if const

ll modpow(ll b, ll e) {
    ll ans = 1;
    for (; e; b = b * b % mod, e /= 2)
        if (e & 1) ans = ans * b % mod;
    return ans;
}

const int mxn = 1e6 + 5;

ll fact[mxn], invfact[mxn];

ll nCr(int n, int k) {
    return (((fact[n] * invfact[n - k]) % mod) * invfact[k]) % mod;
}

int main() {
    fact[0] = 1;
    for (int i = 1; i < mxn; ++i) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    invfact[mxn - 1] = modpow(fact[mxn - 1], mod - 2);
    for (int i = mxn - 2; i >= 0; --i) {
        invfact[i] = (invfact[i + 1] * (i + 1)) % mod;
    }
    ll k, n, l;
    cin >> k >> n >> l;
    string s;
    cin >> s;
    long long sol = 1, cur = 0;
    for (int r = n - 1; r >= 0; --r) {
        if (s[r] == 'O') {
            ++cur;
        } else {
            sol *= nCr(cur, k);
            sol %= mod;
            cur -= k;
        }
    }
    cout << modpow(sol, l) << "\n";
    return 0;
}

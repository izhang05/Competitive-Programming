#define print_debug true

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_set;

typedef long long ll;

void fileIO(string name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

template <class T>
void debug(const T& n) {
    if (print_debug) cerr << n << "\n\n";
}

template <class T>
void debug(const vector<T>& k) {
    if (print_debug) {
        for (int i = 0; i < (int)k.size(); ++i) {
            cerr << k[i] << " ";
        }
        cerr << "\n\n";
    }
}

template <class T>
void debug(const vector<vector<T>>& k) {
    if (print_debug) {
        for (int i = 0; i < (int)k.size(); ++i) {
            for (int j = 0; j < (int)k[i].size(); ++j) {
                cerr << k[i][j] << " ";
            }
            cerr << "\n";
        }
        cerr << "\n";
    }
}

template <class T>
int bin_upper(const vector<T>& k, const T& value) {
    return distance(k.begin(), upper_bound(k.begin(), k.end(), value));
}

template <class T>
int bin_lower(const vector<T>& k, const T& value) {
    return distance(k.begin(), lower_bound(k.begin(), k.end(), value));
}

int n;
ll MOD;

long long mod_pow(long long x, long long n) {
    assert(n >= 0);
    x %= MOD;
    long long res = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            res = res * x % MOD;
        }
        x = x * x % MOD;
        n /= 2;
    }
    return res;
}

ll inv(ll a) {
    return mod_pow(a, MOD - 2);
}

vector<ll> ans;
vector<ll> fact;

const int maxn = 1e4 + 5;
long long inv_fact[maxn];

ll choose(ll a, ll b) {
    return (fact[a] * inv_fact[b] % MOD * inv_fact[a - b]) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> MOD;
    ans.resize(n + 1);
    fact.resize(n + 1);
    fact[0] = 1;
    for (int i = 1; i < n + 1; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
        inv_fact[i] = inv(fact[i]);
    }

    ans[1] = 0;
    for (int i = 2; i < n + 1; ++i) {
        ll total = mod_pow(3, i);
        ll move = 0;
        ll ev = 0;
        for (int j = 1; j < i; ++j) {
            move += 3 * choose(i, j) % MOD;
            move %= MOD;
            ev += (3 * choose(i, j) % MOD) * ans[j] % MOD;
            ev %= MOD;
        }

//        cerr << move << " " << ev << "\n";
        ev = (ev * inv(total)) % MOD;
        ans[i] = ((total * inv(move)) % MOD) * (ev + 1) % MOD;


    }

    for (int i = 1; i < n + 1; ++i) {
        cout << ans[i] << " ";
    }

}
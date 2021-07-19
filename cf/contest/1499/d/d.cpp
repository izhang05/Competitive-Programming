/* Author: izhang05
 * Time: 07-18-2021 23:10:21
**/
#include <bits/stdc++.h>

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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 3e7;
int c, d, x;
bool is_prime[maxn];
int num_primes[maxn];
long long sol;

void solve(long long g) {
    long long p = (x + d * g);
    if (p % c) {
        return;
    }
    p /= c;
    if (p % g) {
        return;
    }
    p /= g;
#ifdef DEBUG
    cout << g << " " << p << "\n";
#endif
    sol += 1 << num_primes[p];
}

int main() {
    setIO("1");
    memset(is_prime, true, sizeof(is_prime));
    for (int i = 2; i < maxn; ++i) {
        if (is_prime[i]) {
            ++num_primes[i];
            for (int j = 2 * i; j < maxn; j += i) {
                ++num_primes[j];
                is_prime[j] = false;
            }
        }
    }
    int t;
    cin >> t;
    while (t--) {
        cin >> c >> d >> x;
        sol = 0;
        for (long long g = 1; g * g <= x; ++g) {
            if (x % g == 0) {
                solve(g);
                if (g * g != x) {
                    solve(x / g);
                }
            }
        }
        cout << sol << "\n";
    }
    return 0;
}

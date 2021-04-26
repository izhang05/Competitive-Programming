#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(string name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}
const int maxn = 1e9;


vector<int> primes;
bool good(long long x) {
    if (x % 2 == 0) {
        return false;
    }
    for (int i = 3; i * i <= x; i += 2) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}
int m;

void solve() {
    long long n;
    cin >> n;
    int lo = 0, hi = m - 2, mid;
    long long res = -1;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if ((long long) primes[mid] * primes[mid + 1] <= n) {
            res = (long long) primes[mid] * primes[mid + 1];
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    cout << res << "\n";
}

bool prime[maxn + 1];
int main() {
    setIO("1");
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= maxn; p++) {
        // If prime[p] is not changed,
        // then it is a prime
        if (prime[p]) {
            // Update all multiples
            // of p greater than or
            // equal to the square of it
            // numbers which are multiple
            // of p and are less than p^2
            // are already been marked.
            for (int i = p * p; i <= maxn; i += p)
                prime[i] = false;
        }
    }
    primes.push_back(2);
    for (int i = 3; i < maxn; i += 2) {
        if (prime[i]) {
            primes.push_back(i);
        }
    }
    m = (int) primes.size();
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
}

/* Author: izhang05
 * Time: 06-25-2021 11:15:10
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

int main() {
    setIO("1");

    long long n;
    cin >> n;
    vector<long long> primes;
    if (n % 2 == 0) {
        primes.push_back(2);
        while (n % 2 == 0) {
            n /= 2;
        }
    }
    for (long long i = 3; i * i <= n; ++i) {
        if (n % i == 0) {
            primes.push_back(i);
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 1) {
        primes.push_back(n);
    }
    if (int(primes.size()) == 1) {
        cout << primes[0] << "\n";
    } else {
        cout << 1 << "\n";
    }
    return 0;
}

/* Author: izhang05
 * Time: 07-03-2021 09:05:10
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

vector<int> primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 39, 41, 43};

int f(int x) {
    for (int i = 2; i < x; ++i) {
        if (x % i != 0) {
            return i;
        }
    }
    return x + 1;
}

int main() {
    setIO("1");

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long sol = n, cur_lcm = 1;
        for (int i = 2; i <= 43 && cur_lcm <= (long long) 1e16; ++i) {
            //            if (lcm(cur_lcm, i) != cur_lcm) {
            sol += n / cur_lcm;
            sol %= mod;
            cur_lcm = lcm(cur_lcm, i);
            //            }
        }
        cout << sol << "\n";
    }
    return 0;
}

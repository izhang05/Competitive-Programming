/* Author: izhang05
 * Time: 07-07-2021 10:35:04
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

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

//int k_xor(int a, int b, int k) {
//    int res = 0;
//    int cnt = 0;
//    while (a | b) {
//        res += (int) binpow(k, cnt, mod) * ((a % k + b % k) % k);
//        a /= k;
//        b /= k;
//        ++cnt;
//    }
//    return res;
//}
//
//int anti_k_xor(int a, int b, int k) {
//    int res = 0, cnt = 0;
//    while (a | b) {
//        res += (int) binpow(k, cnt, mod) * ((b % k - a % k + k) % k);
//        a /= k;
//        b /= k;
//        ++cnt;
//    }
//    return res;
//}

int eval(vector<int> digits, int guess, int k, bool add) {
    int res = 0;
    for (int i = 0; i < (int) digits.size(); ++i) {
        int cur = digits[i];
        if (add) {
            cur += guess % k;
        } else {
            cur -= guess % k;
        }
        cur = (cur % k + k) % k;
        res += (int) binpow(k, i, mod) * cur;
        guess /= k;
    }
    return res;
}

void solve() {
    int n, k;
    cin >> n >> k;
    set<int> pos;
    for (int i = 0; i < n; ++i) {
        pos.insert(i);
    }
    vector<int> digits(26, 0);
    for (int i = 0; i < n; ++i) {
        int guess = eval(digits, *pos.begin(), k, i % 2 == 0);
        pos.erase(pos.begin());
        cout << guess << endl;
        for (int &digit : digits) {
            digit = guess % k - digit;
            guess /= k;
        }
        int res;
        cin >> res;
        if (res == 1) {
            return;
        }
    }
}

int main() {
    setIO("1");

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

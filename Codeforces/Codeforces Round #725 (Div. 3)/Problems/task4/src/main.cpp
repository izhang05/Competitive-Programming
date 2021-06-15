#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

int factors(int x) {
    int res = 0;
    while (x % 2 == 0) {
        ++res;
        x /= 2;
    }
    for (int i = 3; i * i <= x; i += 2) {
        while (x % i == 0) {
            ++res;
            x /= i;
        }
    }
    if (x > 1) {
        ++res;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int t;
    cin >> t;
    while (t--) {
        int a, b, k;
        cin >> a >> b >> k;
        if (a > b) {
            swap(a, b);
        }
        if (k == 1) {
            if (b % a == 0 && b != a) {
                cout << "YES" << "\n";
            } else {
                cout << "NO" << "\n";
            }
            continue;
        }
        cout << ((factors(a) + factors(b) >= k) ? "YES" : "NO") << "\n";
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
set<long long> bad;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    long long cur = 2;
    while (cur < (long long) 1e10) {
        bad.insert(cur);
        cur *= 4;
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n % 2 == 1) {
            cout << "Bob" << "\n";
            continue;
        }
        if (bad.find(n) != bad.end()) {
            cout << "Bob" << "\n";
        } else {
            cout << "Alice" << "\n";
        }
    }
    return 0;
}

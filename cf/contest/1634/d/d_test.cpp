#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long rnd(long long l, long long r) {
    return uniform_int_distribution<long long>(l, r)(rng);
}

int main() {
    srand(time(nullptr));
    int tests = 2;
    cout << tests << endl;
    while (tests--) {
        int n = rnd(4, 5);
        vector<int> a(n);
        for (int i = 1; i < n; ++i) {
            a[i] = rnd(1, 5);
        }
        shuffle(a.begin(), a.end(), rng);
        cout << n << endl;
        int mx = 2 * n - 2;
        int cnt = 0;
        while (true) {
            char t;
            cin >> t;
            if (t == '?') {
                ++cnt;
                if (cnt > mx) {
                    return 1;
                }
                int i, j, k;
                cin >> i >> j >> k;
                --i, --j, --k;
                cout << max({a[i], a[j], a[k]}) - min({a[i], a[j], a[k]}) << endl;
            } else if (t == '!') {
                int i, j;
                cin >> i >> j;
                --i, --j;
                if (a[i] && a[j]) {
                    return 2;
                }
                break;
            }
        }
    }
    return 0;
}
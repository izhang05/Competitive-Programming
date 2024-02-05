#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include <debug.h>
#else
struct dbg {
    template<class c>
    dbg &operator<<(const c &) { return *this; }
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#endif

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long double rnd(long double l, long double r) { // [l, r]
    return uniform_real_distribution<long double>(l, r)(rng);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int t = 1000;
    for (int n = 2; n <= 20; ++n) {
        int cur = 0;
        for (int i = 0; i < t; ++i) {
            vector<vector<long double>> a(n, vector<long double>(n)), b(n, vector<long double>(n));
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    a[j][k] = rnd(0, 1);
                    b[j][k] = rnd(0, 1);
                }
            }
            bool psne = false;
            for (int j = 0; j < n && !psne; ++j) {
                for (int k = 0; k < n; ++k) {
                    bool good = true;
                    // row deviates
                    for (int l = 0; l < n; ++l) {
                        if (a[l][k] > a[j][k]) {
                            good = false;
                        }
                    }

                    // column deviates
                    for (int l = 0; l < n; ++l) {
                        if (b[j][l] > b[j][k]) {
                            good = false;
                        }
                    }
                    if (good) {
                        psne = true;
                        break;
                    }
                }
            }
            cur += psne;
        }
        cout << "(" << n << ", " << (long double) cur / t << ")"
             << "\n";
    }
    return 0;
}

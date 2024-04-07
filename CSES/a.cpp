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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxk = 65;
int k[mxk];

long long dp(long long r, long long x) {
    if (x == )
        vector<int> dp(mxk, mxk);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    k[1] = 0;
    for (int i = 2; i < mxk; ++i) {
        k[i] = 1 + k[__builtin_popcount(i)];
    }
    while (true) {
        long long lo, hi, x;
        cin >> lo >> hi >> x;
        if (lo == 0 && hi == 0 && x == 0) {
            break;
        }
        if (lo < )
        long long sol = 0;
        for (int i = 0; i < mxk; ++i) {
            if (k[i] == x - 1) {
                sol += dp(hi, i) - dp(lo - 1, i);
            }
        }
        cout << sol << "\n";
    }

    return 0;
}

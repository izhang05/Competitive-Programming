#include <bits/stdc++.h>

using namespace std;

#if defined LOCAL || defined DEBUG
#include <debug.h>
#else
struct dbg {
    template<class c>
    dbg &operator<<(const c &) { return *this; }
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#endif

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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 1e8 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
bool prime[mxn];


int main() {
    memset(prime, true, sizeof(prime));
    for (int i = 2; i < mxn; ++i) {
        if (prime[i]) {
            for (int j = i + i; j < mxn; j += i) {
                prime[j] = false;
            }
        }
    }
    long long sol = 0;
    for (int i = 1; i <= 1e8; ++i) {
        bool good = true;
        for (long long j = 1; j * j <= i; ++j) {
            if (i % j == 0 && !prime[j + i / j]) {
                good = false;
                break;
            }
        }
        if (good) {
            sol += i;
        }
    }
    cout << sol << "\n";
}

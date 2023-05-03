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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

void test_case() {
    int n, l, h;
    cin >> n >> l >> h;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    int mn = n, mx = 0;
    for (int i = l; i <= h; ++i) {
        for (int j = 1; j <= i; ++j) {
            int cnt = 0, a = 0, b = j;
            while (a < n) {
                int cur = 0;
                for (int k = a; k < min(b, n); ++k) {
                    cur += p[k];
                }
                a = b, b += i;
                if (cur > 0) {
                    ++cnt;
                }
            }
            mn = min(mn, cnt);
            mx = max(mx, cnt);
        }
    }
    cout << mn << " " << mx << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}

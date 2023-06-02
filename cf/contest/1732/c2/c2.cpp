/* Author: izhang
 * Time: 05-08-2023 22:20:58
**/
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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<long long> s(n + 1), x(n + 1);
    for (int i = 0; i < n; ++i) {
        s[i + 1] = s[i] + a[i];
        x[i + 1] = x[i] ^ a[i];
    }
    auto f = [&](int l, int r) -> long long {
        return s[r] - s[l] - (x[r] ^ x[l]);
    };

    while (q--) {
        int l, r;
        cin >> l >> r;
        --l;
        pair<long long, long long> sol{l, r};
        long long val = f(l, r);
        for (int i = l; i < r; ++i) {
            int lo = i + 1, hi = r, mid;
            while (lo <= hi) {
                mid = (lo + hi) / 2;
                if (f(i, mid) == val) {
                    hi = mid - 1;
                    if (sol.second - sol.first > mid - i) {
                        sol = {i, mid};
                    }
                } else {
                    lo = mid + 1;
                }
            }
        }
        cout << sol.first + 1 << " " << sol.second << "\n";
    }
}

int main() {
    setIO("1");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}

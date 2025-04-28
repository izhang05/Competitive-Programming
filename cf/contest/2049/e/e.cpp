/* Author: izhang
 * Time: 12-27-2024 18:40:38
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
int n;

int q(int l, int r) { // [l, r), 0-indexed
    cout << "? " << l + 1 << " " << r << endl;
    int res;
    cin >> res;
    return res;
}

void g(int x) {
    cout << "! " << x << endl;
}

void solve() {
    cin >> n;
    int div = n / 4, a = q(0, div), b = q(div, 2 * div), c = q(2 * div, 3 * div);
    if (a + b + c >= 2) {
        // k <= div
        long long bot;
        if (a == 1) {
            bot = 0;
        } else if (b == 1) {
            bot = div;
        }
        long long lo = 1, hi = div, mid, sol = 1;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            int cur = q(bot, bot + mid);
            if (cur == 1) {
                sol = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        g(sol);
    } else {
        // k > div
        long long lo = div + 1, hi = n, mid, sol;
        long long top;
        if (a == 1) {
            top = div;
        } else if (b == 1) {
            top = 2 * div;
        } else if (c == 1) {
            top = 3 * div;
        } else {
            top = 4 * div;
        }
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            long long cur_top = top;
            long long bot = top - mid;
            if (bot < 0) {
                cur_top -= bot;
                bot = 0;
            }
            int cur = q(bot, cur_top);
            if (cur == 0) {
                sol = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        g(sol);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

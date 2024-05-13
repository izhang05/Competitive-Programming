/* Author: izhang
 * Time: 04-07-2024 00:43:59
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
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(x);
    for (int i = 0; i < x; ++i) {
        cin >> a[i];
        a[i] %= n;
    }
    sort(a.begin(), a.end());
    int sol = x - 2;
    multiset<int> even, odd;
    for (int i = 0; i < x; ++i) {
        int b = a[i], c = a[(i + 1) % x];
        if ((b + 2) % n == c) {
            ++sol;
        }
        int cur = (c - b + n) % n;
        if ((cur) % 2 == 0) {
            if (cur > 2) {
                even.insert(cur);
            }
        } else if (cur >= 3) {
            odd.insert(cur);
        }
    }
    dbg() << even << " " << odd;
    while (y) {
        if (!even.empty()) {
            auto it = even.begin();
            if (*it == 4) {
                sol += 3;
                --y;
            } else {
                int op = min(y, *it / 2 - 2);
                sol += 2 * op;
                even.insert(*it - 2 * op);
                y -= op;
            }
            even.erase(it);
        } else if (!odd.empty()) {
            auto it = odd.begin();
            int op = min(y, *it / 2);
            sol += 2 * op;
            y -= op;
            odd.erase(it);
        } else {
            break;
        }
    }
    cout << sol << "\n";
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

/* Author: izhang
 * Time: 09-08-2023 02:36:09
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

long long f(long long a, long long b, int x) {
    if (x == 0) {
        return a + b;
    } else if (x == 1) {
        return a - b;
    } else if (x == 2) {
        return a * b;
    } else if (x == 3) {
        if (b == 0 || a % b == 0) {
            return a / b;
        } else {
            return -INFL;
        }
    }
}

void test_case() {
    vector<int> a(3);
    for (int i = 0; i < 3; ++i) {
        cin >> a[i];
    }
    long long sol = INFL;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            long long cur = f(a[0], a[1], i);
            if (cur == -INFL) {
                continue;
            }
            cur = f(cur, a[2], j);
            if (cur >= 0) {
                sol = min(sol, cur);
            }
        }
    }
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}

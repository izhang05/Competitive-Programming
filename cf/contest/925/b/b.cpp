/* Author: izhang
 * Time: 05-02-2022 21:39:09
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

long long c_div(long long a, long long b) {
    return (a + b - 1) / b;
}

bool solve(long long n, long long x1, long long x2, const vector<pair<long long, int>> &c, bool swapped) {
    for (int i = 1; i <= n; ++i) {
        long long u = c_div(x2, i);
        if (c[n - i].first >= u) {
            for (int j = 1; j <= n; ++j) {
                long long u2 = c_div(x1, j);
                auto it = lower_bound(c.begin(), c.end(), make_pair(u2, -inf));
                if (it - c.begin() + j <= n - i) {
                    cout << "Yes"
                         << "\n";
                    if (!swapped) {
                        cout << j << " " << i << "\n";
                        for (int k = it - c.begin(); k < it - c.begin() + j; ++k) {
                            cout << c[k].second << " ";
                        }
                        cout << "\n";
                        for (int k = n - i; k < n; ++k) {
                            cout << c[k].second << " ";
                        }
                        cout << "\n";
                    } else {
                        cout << i << " " << j << "\n";
                        for (int k = n - i; k < n; ++k) {
                            cout << c[k].second << " ";
                        }
                        cout << "\n";
                        for (int k = it - c.begin(); k < it - c.begin() + j; ++k) {
                            cout << c[k].second << " ";
                        }
                        cout << "\n";
                    }
                    return true;
                }
            }
            return false;
        }
    }
}

void test_case() {
    long long n, x1, x2;
    cin >> n >> x1 >> x2;
    vector<pair<long long, int>> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i].first;
        c[i].second = i + 1;
    }
    sort(c.begin(), c.end());
    if (!solve(n, x1, x2, c, false)) {
        if (!solve(n, x2, x1, c, true)) {
            cout << "No"
                 << "\n";
        }
    }
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}

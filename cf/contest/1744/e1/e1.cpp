/* Author: izhang
 * Time: 11-03-2022 22:19:23
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
int sieve[maxn];

multiset<int> factor(int x) {
    multiset<int> res;
    while (x != 1) {
        res.insert(sieve[x]);
        x /= sieve[x];
    }
    return res;
}

void test_case() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    multiset<int> f = factor(a);
    for (auto &i : factor(b)) {
        f.insert(i);
    }
    for (int i = a + 1; i <= c; ++i) {
        multiset<int> cur = factor(i), goal = f;
        for (auto &j : cur) {
            auto it = goal.find(j);
            if (it != goal.end()) {
                goal.erase(it);
            }
        }
        long long prod = 1;
        for (auto &j : goal) {
            prod *= j;
        }
        long long sol = prod * (d / prod);
        if (sol > b) {
            cout << i << " " << sol << "\n";
            return;
        }
    }
    cout << -1 << " " << -1 << "\n";
}

int main() {
    setIO("1");
    sieve[1] = 1;
    for (int i = 2; i < maxn; ++i) {
        if (sieve[i] == 0) {
            for (int j = i; j < maxn; j += i) {
                sieve[j] = i;
            }
        }
    }
    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}

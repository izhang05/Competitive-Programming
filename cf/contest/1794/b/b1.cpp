/* Author: izhang
 * Time: 03-04-2023 12:35:03
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
//    freopen("out.txt", "w", stdout);
//    freopen("out.txt", "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long rnd(long long l, long long r) { // [l, r]
    return uniform_int_distribution<long long>(l, r)(rng);
}

void test_case() {
    //    int n;
    //    cin >> n;
    //    vector<int> a(n);
    //    for (int i = 0; i < n; ++i) {
    //        cin >> a[i];
    //    }
    int n = 10;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = rnd(1, 1e9);
        cout << a[i] << " \n"[i == n - 1];
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] == 1) {
            ++a[i];
        }
        if (a[i] % 2 != i % 2) {
            ++a[i];
        }
        cout << a[i] << " \n"[i == n - 1];
        cout.flush();
    }
    for (int i = 0; i < n - 1; ++i) {
        if (a[i + 1] % a[i] == 0) {
            assert(false);
        }
    }
}

int main() {
    setIO("1");

    int test_case_number = 1000;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}

/* Author: izhang
 * Time: 10-11-2025 13:55:15
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
int sol_a = 0, sol_b = 0;


long long dist(long long x, long long y) {
    return (x - 144) * (x - 144) + (y - 84) * (y - 84);
}

void test_case() {
    int n, m;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        a[i] = dist(x, y);
    }
    sort(a.begin(), a.end());
    cin >> m;
    vector<long long> b(m);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        b[i] = dist(x, y);
    }
    sort(b.begin(), b.end());
    long long first_b = INFL, first_a = INFL;
    if (n != 0) {
        first_a = a[0];
    }
    if (m != 0) {
        first_b = b[0];
    }

    for (int i = 0; i < n; ++i) {
        if (a[i] < first_b) {
            ++sol_a;
        }
    }
    for (int i = 0; i < m; ++i) {
        if (b[i] < first_a) {
            ++sol_b;
        }
    }
}

int main() {
    setIO("1");

    int test_case_number = 10;
    while (test_case_number--) {
        test_case();
    }
    cout << sol_a << " " << sol_b << "\n";
    return 0;
}

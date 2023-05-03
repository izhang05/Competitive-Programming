/* Author: izhang
 * Time: 05-02-2023 13:51:13
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
    vector<int> pre(n + 1);
    for (int i = 1; i < n - 1; ++i) {
        pre[i + 1] = pre[i] + (a[i - 1] >= a[i] && a[i] >= a[i + 1]);
    }
    pre[n] = pre[n - 1];
    while (q--) {
        int l, r;
        cin >> l >> r;
        --l;
        if (r - l <= 2) {
            cout << r - l << "\n";
            continue;
        }
        int sol = r - l - (pre[r - 1] - pre[l + 1]);
        cout << sol << "\n";
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

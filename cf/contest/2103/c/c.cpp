/* Author: izhang
 * Time: 05-15-2025 15:49:47
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] <= k) {
            a[i] = 1;
        } else {
            a[i] = -1;
        }
    }
    vector<int> pre(n + 1), rev(n + 1);
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1] + a[i - 1];
    }
    for (int i = n - 1; i >= 0; --i) {
        rev[i] = rev[i + 1] + a[i];
    }

    multiset<int, greater<>> vals, vals_rev;
    for (int i = 1; i < n; ++i) {
        vals.insert(pre[i]);
        vals_rev.insert(rev[i]);
    }

    for (int i = 0; i < n - 2; ++i) {
        vals.erase(vals.find(pre[i + 1]));
        vals_rev.erase(vals_rev.find(rev[i + 1]));
        if (pre[i + 1] >= 0) {
            if (*vals.begin() >= pre[i + 1] || *vals_rev.begin() >= 0) {
                cout << "YES" << "\n";
                return;
            }
        }
    }

    vals.clear(), vals_rev.clear();
    for (int i = 1; i < n; ++i) {
        vals.insert(pre[i]);
        vals_rev.insert(rev[i]);
    }
    for (int i = n - 1; i >= 2; --i) {
        vals.erase(vals.find(pre[i]));
        vals_rev.erase(vals_rev.find(rev[i]));
        if (rev[i] >= 0) {
            if (*vals.begin() >= 0 || *vals_rev.begin() >= rev[i]) {
                cout << "YES" << "\n";
                return;
            }
        }
    }

    cout << "NO" << "\n";
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

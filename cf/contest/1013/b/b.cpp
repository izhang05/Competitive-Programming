/* Author: izhang
 * Time: 10-15-2023 00:45:01
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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    multiset<int> cur, pos;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (cur.find(a[i]) != cur.end()) {
            cout << 0 << "\n";
            return;
        }
        cur.insert(a[i]);
    }
    bool good = false;
    for (int i = 0; i < n; ++i) {
        if ((a[i] & x) == a[i]) {
            if (cur.count(a[i] & x) >= 2) {
                cout << 1 << "\n";
                return;
            }
        } else {
            if (cur.count(a[i] & x) >= 1) {
                cout << 1 << "\n";
                return;
            }
        }
        if (pos.find(a[i] & x) != pos.end()) {
            good = true;
        }
        pos.insert(a[i] & x);
    }
    cout << (good ? 2 : -1) << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}

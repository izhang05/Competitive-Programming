/* Author: izhang
 * Time: 01-06-2023 11:08:29
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    set<int> t, b;
    for (int i = 1; i <= n; ++i) {
        t.insert(i);
        b.insert(i);
    }
    vector<int> p(n, inf), q(n, inf);
    for (int i = 0; i < n; ++i) {
        if (t.find(a[i]) != t.end()) {
            p[i] = a[i];
            t.erase(a[i]);
        } else if (b.find(a[i]) != b.end()) {
            q[i] = a[i];
            b.erase(a[i]);
        } else {
            cout << "NO"
                 << "\n";
            return;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (p[i] == inf) {
            auto it = t.upper_bound(q[i]);
            if (it == t.begin()) {
                cout << "NO"
                     << "\n";
                return;
            }
            p[i] = *--it;
            t.erase(it);
        }
        if (q[i] == inf) {
            auto it = b.upper_bound(p[i]);
            if (it == b.begin()) {
                cout << "NO"
                     << "\n";
                return;
            }
            q[i] = *--it;
            b.erase(it);
        }
    }
    cout << "YES"
         << "\n";
    for (auto &i : p) {
        cout << i << " ";
    }
    cout << "\n";
    for (auto &i : q) {
        cout << i << " ";
    }
    cout << "\n";
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

/* Author: izhang
 * Time: 06-03-2024 10:35:01
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
    vector<int> b(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        b[i] = __gcd(a[i], a[i + 1]);
    }
    dbg() << b;
    for (int i = 0; i < n - 2; ++i) {
        if (b[i + 1] < b[i]) {
            for (int j = i; j <= i + 2 && j < n; ++j) {
                vector<int> cur;
                for (int k = 0; k < n; ++k) {
                    if (k != j) {
                        cur.push_back(a[k]);
                    }
                }
                vector<int> b2(int(cur.size()) - 1);
                for (int l = 0; l < int(cur.size()) - 1; ++l) {
                    b2[l] = __gcd(cur[l], cur[l + 1]);
                }
                dbg() << j << " " << cur << " " << b2;
                bool good = true;
                for (int k = 0; k < int(b2.size()) - 1; ++k) {
                    dbg() << b2[k + 1] << " " << b2[k] << " " << (b2[k + 1] < b2[k]);
                    if (b2[k + 1] < b2[k]) {
                        good = false;
                    }
                }
                if (good) {
                    cout << "YES"
                         << "\n";
                    return;
                }
                dbg() << j << " " << i + 2 << " " << n;
            }
            cout << "NO"
                 << "\n";
            return;
        }
    }
    cout << "YES"
         << "\n";
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

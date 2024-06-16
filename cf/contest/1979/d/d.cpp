/* Author: izhang
 * Time: 06-06-2024 19:30:01
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
    string s;
    cin >> s;
    vector<int> a;
    int pre = 0;
    char c = s[0];
    for (int i = 1; i < n; ++i) {
        if (s[i] != c) {
            a.push_back(i - pre);
            pre = i;
            c = s[i];
        }
    }
    a.push_back(n - pre);
    int bad = 0;
    for (auto &i : a) {
        if (i != k) {
            ++bad;
        }
    }
    //    dbg() << a << " " << bad;
    if (bad > 2) {
        cout << -1 << "\n";
        return;
    }
    int m = int(a.size());
    if (bad == 0) {
        if (m == 1 || m % 2 == 0) {
            cout << k << "\n";
        } else {
            cout << 2 * k << "\n";
        }
        return;
    }
    if (bad == 1) {
        int cur = 0;
        for (int i = 0; i < m; ++i) {
            if (a[i] != k) {
                if (i % 2 != m % 2) {
                    cout << -1 << "\n";
                } else if (a[i] == 2 * k) {
                    cout << cur + k << "\n";
                } else {
                    cout << -1 << "\n";
                }
                return;
            }
            cur += a[i];
        }
        return;
    }
    // bad == 2
    if (a.back() >= k) {
        cout << -1 << "\n";
        return;
    }
    int need = k - a.back();
    int cur = 0;
    for (int i = 0; i < m; ++i) {
        if (a[i] != k) {
            if (i % 2 != (m - 1) % 2) {
                cout << -1 << "\n";
                return;
            }
            if (a[i] < k) {
                if (a[i] == need) {
                    cout << cur + need << "\n";
                } else {
                    cout << -1 << "\n";
                }
                return;
            } else {
                if (a[i] - need == k) {
                    cout << cur + need << "\n";
                } else {
                    cout << -1 << "\n";
                }
                return;
            }
        }
        cur += a[i];
    }
    cout << -1 << "\n";
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

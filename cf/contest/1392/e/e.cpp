/* Author: izhang
 * Time: 01-03-2024 17:36:53
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
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("out.txt", "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
int n;

void test_case() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i % 2 == 0) {
                cout << 0 << " ";
            } else {
                cout << (1ll << (i + j - 1)) << " ";
            }
        }
        cout << endl;
    }
    int q;
    cin >> q;
    while (q--) {
        long long k;
        cin >> k;
        pair<int, int> cur{0, 0};
        cout << 1 << " " << 1 << "\n";
        for (int i = 0; i < 55; ++i) {
            if (!(k & (1ll << i))) {
                if (cur.first % 2 == 0) {
                    ++cur.second;
                } else {
                    ++cur.first;
                }
            } else {
                if (cur.first % 2 == 0) {
                    ++cur.first;
                } else {
                    ++cur.second;
                }
            }
            cout << cur.first + 1 << " " << cur.second + 1 << endl;
            if (cur == make_pair(n - 1, n - 1)) {
                break;
            }
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

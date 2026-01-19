/* Author: izhang
 * Time: 06-20-2025 15:42:27
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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 2e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

long long f[mxn];

void test_case() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'B') {
            a[i] = 0;
        } else {
            a[i] = 1;
        }
    }
    long long sol = 0, cur = 0, res = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 1) {
            ++cur;
        } else {
            if (cur % 2 == 0) {
                sol += cur / 2 + res;
                if (res) {
                    --res;
                    ++cur;
                }
            } else {
                sol += cur / 2;
                --cur;
                ++res;
            }
        }
    }
    cout << sol + f[res] << "\n";
}

int main() {
    setIO("1");

    f[1] = 1, f[2] = 2;
    for (int i = 3; i < mxn; ++i) {
        f[i] = f[i - 2] + i;
    }

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}

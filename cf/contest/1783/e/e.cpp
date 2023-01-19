/* Author: izhang
 * Time: 01-11-2023 21:54:55
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
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    vector<int> inc(n + 2);
    for (int i = 0; i < n; ++i) {
        if (a[i] > b[i]) {
            ++inc[b[i] + 1], --inc[a[i] + 1];
        }
    }
    for (int i = 1; i <= n + 1; ++i) {
        inc[i] += inc[i - 1];
    }
    vector<int> sol;
    for (int k = 1; k <= n; ++k) {
        bool good = true;
        for (int i = k; i <= n; i += k) {
            if (inc[i + 1] != 0) {
                good = false;
                break;
            }
        }
        if (good) {
            sol.push_back(k);
        }
    }
    cout << sol.size() << "\n";
    for (auto &i : sol) {
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

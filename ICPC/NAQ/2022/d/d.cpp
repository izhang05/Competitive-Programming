/* Author: izhang
 * Time: 09-08-2023 02:30:40
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
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
        --a[i];
    }
    vector<int> sol(n);
    for (int i = 0; i < n; ++i) {
        int cur = i;
        for (int j = 0; j < m; ++j) {
            if (a[j] == cur) {
                ++cur;
            } else if (a[j] == cur - 1) {
                --cur;
            }
        }
        sol[cur] = i + 1;
    }
    for (auto &i: sol) {
        cout << i << "\n";
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

/* Author: izhang
 * Time: 04-28-2022 14:23:50
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
    set<int> nums;
    for (int i = 1; i <= n; ++i) {
        nums.insert(i);
    }
    for (int i = 0; i < m; ++i) {
        int _, b;
        cin >> _ >> b >> _;
        nums.erase(b);
    }
    int center = *nums.begin();
    for (int i = 1; i <= n; ++i) {
        if (i != center) {
            cout << i << " " << center << "\n";
        }
    }
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

// Rating: 10 - easy statement to understand, nice construction that is easy to prove, short impl, suitable difficulty

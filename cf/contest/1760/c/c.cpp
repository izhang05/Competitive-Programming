/* Author: izhang
 * Time: 12-01-2022 14:07:49
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
    try {
        freopen(("in" + name + ".txt").c_str(), "r", stdin);
    } catch (...) {
        freopen(("testI" + name + ".txt").c_str(), "r", stdin);
    }
    freopen("out.txt", "w", stdout);
    freopen("out.txt", "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

void test_case() {
    int n;
    cin >> n;
    set<pair<int, int>, greater<>> mx;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mx.insert({a[i], i});
    }
    auto it = mx.begin();
    for (int i = 0; i < n; ++i) {
        if (it->second != i) {
            cout << a[i] - it->first << " ";
        } else {
            cout << a[i] - next(it)->first << " ";
        }
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

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
    int n, f, k;
    cin >> n >> f >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int fav = a[f - 1];
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    if (k == n) {
        cout << "YES"
             << "\n";
        return;
    }
    if (k == 0) {
        cout << "NO"
             << "\n";
        return;
    }
    if (a[k] > fav) {
        cout << "NO"
             << "\n";
    } else if (a[k] < fav) {
        cout << "YES"
             << "\n";
    } else if (a[k - 1] == fav) {
        cout << "MAYBE"
             << "\n";
    } else {
        cout << "NO"
             << "\n";
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

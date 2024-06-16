/* Author: izhang
 * Time: 06-06-2024 14:38:59
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
    map<array<int, 3>, int> occ;
    map<pair<int, int>, int> o12, o13, o23;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    long long sol = 0;
    for (int i = 0; i < n - 2; ++i) {
        array<int, 3> cur = {a[i], a[i + 1], a[i + 2]};
        sol += o12[{a[i], a[i + 1]}];
        sol += o13[{a[i], a[i + 2]}];
        sol += o23[{a[i + 1], a[i + 2]}];
        sol -= 3 * occ[cur];

        ++o12[{a[i], a[i + 1]}];
        ++o13[{a[i], a[i + 2]}];
        ++o23[{a[i + 1], a[i + 2]}];

        ++occ[cur];
    }
    cout << sol << "\n";
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

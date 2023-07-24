/* Author: izhang
 * Time: 07-21-2023 16:57:06
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
    vector<pair<int, int>> a(n);
    map<int, long long> col, row, d1, d2;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
        ++col[a[i].first];
        ++row[a[i].second];
        ++d1[a[i].first + a[i].second];
        ++d2[a[i].first - a[i].second];
    }
    long long sol = 0;
    for (auto &i : col) {
        sol += (i.second - 1) * i.second;
    }
    for (auto &i : row) {
        sol += i.second * (i.second - 1);
    }
    for (auto &i : d1) {
        sol += i.second * (i.second - 1);
    }
    for (auto &i : d2) {
        sol += i.second * (i.second - 1);
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

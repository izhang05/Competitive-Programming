/* Author: izhang
 * Time: 09-19-2025 20:55:17
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

int dist (pair<int, int> x, pair<int, int> y) {
    return abs(x.first - y.first) + abs(x.second - y.second);
}

void test_case() {
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first.first >> a[i].first.second;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    for (auto &i: a) {
        cout << i.first.first << " " << i.first.second << " " << i.second + 1 << "\n";
    }
    int sol = 0;
    for (int i = 0; i < n / 2; ++i) {
        sol += dist(a[i].first, a[n - i - 1].first);
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

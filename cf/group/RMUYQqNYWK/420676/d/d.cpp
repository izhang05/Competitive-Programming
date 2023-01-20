/* Author: izhang
 * Time: 01-19-2023 20:54:07
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
    set<pair<pair<int, int>, int>, greater<>> inc;
    set<pair<pair<int, int>, int>> dec;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
        if (a[i].first < a[i].second) {
            inc.insert({a[i], i + 1});
        } else {
            dec.insert({a[i], i + 1});
        }
    }
    if (inc.size() >= dec.size()) {
        cout << inc.size() << "\n";
        for (auto &i : inc) {
            cout << i.second << " ";
        }
        cout << "\n";
    } else {
        cout << dec.size() << "\n";
        for (auto &i : dec) {
            cout << i.second << " ";
        }
        cout << "\n";
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

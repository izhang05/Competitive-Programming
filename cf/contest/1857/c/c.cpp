/* Author: izhang
 * Time: 08-08-2023 13:45:01
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
    int m = (n * (n - 1)) / 2;
    vector<int> b(m);
    map<int, int> cnt;
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
        ++cnt[b[i]];
    }
    sort(b.begin(), b.end());
    vector<int> a;
    int cur = n - 1;
    for (auto &i : cnt) {
        while (i.second > 0) {
            a.push_back(i.first);
            i.second -= cur;
            --cur;
        }
    }
    a.push_back(1e9);
    for (auto &i : a) {
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

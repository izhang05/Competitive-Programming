/* Author: izhang
 * Time: 05-13-2024 17:10:01
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
    vector<pair<int, int>> a(2 * n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = 0;
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i + n].first;
        a[i + n].second = 1;
    }
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    sort(a.begin(), a.end());
    vector<long long> range;
    stack<int> st;
    for (auto &i : a) {
        if (i.second == 0) {
            st.push(i.first);
        } else {
            range.push_back(i.first - st.top());
            st.pop();
        }
    }
    sort(range.begin(), range.end());
    sort(c.begin(), c.end());
    reverse(c.begin(), c.end());
    long long sol = 0;
    for (int i = 0; i < n; ++i) {
        sol += range[i] * c[i];
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

/* Author: izhang
 * Time: 02-06-2023 22:35:49
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
    int n, k, l;
    cin >> n >> k >> l;
    int m = n * k;
    vector<int> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int mx = a[0] + l;
    int ind = upper_bound(a.begin(), a.end(), mx) - a.begin();
    multiset<int> nums;
    if (ind < n) {
        cout << 0 << "\n";
        return;
    }
    for (auto &i : a) {
        nums.insert(i);
    }
    long long orig = a[0], sol = orig;
    nums.erase(nums.begin());
    for (int i = 0; i < k - 1; ++i) {
        nums.erase(prev(nums.end()));
    }
    for (int i = 0; i < n - 1; ++i) {
        auto it = prev(nums.upper_bound(orig + l));
        sol += *it;
        nums.erase(it);
        for (int j = 0; j < k - 1; ++j) {
            nums.erase(prev(nums.end()));
        }
    }
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}

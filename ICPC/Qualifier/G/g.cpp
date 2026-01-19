/* Author: izhang
 * Time: 10-19-2025 11:58:51
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

int test_case_number = 0;

void test_case() {
    ++test_case_number;
    int n;
    cin >> n;
    if (n == 0) {
        exit(0);
    }
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        int b;
        cin >> b;
        a[i] -= b;
    }
    vector<long long> pre(n);
    pre[0] = a[0];
    for (int i = 1; i < n; ++i) {
        pre[i] = pre[i - 1] + a[i];
    }
    multiset<long long> nums;
    for (int i = 0; i < n; ++i) {
        nums.insert(pre[i]);
    }
    long long offset = 0;
    vector<int> sol;

    for (int i = 0; i < n; ++i) {
//        cout << i << " " << *nums.begin() << " " << offset << "\n";
        if (*nums.begin() + offset >= 0) {
            sol.push_back(i + 1);
        }
        nums.erase(nums.find(pre[i]));
        offset -= a[i];
        nums.insert(-offset);
    }



    cout << "Case " << test_case_number << ": ";
    int m = sol.size();
    for (int i = 0; i < m; ++i) {
        cout << sol[i] << " \n"[i == m - 1];
    }
}

int main() {
    setIO("1");

    while (true) {
        test_case();
    }
    return 0;
}

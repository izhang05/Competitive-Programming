/* Author: izhang
 * Time: 06-24-2024 16:25:01
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
    long long k;
    cin >> n >> k;
    if (k % 2 == 1) {
        cout << "No"
             << "\n";
        return;
    }
    long long mx = 0;
    for (int i = 1; i <= n; ++i) {
        int cur = n - i + 1;
        mx += abs(i - cur);
    }
    if (k > mx) {
        cout << "No"
             << "\n";
        return;
    }
    cout << "Yes"
         << "\n";
    vector<int> sol(n);
    for (int i = 0; i < n; ++i) {
        sol[i] = i + 1;
    }
    for (int i = 0; i < n && k; ++i) {
        int cur = 2 * abs(i - (n - i - 1));
        if (k >= cur) {
            swap(sol[i], sol[n - i - 1]);
            k -= cur;
        } else {
            for (int j = i + 1; j < n; ++j) {
                if (2 * (j - i) == k) {
                    swap(sol[i], sol[j]);
                    k = 0;
                }
            }
        }
    }
    for (auto &i : sol) {
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

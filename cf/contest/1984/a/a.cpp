/* Author: izhang
 * Time: 06-09-2024 10:35:01
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
    map<int, int> nums;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++nums[a[i]];
    }
    if (int(nums.size()) == 1) {
        cout << "NO"
             << "\n";
    } else {
        cout << "YES"
             << "\n";
        if (nums.size() == 2) {
            bool found = false;
            for (int i = 0; i < n; ++i) {
                if (found || nums[a[i]] == 1) {
                    cout << 'B';
                } else {
                    cout << 'R';
                    found = true;
                }
            }
        } else {
            cout << 'R';
            for (int i = 0; i < n - 1; ++i) {
                cout << 'B';
            }
        }
        cout << "\n";
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

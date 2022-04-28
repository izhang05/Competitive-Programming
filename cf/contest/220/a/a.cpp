/* Author: izhang
 * Time: 04-11-2022 23:07:03
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
pair<int, int> bad{-1, -1};
void add(int x) {
    if (bad.first == -1) {
        bad.first = x;
    } else if (bad.second == -1) {
        bad.second = x;
    } else {
        cout << "NO"
             << "\n";
        exit(0);
    }
}

void test_case() {
    int n;
    cin >> n;
    vector<int> a(n);
    multiset<pair<int, int>, greater<>> nums;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        nums.insert({a[i], -i});
    }
    for (int i = n - 1; i >= 1; --i) {
        nums.erase(nums.find({a[i], -i}));
        if (nums.begin()->first > a[i]) {
            swap(a[i], a[-nums.begin()->second]);
            bool good = true;
            for (int j = 1; j < n; ++j) {
                if (a[j] < a[j - 1]) {
                    good = false;
                    break;
                }
            }
            if (good) {
                cout << "YES" << "\n";
            } else {
                cout << "NO" << "\n";
            }
            return;
        }
    }
    cout << "YES"
         << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}

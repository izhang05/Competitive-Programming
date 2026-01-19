/* Author: izhang
 * Time: 05-19-2025 22:38:06
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
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
    }
    bool chain = false;
    int pre = -2;
    for (auto it = cnt.begin(); it != cnt.end(); ++it) {
        if (it->second >= 4) {
            cout << "Yes\n";
            return;
        }
        if (it->first != pre + 1) {
            chain = false;
        }
        if (chain) {
            if (it->second >= 2) {
                cout << "Yes\n";
                return;
            }
            pre = it->first;
        } else if (it->second >= 2) {
            chain = true;
            pre = it->first;
        }
    }
    cout << "No\n";
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

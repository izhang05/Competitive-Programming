/* Author: izhang
 * Time: 10-19-2025 11:59:02
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
const long long INFL = 0x3f3f3f3f3f3f3f3f, mxs = 4e14;

void test_case() {
    int n;
    cin >> n;
    vector<__int128> a(n);
    set<int> pos;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[i] = x;
        if (a[i] != 1) {
            pos.insert(i);
        }
    }
    pos.insert(n);
    long long sol = 0;
    for (int i = 0; i < n; ++i) {
        __int128 cur_sum = a[i], cur_prod = a[i];
        int ind = i;
        while (true) {
            int nxt = *pos.upper_bound(ind);
            int diff = nxt - ind - 1;
            if (cur_sum < cur_prod && cur_sum + diff >= cur_prod) {
                ++sol;
            }
            cur_sum += diff;
            if (nxt == n) {
                break;
            }
            cur_prod *= a[nxt];
            cur_sum += a[nxt];
            if (cur_sum == cur_prod) {
                ++sol;
            }
            if (cur_prod > mxs) {
                break;
            }
            ind = nxt;
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

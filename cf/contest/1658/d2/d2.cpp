/* Author: izhang
 * Time: 03-27-2022 10:35:01
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxs = 20;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

void test_case() {
    int l, r;
    cin >> l >> r;
    int n = r - l + 1;
    vector<int> goal(maxs);
    for (int i = l; i <= r; ++i) {
        for (int j = 0; j < maxs; ++j) {
            if (i & (1 << j)) {
                ++goal[j];
            }
        }
    }
    vector<int> a(n), cnt(maxs);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j = 0; j < maxs; ++j) {
            if (a[i] & (1 << j)) {
                ++cnt[j];
            }
        }
    }
    sort(a.begin(), a.end());
    vector<int> pos;
    int sol = 0;
    for (int i = 0; i < maxs; ++i) {
        if (cnt[i] != goal[i]) {
            sol ^= 1 << i;
        } else if (n - cnt[i] == cnt[i]) {
            pos.push_back(i);
        }
    }
    for (int i = 0; i < (1 << int(pos.size())); ++i) {
        int x = sol;
        for (int j = 0; j < int(pos.size()); ++j) {
            if (i & (1 << j)) {
                x ^= 1 << pos[j];
            }
        }
        dbg() << x;
        vector<int> cur(n);
        for (int j = 0; j < n; ++j) {
            cur[j] = (j + l) ^ x;
        }
        sort(cur.begin(), cur.end());
        if (cur == a) {
            cout << x << "\n";
            return;
        }
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

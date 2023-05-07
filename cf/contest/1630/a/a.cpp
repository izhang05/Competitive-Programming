/* Author: izhang
 * Time: 05-03-2023 10:30:24
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

int n, k;

int comp(int x) {
    return n - 1 - x;
}

void test_case() {
    cin >> n >> k;
    if (k == n - 1) {
        if (n == 4) {
            cout << -1 << "\n";
            return;
        }
        cout << k << " " << k - (n >> 1) << "\n";
        cout << (n >> 1) << " " << (n >> 1) + 1 << "\n";
        cout << comp((n >> 1) + 1) << " " << 0 << "\n";

        set<pair<int, int>> pairs;
        for (int i = 1; i < n - 1; ++i) {
            pair<int, int> cur = {i, comp(i)};
            if (cur.first == (n >> 1) + 1 || cur.second == (n >> 1) + 1 || cur.first == (n >> 1) || cur.second == (n >> 1)) {
                continue;
            }
            if (cur.first > cur.second) {
                swap(cur.first, cur.second);
            }
            pairs.insert(cur);
        }
        for (auto &i : pairs) {
            cout << i.first << " " << i.second << "\n";
        }
        return;
    }
    cout << n - 1 << " " << k << "\n";
    set<pair<int, int>> pairs;
    dbg() << n - 1 << " " << k;
    for (int i = 1; i < n - 1; ++i) {
        pair<int, int> cur = {i, comp(i)};
        if (cur.first == k || cur.second == k) {
            continue;
        }
        if (cur.first > cur.second) {
            swap(cur.first, cur.second);
        }
        pairs.insert(cur);
    }
    if (k != 0) {
        pairs.insert({0, comp(k)});
    }
    for (auto &i : pairs) {
        cout << i.first << " " << i.second << "\n";
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

/* Author: izhang
 * Time: 04-15-2022 23:24:28
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
    int n, s;
    cin >> n >> s;
    vector<pair<int, int>> buy, sell;
    for (int i = 0; i < n; ++i) {
        char d;
        int p, q;
        cin >> d >> p >> q;
        if (d == 'B') {
            buy.emplace_back(p, q);
        } else {
            sell.emplace_back(p, q);
        }
    }
    if (!sell.empty()) {
        sort(sell.begin(), sell.end());
        pair<int, int> pre = {sell[0].first, 0};
        int cnt = 0;
        vector<pair<int, int>> sol;
        for (auto &i : sell) {
            if (i.first == pre.first) {
                pre.second += i.second;
            } else {
                sol.push_back(pre);
                ++cnt;
                if (cnt >= s) {
                    break;
                }
                pre = i;
            }
        }
        if (cnt < s) {
            sol.push_back(pre);
        }
        reverse(sol.begin(), sol.end());
        for (auto &i : sol) {
            cout << "S " << i.first << " " << i.second << "\n";
        }
    }
    if (!buy.empty()) {
        sort(buy.begin(), buy.end());
        reverse(buy.begin(), buy.end());
        pair<int, int> pre = {buy[0].first, 0};
        int cnt = 0;
        for (auto &i : buy) {
            if (i.first == pre.first) {
                pre.second += i.second;
            } else {
                cout << "B " << pre.first << " " << pre.second << "\n";
                ++cnt;
                if (cnt >= s) {
                    break;
                }
                pre = i;
            }
        }
        if (cnt < s) {
            cout << "B " << pre.first << " " << pre.second << "\n";
        }
    }
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}

/* Author: izhang
 * Time: 12-04-2023 19:54:14
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
    string s;
    cin >> s;
    pair<int, int> sum, q;
    for (int i = 0; i < n / 2; ++i) {
        if (s[i] == '?') {
            ++q.first;
        } else {
            sum.first += s[i] - '0';
        }
    }
    for (int i = n / 2; i < n; ++i) {
        if (s[i] == '?') {
            ++q.second;
        } else {
            sum.second += s[i] - '0';
        }
    }
    if (sum.first > sum.second || (sum.first == sum.second && q.first > q.second)) {
        swap(sum.first, sum.second);
        swap(q.first, q.second);
    }
    // sum.first <= sum.second
    int diff = sum.second - sum.first;
    int m = q.first + q.second;
    pair<int, int> orig_sum = sum, orig_q = q;

    for (int i = 0; i < m / 2; ++i) {
        if (q.second != 0) {
            diff += 9;
            --q.second;
        } else {
            --q.first;
        }

        if (q.first != 0) {
            diff -= 9;
            --q.first;
        } else {
            --q.second;
        }
    }
    if (diff > 0) {
        cout << "Monocarp"
             << "\n";
        return;
    }

    q = orig_q;
    diff = sum.second - sum.first;
    for (int i = 0; i < m / 2; ++i) {
        if (q.first != 0) {
            diff -= 9;
            --q.first;
        } else {
            --q.second;
        }

        if (q.second != 0) {
            diff += 9;
            --q.second;
        } else {
            --q.first;
        }
    }
    if (diff < 0) {
        cout << "Monocarp"
             << "\n";
        return;
    }
    cout << "Bicarp"
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

/* Author: izhang
 * Time: 12-19-2025 13:05:18
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
    int n, k;
    cin >> n >> k;
    if (k % 2 == 1) {
        for (int i = 0; i < k; ++i) {
            cout << n << " ";
        }
        cout << "\n";
        return;
    }
    vector<long long> sol(k);
    vector<int> avail;
    int cur = 0;
    for (int i = 30; i >= 0; --i) {
        if (n & (1 << i)) {
            for (int j = 0; j < k; ++j) {
                if (j != min(k - 1, cur)) {
                    sol[j] += 1 << i;
                }
            }
            if (cur != k) {
                avail.push_back(cur);
                ++cur;
            }
        } else {
            for (int j = 0; j + 1 < int(avail.size()); j += 2) {
                sol[avail[j]] += 1 << i;
                sol[avail[j + 1]] += 1 << i;
            }
        }
    }
    for (auto &i: sol) {
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

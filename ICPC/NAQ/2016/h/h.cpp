/* Author: izhang
 * Time: 01-01-2024 13:57:21
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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxw = 1e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
int dp_h[maxw], dp_b[maxw];

void test_case() {
    int h;
    cin >> h;
    memset(dp_h, 0x3f, sizeof(dp_h));
    memset(dp_b, 0x3f, sizeof(dp_b));
    dp_h[0] = dp_b[0] = 0;
    vector<int> h_v(h);
    for (int i = 0; i < h; ++i) {
        cin >> h_v[i];
    }
    sort(h_v.begin(), h_v.end());
    reverse(h_v.begin(), h_v.end());
    for (auto &i: h_v) {
        for (int j = maxw - 1; j >= 0; --j) {
            if (j + i < maxw) {
                dp_h[j + i] = min(dp_h[j + i], dp_h[j] + 1);
            }
        }
    }
    int b;
    cin >> b;
    vector<int> b_v(b);
    for (int i = 0; i < b; ++i) {
        cin >> b_v[i];
    }
    sort(b_v.begin(), b_v.end());
    reverse(b_v.begin(), b_v.end());
    for (auto &i: b_v) {
        for (int j = maxw - 1; j >= 0; --j) {
            if (j + i < maxw) {
                dp_b[j + i] = min(dp_b[j + i], dp_b[j] + 1);
            }
        }
    }
    int sol = inf;
    for (int i = 1; i < maxw; ++i) {
        sol = min(sol, dp_h[i] + dp_b[i]);
    }
    if (sol == inf) {
        cout << "impossible" << "\n";
    } else {
        cout << sol << "\n";
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

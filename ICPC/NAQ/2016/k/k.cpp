/* Author: izhang
 * Time: 01-01-2024 14:15:43
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

void test_case() {
    pair<long long, long long> a, b, t;
    cin >> a.first >> a.second >> b.first >> b.second >> t.first >> t.second;
    pair<long long, long long> sol{-1, -1};
    for (int i = 1; i < maxw; ++i) {
        pair<long long, long long> cur{a.first * i, a.second * i};
        if (cur.first > t.first || cur.second > t.second) {
            continue;
        }
        pair<long long, long long> rem = {t.first - cur.first, t.second - cur.second};
        if (i < 10) {
            dbg() << i << " " << cur << " " << rem << " " << sol;
        }
        if (rem.first % b.first == 0 && rem.second % b.second == 0 && rem.first / b.first == rem.second / b.second &&
            rem.first != 0) {
            if (sol != make_pair(-1ll, -1ll)) {
                cout << "?" << "\n";
                return;
            }
            sol = {i, rem.first / b.first};
        }
    }
    if (sol == make_pair(-1ll, -1ll)) {
        cout << "?" << "\n";
    } else {
        cout << sol.first << " " << sol.second << "\n";
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

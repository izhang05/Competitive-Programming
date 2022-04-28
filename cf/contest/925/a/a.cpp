/* Author: izhang
 * Time: 04-19-2022 22:48:05
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
    long long n, m, cl, ce, v;
    cin >> n >> m >> cl >> ce >> v;
    vector<int> stairs(cl), elev(ce);
    for (int i = 0; i < cl; ++i) {
        cin >> stairs[i];
    }
    for (int i = 0; i < ce; ++i) {
        cin >> elev[i];
    }
    dbg() << imie(stairs);
    dbg() << imie(elev);
    int q;
    cin >> q;
    while (q--) {
        long long x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        dbg() << x1 << " " << y1 << " " << x2 << " " << y2;
        if (y1 == y2) {
            cout << abs(x1 - x2) << "\n";
            continue;
        }
        auto it = lower_bound(stairs.begin(), stairs.end(), x1);
        long long sol = INFL;
        if (it != stairs.end()) {
            dbg() << "stairs: " << *it;
            sol = abs(y2 - y1) + abs(*it - x1) + abs(*it - x2);
        }
        if (it != stairs.begin()) {
            dbg() << "stairs: " << *prev(it);
            sol = min(sol, (long long) abs(y2 - y1) + abs(*prev(it) - x1) + abs(*prev(it) - x2));
        }
        it = lower_bound(elev.begin(), elev.end(), x1);
        if (it != elev.end()) {
            dbg() << "elev: " << *it;
            sol = min(sol, (long long) abs(*it - x1) + abs(*it - x2) + (abs(y1 - y2) + v - 1) / v);
        }
        if (it != elev.begin()) {
            dbg() << "elev: " << *prev(it);
            sol = min(sol, (long long) abs(*prev(it) - x1) + abs(*prev(it) - x2) + (abs(y1 - y2) + v - 1) / v);
        }
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

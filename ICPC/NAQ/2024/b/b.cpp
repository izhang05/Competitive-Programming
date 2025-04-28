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
    bool inter = false;
    long double sol = 1e18;
    for (int i = 0; i < n; ++i) {
        long double x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if ((x1 > 0 && x2 > 0) || (x1 < 0 && x2 < 0)) {
            continue;
        }
        long double slope = (y2 - y1) / (x2 - x1);
        long double point = y1 - x1 * slope;
        if (point <= 0) {
            continue;
        }
        inter = true;
        sol = min(sol, point);
    }
    if (!inter) {
        cout << "-1.0" << "\n";
        return;
    }
    cout << fixed << setprecision(18) << sol << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}

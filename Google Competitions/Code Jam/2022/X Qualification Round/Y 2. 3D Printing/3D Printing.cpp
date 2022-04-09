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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
struct printer {
    long long c, m, y, k;
    void mn(const printer &rhs) {
        c = min(c, rhs.c);
        m = min(m, rhs.m);
        y = min(y, rhs.y);
        k = min(k, rhs.k);
    }
};

void test_case() {
    int n = 3;
    vector<printer> a(n);
    printer sol{INFL, INFL, INFL, INFL};
    for (auto &i : a) {
        cin >> i.c >> i.m >> i.y >> i.k;
        sol.mn(i);
    }
    long long goal = 1e6;
    long long sum = sol.c;

    long long add = min(sol.m, goal - sum);
    sum += add;
    sol.m = add;
    add = min(sol.y, goal - sum);
    sum += add;
    sol.y = add;
    add = min(sol.k, goal - sum);
    sum += add;
    sol.k = add;
    if (sum < goal) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    cout << sol.c << " " << sol.m << " " << sol.y << " " << sol.k << "\n";
}

int main() {
    setIO("1");
    int test_case_number = 1;
    cin >> test_case_number;
    for (int i = 1; i <= test_case_number; ++i) {
        cout << "Case #" << i << ": ";
        test_case();
    }
}

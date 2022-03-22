/* Author: izhang
 * Time: 03-22-2022 10:45:04
**/
#include <bits/stdc++.h>

using namespace std;

#if defined LOCAL || defined DEBUG
#include <debug.h>
#include <ostream>
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

struct unit {
    long long c, d, h;
    friend ostream &operator<<(ostream &os, const unit &unit) {
        os << "c: " << unit.c << " d: " << unit.d << " h: " << unit.h;
        return os;
    }
};
struct monster {
    int ind;
    long long d, h;
    friend ostream &operator<<(ostream &os, const monster &monster) {
        os << "ind: " << monster.ind << " d: " << monster.d << " h: " << monster.h;
        return os;
    }
    bool operator<(const monster &rhs) const {
        return d * h < rhs.d * rhs.h;
    }
};

void test_case() {
    int n, c;
    cin >> n >> c;
    vector<unit> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].c >> a[i].d >> a[i].h;
    }
    int m;
    cin >> m;
    vector<monster> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i].d >> b[i].h;
        b[i].ind = i;
    }
    sort(b.begin(), b.end());
    vector<int> sol(m);

    for (auto &i : sol) {
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

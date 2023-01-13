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
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;//998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

int res(int a, int b) {
    int res = b + 1;
    if (a == b) {
        res += 3;
    } else if (b - a == 1 || b - a == -2) {
        res += 6;
    }
    return res;
}

void test_case() {
    int n = 2500;
    vector<pair<char, char>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
        a[i].first -= 'A', a[i].second -= 'X';
    }
    vector<int> s{0, 1, 2};
    long long sol = 0;
//    do {
        long long cur = 0;
        for (int i = 0; i < n; ++i) {
            cur += res(a[i].first, s[a[i].second]);
        }
        sol = max(sol, cur);
//    } while (std::next_permutation(s.begin(), s.end()));
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}

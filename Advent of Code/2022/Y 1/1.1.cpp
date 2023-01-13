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

void test_case() {
    int n = 245;
    multiset<long long, greater<>> res;
    for (int i = 0; i < n; ++i) {
        long long sum = 0;
        int x;
        while (true) {
            cin >> x;
            if (x == -1) {
                break;
            }
            sum += x;
        }
        res.insert(sum);
    }
    long long sol = 0;
    for (int i = 0; i < 3; ++i) {
        auto it = res.begin();
        sol += *it;
        res.erase(it);
    }
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

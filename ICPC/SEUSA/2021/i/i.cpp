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
    vector<int> a(1 << n);
    for (auto &i: a) {
        cin >> i;
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    int sol = 0;
    for (int r = n - 1; r >= 0; --r) {
        set<int, greater<>> cur;
        for (int i = (1 << r); i < (1 << (r + 1)); ++i) {
            cur.insert(a[i]);
        }
        for (int i = 0; i < (1 << r); ++i) {
            auto it = cur.upper_bound(a[i] - k);
            if (it == cur.begin()) {
                cur.erase(*cur.rbegin());
            } else {
                cur.erase(prev(it));
                ++sol;
            }
        }
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

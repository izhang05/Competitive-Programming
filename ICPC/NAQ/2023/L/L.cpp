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
    int n, a, b;
    cin >> n >> a >> b;
    bool mn = false, mx = false;
    for (int i = 0; i < n - 1; ++i) {
        int x;
        cin >> x;
        if (x < a || x > b) {
            cout << -1 << "\n";
            return;
        }
        if (x == a) {
            mn = true;
        }
        if (x == b) {
            mx = true;
        }
    }
    if ((!mn) && (!mx)) {
        cout << -1 << "\n";
    } else if (mn && (!mx)) {
        cout << b << "\n";
    } else if ((!mn) && mx) {
        cout << a << "\n";
    } else {
        for (int i = a; i <= b; ++i) {
            cout << i << "\n";
        }
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

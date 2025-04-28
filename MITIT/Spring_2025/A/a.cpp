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
    if (n == 4) {
        cout << 2025 << "\n";
    } else if (n == 5) {
        cout << 42025 << "\n";
    } else if (n == 6) {
        cout << 632025 << "\n";
    } else if (n % 2 == 0) {
        cout << 25;
        for (int i = 0; i < n / 2 - 4; ++i) {
            cout << 0;
        }
        cout << 45;
        for (int i = 0; i < n / 2 - 4; ++i) {
            cout << 0;
        }
        cout << 2025 << "\n";
    } else {
        cout << 1;
        for (int i = 0; i < (n / 2) - 2; ++i) {
            cout << 0;
        }
        cout << 9;
        for (int i = 0; i < (n / 2) - 3; ++i) {
            cout << 0;
        }
        cout << 2025 << "\n";
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

#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include <debug.h>
#else
struct dbg {
    template<class c>
    dbg &operator<<(const c &) { return *this; }
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#endif

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

void test_case() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        rotate(a.begin(), a.begin() + 1, a.end());
        bool good = true;
        for (int j = 1; j < n; ++j) {
            if (a[j] < a[j - 1]) {
                good = false;
            }
        }
        if (good) {
            cout << "Yes"
                 << "\n";
            return;
        }
    }
    cout << "No"
         << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int t;
    cin >> t;
    while (t--) {
        test_case();
    }
    return 0;
}

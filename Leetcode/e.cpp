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

int maxLength(vector<int> a, int k) {
    int sol = 0, j = 0, n = int(a.size()), cur = 0;
    for (int i = 0; i < n; ++i) {
        while (j < n && cur + a[j] <= k) {
            cur += a[j];
            ++j;
        }
        cur = max(0, cur - a[i]);
        sol = max(sol, j - i);
    }
    return sol;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int t;
    cin >> t;
    while (t--) {

    }
    return 0;
}

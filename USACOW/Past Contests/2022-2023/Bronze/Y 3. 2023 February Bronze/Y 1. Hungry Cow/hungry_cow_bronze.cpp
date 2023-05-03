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


int main() {
    setIO("1");
    long long n, t;
    cin >> n >> t;
    long long sum = 0, mx = 0;
    for (int i = 0; i < n; ++i) {
        long long d, b;
        cin >> d >> b;
        sum += b;
        mx = max(mx + b, d + b);
    }
    cout << sum - max(0ll, mx - t - 1) << "\n";
    return 0;
}

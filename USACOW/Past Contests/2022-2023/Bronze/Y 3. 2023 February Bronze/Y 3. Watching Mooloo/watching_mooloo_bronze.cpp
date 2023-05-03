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
    long long n, k;
    cin >> n >> k;
    vector<long long> d(n);
    long long sol = k + n;
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
        if (i) {
            sol += min(d[i] - d[i - 1] - 1, k);
        }
    }
    cout << sol << "\n";
    return 0;
}

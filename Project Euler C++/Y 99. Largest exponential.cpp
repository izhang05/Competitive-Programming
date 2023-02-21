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

pair<pair<int, int>, int> mx(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    long double val = b.first.second * (log(b.first.first) / log(a.first.first));
    if (a.first.second > val) {
        return a;
    } else {
        return b;
    }
}


int main() {
    freopen("Y 99.in", "r", stdin);
    int n = 1000;
    pair<pair<int, int>, int> sol;
    for (int i = 0; i < n; ++i) {
        long double a, b;
        cin >> a >> b;
        sol = mx(sol, {{a, b}, i + 1});
    }
    cout << sol.second << "\n";
    return 0;
}

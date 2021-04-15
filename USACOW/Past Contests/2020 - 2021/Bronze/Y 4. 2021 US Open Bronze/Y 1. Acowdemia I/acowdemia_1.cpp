
#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    freopen("1.out", "w", stderr);
#endif
}
//#define DEBUG
int n, l;
vector<int> a;

bool check(int x) {
    int cur = 0;
    for (int i = 0; i < x; ++i) {
        if (a[i] < x - 1) {
            return false;
        }
        cur += max(0, x - a[i]);
    }
    return cur <= l;
}

int main() {
    setIO();
    cin >> n >> l;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    int lo = 0, hi = n, mid, sol = -1;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (check(mid)) {
            sol = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    cout << sol << "\n";
    return 0;
}

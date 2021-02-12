#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}


int main() {
    setIO();

    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int j = 1, cur = a[0], sol = 0;
    for (int i = 0; i < n; ++i) {
        while (cur + a[j] <= x) {
            cur += a[j];
            ++j;
            if (j == n) {
                break;
            }
        }
        sol += cur == x;
        if (j == n) {
            break;
        }
        cur -= a[i];
    }
    cout << sol << "\n";
    return 0;
}

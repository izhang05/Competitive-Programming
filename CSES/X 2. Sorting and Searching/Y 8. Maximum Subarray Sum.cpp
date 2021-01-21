#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}


int main() {
    setIO();

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    long long sol = -1e9, left = 0, cur = a[0];
    for (int i = 1; i < n; ++i) {
        cur += a[i];
        while (cur < a[i]) {
            cur -= a[left];
            ++left;
        }
        sol = max(sol, cur);
    }
    cout << max(sol, cur) << "\n";
    return 0;
}

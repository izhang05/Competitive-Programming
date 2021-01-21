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

int solve(int n) {
    int sol = 1, cur = 0;
    while (n % 2 == 0) {
        n /= 2;
        ++cur;
    }
    sol *= cur + 1;
    for (int i = 3; i * i <= n; i += 2) {
        cur = 0;
        while (n % i == 0) {
            n /= i;
            ++cur;
        }
        sol *= cur + 1;
        if (n == 1) {
            break;
        }
    }
    if (n != 1) {
        sol *= 2;
    }
    return sol;
}

int main() {
    setIO();

    int n, x;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        cout << solve(x) << "\n";
    }
    return 0;
}

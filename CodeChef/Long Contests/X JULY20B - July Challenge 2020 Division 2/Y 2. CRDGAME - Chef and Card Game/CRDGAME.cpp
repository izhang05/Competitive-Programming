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


long long sum(int n) {
    long long sol = 0;
    while (n) {
        sol += n % 10;
        n /= 10;
    }
    return sol;
}


int main() {
    setIO();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a_sol = 0, b_sol = 0;
        int a, b;
        for (int i = 0; i < n; ++i) {
            cin >> a >> b;
            if (sum(a) > sum(b)) {
                ++a_sol;
            } else if (sum(b) > sum(a)) {
                ++b_sol;
            } else {
                ++a_sol;
                ++b_sol;
            }
        }
        if (a_sol > b_sol) {
            cout << 0 << " " << a_sol << "\n";
        } else if (b_sol > a_sol) {
            cout << 1 << " " << b_sol << "\n";
        } else {
            cout << 2 << " " << a_sol << "\n";
        }
    }
    return 0;
}

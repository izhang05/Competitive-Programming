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
    vector<int> apples(n);
    for (int i = 0; i < n; ++i) {
        cin >> apples[i];
    }
    long long sol = 1e18;
    for (unsigned int mask = 0; mask < (1u << n); ++mask) {
        long long one = 0, two = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                one += apples[i];
            } else {
                two += apples[i];
            }
        }
        sol = min(sol, abs(one - two));
    }
    cout << sol << "\n";
    return 0;
}

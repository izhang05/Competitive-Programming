#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
    long long a, b;
    cin >> a >> b;
    long long solution;
    if (b - a >= 5) {
        solution = 0;
    } else {
        solution = 1;
        for (long long i = a + 1; i < b + 1; ++i) {
            solution *= i % 10;
            solution %= 10;
        }
    }
    cout << solution << "\n";

    return 0;
}

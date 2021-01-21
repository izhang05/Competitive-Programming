#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
    int t;
    cin >> t;
    long long n, a, b, c;
    while (t--) {
        long long solution;
        cin >> n >> a >> b >> c;
        int f[n];
        for (int i = 0; i < n; ++i) {
            cin >> f[i];
        }
        solution = abs(a - f[0]) + abs(b - f[0]) + c;
        for (int i : f) {
            solution = min(solution, abs(a - i) + abs(b - i) + c);
        }
        cout << solution << "\n";
    }
    return 0;
}

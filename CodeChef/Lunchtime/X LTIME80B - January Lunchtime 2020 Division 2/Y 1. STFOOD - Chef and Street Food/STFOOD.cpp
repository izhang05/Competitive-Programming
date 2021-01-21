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
    while (t--) {
        int solution = 0;
        int n;
        cin >> n;
        int s, p, v;
        for (int i = 0; i < n; ++i) {
            cin >> s >> p >> v;
            solution = max(solution, (p / (s + 1)) * v);
        }
        cout << solution << "\n";
    }
    return 0;
}

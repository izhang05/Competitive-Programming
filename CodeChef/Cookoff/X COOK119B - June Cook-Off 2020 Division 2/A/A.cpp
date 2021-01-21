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

    int t;
    cin >> t;
    while (t--) {
        int n, b, m;
        cin >> n >> b >> m;
        vector<int> x(m);
        for (int i = 0; i < m; ++i) {
            cin >> x[i];
        }
        int sol = 1, pre = x[0] / b;
        for (int i = 1; i < m; ++i) {
            if (x[i] / b != pre) {
                ++sol;
                pre = x[i] / b;
            }
        }
        cout << sol << "\n";
    }
    return 0;
}

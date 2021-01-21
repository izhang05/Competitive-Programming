#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<vector<int> > prices(n);
        vector<vector<int> > discounts(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int p;
                cin >> p;
                prices[i].push_back(p);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int p;
                cin >> p;
                discounts[i].push_back(p);
            }
        }

    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> w(n);
        for (int i = 0; i < n; ++i) {
            cin >> w[i];
        }
        vector<pair<int, int> > f(m);
        for (int i = 0; i < m; ++i) {
            cin >> f[i].first >> f[i].second;
        }

    }
    return 0;
}

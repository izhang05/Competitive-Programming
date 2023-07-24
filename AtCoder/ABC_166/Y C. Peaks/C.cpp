#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
//    freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
    int n, m;
    cin >> n >> m;
    vector<int> obs(n);
    set<int> bad;
    for (int i = 0; i < n; ++i) {
        cin >> obs[i];
    }
    int a, b, ah, bh;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        ah = obs[a - 1], bh = obs[b - 1];
        if (ah == bh) {
            bad.insert(a), bad.insert(b);
        } else if (ah > bh) {
            bad.insert(b);
        } else {
            bad.insert(a);
        }
    }
    cout << n - bad.size() << "\n";

    return 0;
}

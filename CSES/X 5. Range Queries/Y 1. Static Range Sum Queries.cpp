#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}


int main() {
    setIO();
    int n, q;
    cin >> n >> q;
    vector<long long> pre(n + 1, 0);
    int a;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        pre[i + 1] = pre[i] + a;
    }
    int b;
    for (int i = 0; i < q; ++i) {
        cin >> a >> b;
        cout << pre[b] - pre[a - 1] << "\n";
    }
    return 0;
}

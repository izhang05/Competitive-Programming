#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    vector<int> x(n);
    x[0] = 1;
    cout << b[0];
    int m = b[0];
    for (int i = 1; i < n; ++i) {
        x[i] = m;
        cout << " " << b[i] + x[i];
        m = max(m, b[i] + x[i]);
    }
    return 0;
}

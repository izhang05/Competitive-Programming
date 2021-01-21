#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}


int main() {
    setIO();
    int x, n;
    cin >> x >> n;
    long long sol = 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<>());
    for (int i = 0; i < n - 1; ++i) {
        sol += x;
        x -= a[i];
    }
    cout << sol << "\n";
    return 0;
}

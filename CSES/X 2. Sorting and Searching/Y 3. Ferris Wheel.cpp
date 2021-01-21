#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}


int main() {
    setIO();

    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int i = 0, j = n - 1, sol = 0;
    while (i <= j) {
        if (a[i] + a[j] <= x) {
            ++i;
        }
        --j, ++sol;
    }
    cout << sol << "\n";
    return 0;
}

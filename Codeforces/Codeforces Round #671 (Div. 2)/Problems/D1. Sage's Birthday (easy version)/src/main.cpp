#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if (n == 1) {
        cout << 0 << "\n";
        cout << a[0] << "\n";
        return 0;
    }
    if (n == 2) {
        cout << 0 << "\n";
        cout << a[0] << " " << a[1] << "\n";
        return 0;
    }
    int num = (n - 1) / 2;
    cout << num << "\n";
    vector<int> cheap(num);
    for (int i = 0; i < num; ++i) {
        cheap[i] = a[i];
    }
    a.erase(a.begin(), a.begin() + num);
    cout << a[0];
    cout << " " << cheap[0];
    for (int i = 1; i < a.size(); ++i) {
        cout << " " << a[i];
        if (i < num) {
            cout << " " << cheap[i];
        }
    }
    return 0;
}

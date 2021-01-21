#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int> unlocked;
        bool b[n];
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
            if (!b[i]) {
                unlocked.push_back(a[i]);
            }
        }
        sort(unlocked.begin(), unlocked.end(), greater<>());
        int j = 0;
        if (b[0]) {
            cout << a[0];
        } else {
            cout << unlocked[j++];
        }
        for (int i = 1; i < n; ++i) {
            if (b[i]) {
                cout << " " << a[i];
            } else {
                cout << " " << unlocked[j++];
            }
        }
        cout << "\n";
    }
    return 0;
}

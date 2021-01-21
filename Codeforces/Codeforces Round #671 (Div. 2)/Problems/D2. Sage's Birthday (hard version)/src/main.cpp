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

    int low = 0, high = n, mid, sol;
    while (low <= high) {
        mid = (low + high) / 2;
        if (mid > (n - 1) / 2) {
            high = mid - 1;
            continue;
        }
        bool pos = true;
        int j = n - mid;
        for (int i = 0; i < mid; ++i) {
            if (a[i] >= a[j++]) {
                pos = false;
                break;
            }
        }
        if (pos) {
            low = mid + 1;
            sol = mid;
        } else {
            high = mid - 1;
        }
    }
    cout << sol << "\n";
    cout << a[sol];
    if (sol == 0) {
        for (int i = 1; i < n; ++i) {
            cout << " " << a[i];
        }
        return 0;
    }
    for (int i = sol + 1; i < n - sol; ++i) {
        cout << " " << a[i];
    }
    for (int i = 0; i < sol; ++i) {
        cout << " " << a[i];
        cout << " " << a[i + n - sol];
    }
    return 0;
}

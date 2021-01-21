//#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

vector<int> a;
int n, x;

bool possible(int len) {
    int sum = 0;
    for (int i = 0; i < len; ++i) {
        sum += a[i];
    }
    if (sum % x != 0) {
        return true;
    }
    for (int i = 0; i + len < n; ++i) {
        sum -= a[i];
        sum += a[i + len];
        if (sum % x != 0) {
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> x;
        a.resize(n);
        int num;
        bool pos = false;
        for (int i = 0; i < n; ++i) {
            cin >> num;
            if (num % x != 0)
                pos = true;
            a[i] = num % x;
        }
        if (!pos) {
            cout << -1 << "\n";
        } else {
            for (int i = n; i >= 0; --i) {
                if (possible(i)) {
                    cout << i << endl;
                    break;
                }
            }
        }
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        string a;
        cin >> a;
        string b;
        b += a[0];
        for (int i = 1; i < a.size() - 1; i += 2) {
            b += a[i];
        }
        b += a[a.size() - 1];
        cout << b << "\n";
    }
    return 0;
}

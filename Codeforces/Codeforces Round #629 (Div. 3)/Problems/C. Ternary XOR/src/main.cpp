#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, n;
    string x, a, b;
    cin >> t;
    bool different;
    while (t--) {
        different = false;
        a = "", b = "";
        cin >> n >> x;
        for (char i : x) {
            if (i == '0') {
                a += '0';
                b += '0';
            } else if (i == '1') {
                if (different) {
                    a += '0';
                    b += '1';
                } else {
                    different = true;
                    a += '1';
                    b += '0';
                }
            } else if (i == '2') {
                if (different) {
                    a += '0';
                    b += '2';
                } else {
                    a += '1';
                    b += '1';
                }
            }
        }
        cout << a << "\n";
        cout << b << "\n";
    }
    return 0;
}

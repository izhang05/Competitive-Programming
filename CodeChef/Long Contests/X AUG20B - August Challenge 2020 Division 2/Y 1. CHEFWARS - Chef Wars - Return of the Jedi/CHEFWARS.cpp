#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    //freopen("1.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}


int main() {
    setIO();

    int t;
    cin >> t;
    while (t--) {
        int h, p;
        cin >> h >> p;
        while (p) {
            h -= p;
            p /= 2;
        }
        cout << (h <= 0) << "\n";
    }
    return 0;
}

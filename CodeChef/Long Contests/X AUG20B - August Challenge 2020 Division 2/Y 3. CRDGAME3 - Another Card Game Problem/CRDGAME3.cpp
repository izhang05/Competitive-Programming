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
        int c, r;
        cin >> c >> r;
        int pc = (c + 8) / 9, rc = (r + 8) / 9;
        cout << (pc >= rc) << " ";
        cout << min(pc, rc) << "\n";
    }
    return 0;
}

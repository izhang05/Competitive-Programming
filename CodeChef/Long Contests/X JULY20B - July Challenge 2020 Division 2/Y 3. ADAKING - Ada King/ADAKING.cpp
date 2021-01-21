#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}


int main() {
    setIO();

    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        int count = 0;
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (i == 7 && j == 7) {
                    cout << "O";
                } else if (count < 64 - k) {
                    ++count;
                    cout << "X";
                } else {
                    cout << ".";
                }
            }
            cout << "\n";
        }
    }
    return 0;
}

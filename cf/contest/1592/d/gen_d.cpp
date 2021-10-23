#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("in1.txt", "w", stdout);
    cout << 850 << "\n";
    cout << "1 2 2\n"
            "1 3 1\n"
            "1 4 1\n"
            "4 5 1\n"
            "5 6 1\n"
            "5 7 1\n"
            "4 8 1\n"
            "8 9 1\n"
            "8 10 1\n";

    int c = 4, next = 11;
    for (int i = 0; i < 4; ++i) {
        int sz = next - 1;
        cout << c << " " << next << " " << 1 << "\n";
        c = next;
        ++next;
        for (int j = 0; j < 2; ++j) {
            int cur = next;
            cout << c << " " << next++ << " " << 1 << "\n";
//            if (j == 1) {
//                ++sz;
//            }
            for (int k = 0; k < sz - 1; ++k) {
                cout << cur << " " << next++ << " " << 1 << "\n";
            }
        }
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int num = 0;
        bool turn = false, found = false;
        while (true) {
//            cout << s << "\n";
            found = false;
            char pre = s[0];
            for (int i = 1; i < s.size(); ++i) {
                if (s[i] != pre) {
                    turn = !turn;
                    s.erase(s.begin() + i - 1, s.begin() + i + 1);
                    found = true;
                    break;
                }
            }
            if (!found) {
                break;
            }
        }
        if (turn) {
            cout << "DA" << "\n";
        } else {
            cout << "NET" << "\n";
        }
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}


int main() {
    setIO();
    int t;
    cin >> t;
    while (t--) {
        string s, p;
        cin >> s >> p;
        multiset<char> letters;
        for (char i : s) {
            letters.insert(i);
        }
        for (char i : p) {
            letters.erase(letters.find(i));
        }
        int i = 1;
        while (p[i] == p[0]) {
            ++i;
            if (i == p.size()) {
                break;
            }
        }
        if (p[i] >= p[0]) {
            while (*letters.begin() <= p[0]) {
                cout << *letters.begin();
                letters.erase(letters.begin());
                if (letters.empty()) {
                    break;
                }
            }
            cout << p;
            for (char j : letters) {
                cout << j;
            }
        } else {
            while (*letters.begin() < p[0]) {
                cout << *letters.begin();
                letters.erase(letters.begin());
                if (letters.empty()) {
                    break;
                }
            }
            cout << p;
            for (char j : letters) {
                cout << j;
            }
        }
        cout << "\n";
    }
    return 0;
}

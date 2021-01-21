#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int sol = 0, cur = 0, first = 0;
        char pre = s[0];
        bool lose = true;
        vector<int> sections;
        if (pre == 'W') {
            ++sol;
            lose = false;
        } else {
            first = 1;
        }
        for (int i = 1; i < n; ++i) {
            if (s[i] == 'W') {
                lose = false;
                if (pre == 'W') {
                    sol += 2;
                } else {
                    sol += 1;
                    pre = 'W';
                }
                sections.push_back(cur);
                cur = 0;
            } else {
                pre = 'L';
                if (lose) {
                    first += 1;
                } else {
                    cur += 1;
                }
            }
        }
        sort(sections.begin(), sections.end());
        for (int i : sections) {
            if (i > 0) {
                if (k - i >= 0) {
                    sol += 2 * i + 1;
                    k -= i;
                } else {
                    sol += 2 * k;
                    k = 0;
                    break;
                }
            }
        }
//        cout << sol << " " << first + cur << " " << k << "\n";
        if (lose) {
            cout << max(0, min(k, first) * 2 - 1) << "\n";
        } else {
            sol += min(k, first + cur) * 2;
            cout << sol << "\n";
        }
    }
    return 0;
}

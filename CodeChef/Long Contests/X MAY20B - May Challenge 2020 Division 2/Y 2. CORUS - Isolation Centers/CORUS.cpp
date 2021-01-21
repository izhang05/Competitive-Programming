#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int main() {
//    freopen("solution.out", "w", stdout);
//    freopen("4.in", "r", stdin);
    int t, n, q;
    string s;
    cin >> t;
    while (t--) {
        cin >> n >> q;
        cin >> s;
        map<char, int> frequency;
        for (char i : s) {
            if (frequency.count(i) == 0) {
                frequency[i] = 1;
            } else {
                ++frequency[i];
            }
        }
        long long c, solution;
        for (int i = 0; i < q; ++i) {
            solution = 0;
            cin >> c;
            if (c >= n) {
                cout << 0 << "\n";
            } else {
                for (pair<char, int> j : frequency) {
                    solution += max(0, (int) (j.second - c));
                }
                cout << solution << "\n";
            }
        }
    }
    return 0;
}

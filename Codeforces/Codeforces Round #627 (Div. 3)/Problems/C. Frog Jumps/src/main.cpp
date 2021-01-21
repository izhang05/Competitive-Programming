#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    string s;
    cin >> t;
    while (t--) {
        int solution = 0, current_distance = 1, position = 0;
        cin >> s;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'R') {
                solution = max(solution, current_distance);
                position = i;
                current_distance = 1;
            } else {
                ++current_distance;
            }
        }
        cout << max(solution, current_distance) << "\n";
    }
    return 0;
}

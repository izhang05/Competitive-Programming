#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size(), sol = 0;
    char cur = s[0];
    int cur_sol = 1;
    for (int i = 1; i < n; ++i) {
        if (s[i] == cur) {
            ++cur_sol;
        } else {
            cur = s[i];
            sol = max(sol, cur_sol);
            cur_sol = 1;
        }
    }
    cout << max(sol, cur_sol) << "\n";
    return 0;
}

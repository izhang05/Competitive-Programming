#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        map<char, int> occ;
        map<char, bool> kept;
        for (auto i : s) {
            ++occ[i];
            kept[i] = false;
        }
        string sol;
        for (int i = 0; i < n; ++i) {
            if (i == n - 1) {
                if (occ[s[i]] == 1) {
                    sol += s[i];
                }
                break;
            }
            if (occ[s[i]] == 1) {
                sol += s[i];
            } else {
                if (s[i] <= s[i + 1] || kept[s[i]]) {
                    --occ[s[i]];
                    while (!sol.empty() && sol.back() <= s[i + 1] && occ[sol.back()] > 1) {
                        --occ[sol.back()];
                        kept[sol.back()] = false;
                        sol.back();
                    }
                } else {
                    sol += s[i];
                    kept[s[i]] = true;
                }
            }
        }
//        if (sol.size() != occ.size()) {
//            throw;
//        }
        cout << sol << "\n";
    }
    return 0;
}

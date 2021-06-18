#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int n, k;
    cin >> n >> k;
    string sol, s, cur;
    cin >> s;
    bool pos = true;
    cur += s[0];
    sol += s[0];
    for (int i = 1; i < n; ++i) {
        cur += s[i];
        if (s[i] < s[0]) {
            sol = cur;
        } else if ((s[i] == s[0]) && pos) {
            sol = cur;
        }
        if (s[i] > s[i - 1]) {
            pos = false;
        }
    }

    while (int(sol.size()) < k) {
        sol += sol;
    }
    while (int(sol.size()) > k) {
        sol.pop_back();
    }
    cout << sol << "\n";
    return 0;
}

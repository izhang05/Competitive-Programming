#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int n, k;
    cin >> n >> k;
    string sol, s;
    cin >> s;
    for (int i = 0; i < k; ++i) {
        sol += s[0];
    }
    string cur;
    for (int i = 0; i < n; ++i) {
        cur += s[i];
        string pos = cur;
        while (int(pos.size()) < k) {
            pos += pos;
        }
        while (int(pos.size()) > k) {
            pos.pop_back();
        }
        sol = min(sol, pos);
    }
    cout << sol << "\n";
    return 0;
}

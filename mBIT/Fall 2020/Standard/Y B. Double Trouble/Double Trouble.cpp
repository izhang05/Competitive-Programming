#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
//freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}


int main() {
    setIO();

    string s;
    getline(cin, s);
    string sol;
    int n = s.size();
    char cur;
    for (int i = 0; i < n; ++i) {
        cur = s[i];
        int num = 0;
        while (i != n && s[i] == cur) {
            ++num, ++i;
        }
        --i;
        if (num != 2) {
            for (int j = 0; j < num; ++j) {
                sol += cur;
            }
        } else {
            sol += cur;
        }
    }
    cout << sol << "\n";
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    //freopen("solution.out", "w", stdout);
    freopen("4.in", "r", stdin);
#endif

    int n, d;
    cin >> n >> d;
    string s;
    cin >> s;
    int sol = 1;
    int i = 0;
    bool found;
    while (i + d < n - 1) {
        found = false;
        for (int j = i + d; j > i; --j) {
            if (s[j] - '0') {
                i = j;
                ++sol;
                found = true;
                break;
            }
        }
        if (!found) {
            sol = -1;
            break;
        }
    }
    cout << sol << "\n";
    return 0;
}

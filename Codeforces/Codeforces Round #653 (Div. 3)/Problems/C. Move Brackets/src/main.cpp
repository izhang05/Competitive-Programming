#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int depth = 0;
        int sol = 0;
        for (char i : s) {
            if (i == '(') {
                ++depth;
            } else {
                --depth;
                if (depth < 0) {
                    depth = 0;
                    ++sol;
                }
            }
        }
        cout << sol << "\n";
    }
    return 0;
}

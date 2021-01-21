#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        multiset<int> a;
        int b;
        for (int i = 0; i < n; ++i) {
            cin >> b;
            a.insert(b);
        }
        int sol = 0, found = 0;
        for (int i = 0; i < n + 2; ++i) {
            if (a.count(i) == 0) {
                if (found == 1) {
                    sol += i;
                } else {
                    sol += 2 * i;
                }
                break;
            } else if (a.count(i) == 1) {
                if (found == 0) {
                    sol += i;
                    if (++found == 2) {
                        break;
                    }
                }
            }
        }
        cout << sol << "\n";
    }
    return 0;
}

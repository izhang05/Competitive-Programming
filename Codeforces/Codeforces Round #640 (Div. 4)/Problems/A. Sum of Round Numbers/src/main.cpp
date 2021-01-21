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
        vector<int> ans;
        int p = 1;
        while (n) {
            if (n % 10) {
                ans.push_back(n % 10 * p);
            }
            n /= 10;
            p *= 10;
        }
        cout << ans.size() << "\n";
        for (int i : ans) {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}

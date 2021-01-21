#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s1, s2;
        cin >> s1 >> s2;
        map<char, int> a, b;
        for (int i = 0; i < n; ++i) {
            ++a[s1[i]];
            ++b[s2[i]];
        }
        bool sol = true;
        for (char i = 'a'; i < 'z' + 1; ++i) {
            if (a[i] < b[i] || (a[i] -= b[i]) % k != 0) {
                sol = false;
                break;
            }
            a[i + 1] += a[i];
        }
        cout << (sol ? "Yes" : "No") << "\n";
    }
    return 0;
}

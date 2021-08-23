/* Author: izhang05
 * Time: 08-23-2021 18:31:48
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
}

int main() {
    setIO("");
    string s;
    cin >> s;
    int n = int(s.size()), pre = -1;
    long long sol = 0;
    for (int i = 2; i < n; ++i) {
        int cur = pre;
        for (int k = 1; i - 2 * k > cur; ++k) {
            if (s[i] == s[i - k] && s[i] == s[i - 2 * k]) {
                cur = i - 2 * k;
            }
        }
        sol += cur + 1;
        pre = cur;
    }
    cout << sol << "\n";
    return 0;
}

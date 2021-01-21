/*
ID: izhang01
TASK: cowcode
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;
string s;

void solve(long long n) {
    if (n <= s.size()) {
        cout << s[n - 1] << "\n";
        return;
    }
    long long x = s.size();
    while (x < n) {
        x *= 2;
    }
    x /= 2;
    if (x + 1 == n) {
        solve(n - 1);
    } else {
        solve(max((long long) 1, n % x - 1));
    }

}

int main() {
    freopen("cowcode.in", "r", stdin);
    freopen("cowcode.out", "w", stdout);
    long long n;
    cin >> s >> n;
    if (s.size() == 1) {
        cout << s << "\n";
    } else {
        solve(n);
    }

    return 0;
}

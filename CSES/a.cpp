#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(string name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}

const int mod = 1e9 + 7, maxn = 1e5 + 5;

int n;

int solve(string s, string t) {
    int i = 0;
    while (i < n && s[i] == t[i]) {
        ++i;
    }
    int j = n - 1;
    while (j >= 0 && s[j] == t[j]) {
        --j;
    }
    string a;
    for (int k = i + 1; k < j + 1; ++k) {
        a += s[k];
    }
    string b;
    for (int k = i; k < j; ++k) {
        b += t[k];
    }
    return a == b;
}

int main() {
    setIO("1");
    cin >> n;
    string s, t;
    cin >> s >> t;
    cout << solve(s, t) + solve(t, s) << "\n";
    return 0;
}


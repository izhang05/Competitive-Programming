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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;


int main() {
    setIO("1");

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> a(n);
        int pre = 0;
        map<int, long long> vals;
        for (int i = 0; i < n; ++i) {
            a[i] = s[i] - '0';
            pre += a[i];
            ++vals[pre - (i + 1)];
        }
        ++vals[0];
        long long sol = 0;
        for (auto i : vals) {
#ifdef DEBUG
            cout << i.first << " " << i.second << "\n";
#endif
            sol += (i.second * (i.second - 1)) / 2;
        }
        cout << sol << "\n";
    }
    return 0;
}

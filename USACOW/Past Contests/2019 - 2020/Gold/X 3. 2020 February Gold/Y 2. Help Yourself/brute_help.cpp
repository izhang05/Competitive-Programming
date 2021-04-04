/*
ID: izhang01
TASK: brute_help
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
//    freopen("help.in", "r", stdin);
//    freopen("help.out", "w", stdout);
//    freopen("help.out", "w", stderr);
}
//#define DEBUG
const int mod = 1e9 + 7;

int main() {
    setIO();
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    long long sol = 0;
    for (int i = 1; i < (1 << n); ++i) {
        vector<pair<int, int>> b;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                b.push_back(a[j]);
            }
        }
        sort(b.begin(), b.end());
        int cur = b.size();
        int mx = b[0].second;
        for (int j = 1; j < (int) b.size(); ++j) {
            if (b[j].first < mx) {
                --cur;
            }
            mx = max(mx, b[j].second);
        }
        sol += cur;
    }
    cout << sol << "\n";
    return 0;
}

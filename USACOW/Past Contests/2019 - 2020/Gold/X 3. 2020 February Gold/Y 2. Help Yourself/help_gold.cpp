/*
ID: izhang01
TASK: help
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    freopen("help.in", "r", stdin);
    freopen("help.out", "w", stdout);
    freopen("help.out", "w", stderr);
}
//#define DEBUG
const int mod = 1e9 + 7, maxn = 1e5 + 5;

long long p[maxn];

int main() {
    setIO();
    p[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        p[i] = (2 * p[i - 1]) % mod;
    }
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());
    vector<int> cover(n);
    priority_queue<int, vector<int>, greater<>> q;
    for (int i = 0; i < n; ++i) {
        while (!q.empty() && q.top() < a[i].first) {
            q.pop();
        }
        cover[i] = q.size();
        q.push(a[i].second);
    }
    long long sol = 0;
    for (int i = n - 1; i >= 0; --i) {
        sol += p[n - cover[i] - 1] % mod;
        sol %= mod;
    }
#ifdef DEBUG
    cout << "dp:"
         << "\n";
    for (int i = 0; i < n; ++i) {
        cout << dp[i] << " ";
    }
    cout << "\n";
    cout << "cover:"
         << "\n";
    for (int i = 0; i < n; ++i) {
        cout << cover[i] << " ";
    }
    cout << "\n";

#endif
    cout << sol << "\n";
    return 0;
}

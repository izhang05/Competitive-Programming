#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
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
#define int long long

signed main() {
    setIO("1");

    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<>> q;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        q.push(a);
    }
    if (n % 2 == 0) {
        ++n;
        q.push(0);
    }
    int sol = 0;
    while (q.size() > 1) {
        int cur = 0;
        for (int i = 0; i < 3; ++i) {
            int t = q.top();
            q.pop();
            cur += t;
        }
        sol += cur;
        q.push(cur);
    }
    cout << sol << "\n";
    return 0;
}

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


int main() {
    setIO("1");

    int n, x;
    cin >> n >> x;
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        sum += a;
    }
    if (sum + n - 1 == x) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
    return 0;
}

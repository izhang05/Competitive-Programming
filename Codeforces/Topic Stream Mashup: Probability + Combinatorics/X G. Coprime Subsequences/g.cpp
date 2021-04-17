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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;
long long p[maxn];

map<int, int> fact(int x) {
    map<int, int> cur;
    while (x % 2 == 0) {
        ++cur[2];
        x /= 2;
    }
    for (int i = 3; i * i <= x; i += 2) {
        while (x % i == 0) {
            ++cur[i];
            x /= i;
        }
    }
    if (x != 1) {
        ++cur[x];
    }
    return cur;
}

int main() {
    setIO("1");
    p[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        p[i] = (p[i - 1] * 2) % mod;
    }
    int n;
    cin >> n;
    map<int, int> occ;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
#ifdef DEBUG
        cout << a << ":"  << "\n";
#endif
        map<int, int> cur = fact(a);
        for (auto j : cur) {
#ifdef DEBUG
            cout << j.first << " " << j.second << "\n";
#endif
            ++occ[j.first];
        }
    }
#ifdef DEBUG
    cout << "\n";
#endif
    long long sol = p[n] - 1;
    for (auto i : occ) {
#ifdef DEBUG
        cout << i.first << " " << i.second << "\n";
#endif
        sol -= p[i.second] - 1;
        sol %= mod;
    }
    cout << (sol + mod) % mod << "\n";
    return 0;
}

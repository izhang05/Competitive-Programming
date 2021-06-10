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

long long binpow(long long x, long long n, long long m) {
    assert(n >= 0);
    x %= m;
    long long res = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            res = res * x % m;
        }
        x = x * x % m;
        n /= 2;
    }
    return res;
}

map<int, int> factor(int x) {
    map<int, int> res;
    while (x % 2 == 0) {
        ++res[2];
        x /= 2;
    }
    for (int i = 3; i * i <= x; i += 2) {
        while (x % i == 0) {
            ++res[i];
            x /= i;
        }
    }
    if (x > 1) {
        ++res[x];
    }
    return res;
}

int main() {
    setIO("c");

    int n;
    cin >> n;
    map<int, multiset<int>> occ;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        map<int, int> cur = factor(a);
        for (auto &j : cur) {
            occ[j.first].insert(j.second);
        }
    }
    for (auto &i : occ) {
        for (int j = 0; j < 2 && (int) i.second.size() < n; ++j) {
            i.second.insert(0);
        }
    }
    long long sol = 1;
    for (auto &i : occ) {
        sol *= binpow(i.first, *next(i.second.begin()), mod);
    }
    cout << sol << "\n";
    return 0;
}

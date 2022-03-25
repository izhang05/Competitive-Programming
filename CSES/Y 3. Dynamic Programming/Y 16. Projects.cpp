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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 5e5 + 5;

struct project {
    int st, en, p;
    bool operator<(const project &rhs) const {
        return en < rhs.en;
    }
};
long long dp[maxn];
vector<pair<int, int>> occ[maxn];

int main() {
    setIO("16");
    int n;
    cin >> n;
    vector<project> a(n);
    set<int> times;
    for (auto &i : a) {
        cin >> i.st >> i.en >> i.p;
        times.insert(i.st);
        times.insert(i.en);
    }
    map<int, int> ind;
    int m = 1;
    for (auto &i : times) {
        ind[i] = m++;
    }
    for (auto &i : a) {
        occ[ind[i.en]].emplace_back(ind[i.st], i.p);
    }
    for (int i = 1; i < m; ++i) {
        dp[i] = dp[i - 1];
        for (auto &j : occ[i]) {
            dp[i] = max(dp[i], dp[j.first - 1] + j.second);
        }
    }
    cout << dp[m - 1] << "\n";
    return 0;
}

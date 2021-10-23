/* Author: izhang05
 * Time: 07-17-2021 16:00:58
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifndef TEST
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long rnd(long long l, long long r) {
    return uniform_int_distribution<long long>(l, r)(rng);
}

int lis(const vector<int> &a) {
    vector<int> dp;
    for (int i : a) {
        int pos = upper_bound(dp.begin(), dp.end(), i) - dp.begin();
        if (pos == (int) dp.size()) {
            dp.push_back(i);
        } else {
            dp[pos] = i;
        }
    }
    return (int) dp.size();
}

long double p(int old, int cur, long double temp) {
    if (cur > old) {
        return 1.0;
    }
    return exp((cur - old) / temp);
}
int n;
vector<int> a;

int val(long long state) {
    vector<int> cur(a.begin(), a.end()), pos;
    for (int j = 0; j < n; ++j) {
        if (state & (1ll << j)) {
            pos.push_back(j);
        }
    }
    int j = 0, k = pos.size() - 1;
    while (j <= k) {
        swap(cur[pos[j]], cur[pos[k]]);
        ++j, --k;
    }
    return lis(cur);
}

int main() {
    setIO("subrev");
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    long double temp = 1e4, r = 0.9999;
    long long state = rnd(1, (1ll << n));
    int sol = 0;
    uniform_real_distribution<double> d(0.0, 1.0);
    while (temp > 1e-10) {
        int change = rnd(0, n - 1);
        long long cur = state;
        cur ^= (1ll << change);
        int cur_val = val(state);
        sol = max(sol, cur_val);
        if (d(rng) < p(cur_val, val(cur), temp)) {
            state = cur;
        }
        temp *= r;
    }
    cout << max(sol, val(state)) << "\n";
    return 0;
}

#include<bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b);++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct pass {
    long long p, d, c;
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, k;
    cin >> n >> k;
    vector<pair<long long, long long>> fares(n);
    for (int i = 0; i < n; ++i) {
        cin >> fares[i].first >> fares[i].second;
    }
    vector<pass> passes(k);
    for (int i = 0; i < k; ++i) {
        cin >> passes[i].p >> passes[i].d >> passes[i].c;
    }
    vector<long long> dp(n + 1, (long long) 1e18);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            int end = min(i + passes[j].d,
                          (long long) (
                                  lower_bound(fares.begin(), fares.end(),
                                              make_pair(fares[i].first + passes[j].p, -(long long) 1)) -
                                  fares.begin()));
            dp[end] = min(dp[end], dp[i] + passes[j].c);
        }
        dp[i + 1] = min(dp[i + 1], dp[i] + fares[i].second);
    }
    cout << dp[n] << "\n";
}

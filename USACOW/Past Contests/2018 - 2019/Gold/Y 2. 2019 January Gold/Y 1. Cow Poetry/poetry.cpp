/*
ID: izhang01
TASK: poetry
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("poetry.in", "r", stdin);
    freopen("poetry.out", "w", stdout);
}
//#define DEBUG



const int maxn = 5e3 + 5, maxk = 5e3 + 5, mod = 1e9 + 7;
long long dp[maxk], endings[maxn];

long long binpow(long long x, long long n) {
    assert(n >= 0);
    x %= mod;
    long long res = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            res = res * x % mod;
        }
        x = x * x % mod;
        n /= 2;
    }
    return res;
}

int main() {
    setIO();
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> words(n);
    for (int i = 0; i < n; ++i) {
        cin >> words[i].first >> words[i].second;
        --words[i].second;
    }
    sort(words.begin(), words.end());
    dp[0] = 1;
    for (int i = 0; i < k; ++i) {
        dp[i] %= mod;
        for (pair<int, int> j : words) {
            if (i + j.first <= k) {
                dp[i + j.first] += dp[i];
            } else {
                break;
            }
            if (i + j.first == k) {
                endings[j.second] += dp[i];
            }
        }
    }
#ifdef DEBUG
    cout << "DP: "
         << "\n";
    for (int j = 0; j < k + 1; ++j) {
        cout << dp[j] << " ";
    }
    cout << "\n";
    cout << "Endings: "
         << "\n";
    for (int i = 0; i < n; ++i) {
        cout << i << " " << endings[i] << "\n";
    }
    cout << "\n";
#endif
    long long sol = 1;
    map<char, int> occur;
    char c;
    for (int i = 0; i < m; ++i) {
        cin >> c;
        ++occur[c];
    }
    for (pair<char, int> i : occur) {
        long long cur = 0;
        for (int j = 0; j < n; ++j) {
#ifdef DEBUG
            cout << endings[j] << " " << i.second << " " << cur << " " << binpow(endings[j], i.second) << "\n";
#endif

            cur += binpow(endings[j], i.second);
            cur %= mod;
        }
        sol *= cur;
        sol %= mod;
#ifdef DEBUG
        cout << "\n";
        cout << i.first << " " << i.second << " " << cur << "\n";
        cout << sol << "\n";
        cout << "\n";
#endif
    }
    cout << sol << "\n";
    return 0;
}

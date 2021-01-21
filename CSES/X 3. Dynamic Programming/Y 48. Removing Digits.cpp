#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}
const int maxn = 1e6 + 1;
int dp[maxn];

int solve(int n) {
    if (dp[n] != 1e9) {
        return dp[n];
    }
    vector<int> digits;
    int &ref = dp[n];
    int num = n;
    while (num) {
        if (num % 10 != 0) {
            digits.push_back(num % 10);
        }
        num /= 10;
    }
    for (int i : digits) {
        if (n - i >= 0) {
            ref = min(ref, solve(n - i) + 1);
        }
    }
    return ref;
}

int main() {
    setIO();

    int n;
    cin >> n;
    for (int i = 0; i < n + 1; ++i) {
        dp[i] = 1e9;
    }
    dp[0] = 0;
    cout << solve(n) << "\n";
    return 0;
}

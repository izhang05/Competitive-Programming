#include <bits/stdc++.h>

using namespace std;

pair<int, int> factor(long long n) {
    pair<int, int> sol{0, 0};
    while (n % 2 == 0) {
        n /= 2;
        ++sol.first;
    }
    while (n % 5 == 0) {
        n /= 5;
        ++sol.second;
    }
    return sol;
}

const int maxn = 201;
int dp[maxn][maxn][maxn];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    long long a;
    vector<pair<int, int> > nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> a;
        nums[i] = factor(a);
    }
    dp[0][1][0]
    return 0;
}

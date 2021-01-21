#include <bits/stdc++.h>

using namespace std;

unordered_map<int, long long> profit{{0, 0},
                                     {1, 1}};

long long solve(int n) {
    if (profit.count(n)) {
        return profit[n];
    }
    long long a = solve(n / 2);
    if (!profit.count(n / 2)) {
        profit[n / 2] = max((long long) (n / 2), a);
    }
    long long b = solve(n / 3);
    if (!profit.count(n / 3)) {
        profit[n / 3] = max((long long) (n / 3), a);
    }
    long long c = solve(n / 4);
    if (!profit.count(n / 4)) {
        profit[n / 4] = max((long long) (n / 4), a);
    }
    if (!profit.count(n)) {
        profit[n] = max((long long) n, a + b + c);
    }
    return profit[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("solution.out", "w", stdout);
//    freopen("1.in", "r", stdin);
    int n;
    while (cin >> n) {
        cout << solve(n) << "\n";
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

long long solve(int n, int m) {
    if (n > m) {
        swap(n, m);
    }
    long long res = 0, tri = (m * (m + 1)) / 2;
    for (int i = 0; i < n; ++i) {
        res += (i + 1) * tri;
    }
    return res;
}

int main() {
    pair<long long, long long> sol{1e100, 1e100};
    long long goal = 2e6;
    for (int i = 1;; ++i) {
        bool first = false;
        for (int j = i;; ++j) {
            long long cur = solve(i, j);
            sol = min(sol, {abs(goal - cur), i * j});
            if (cur > goal) {
                if (j == i) {
                    first = true;
                }
                break;
            }
        }
        if (first) {
            break;
        }
    }
    cout << sol.second << "\n";
    return 0;
}

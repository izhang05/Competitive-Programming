#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    //    freopen("solution.out", "w", stdout);
        freopen("1.in", "r", stdin);
#endif
    int n, k;
    cin >> n >> k;
    set<int> snukes;
    int d, snuke;
    for (int i = 0; i < 2 * k; ++i) {
        cin >> d;
        for (int j = 0; j < d; ++j) {
            cin >> snuke;
            snukes.insert(snuke);
        }
    }
    int solution = 0;
    for (int i = 1; i < n + 1; ++i) {
        if (!snukes.count(i)) {
            ++solution;
        }
    }
    cout << solution
    << "\n";
}

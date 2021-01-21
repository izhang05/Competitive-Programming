#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    //    freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        int flavor, solution = 0, current = 0;
        set<int> unused;
        unordered_map<int, int> cakes;
        for (int i = 1; i < n + 1; ++i) {
            unused.insert(i);
            cakes[i] = 0;
        }
        for (int i = 0; i < n; ++i) {
            cin >> flavor;
            ++cakes[flavor];
            unused.erase(flavor);
            if (!unused.empty()) {
                ++current;
            } else {
                solution = max(solution, current);
                --current;
            }
        }

    }
    return 0;
}
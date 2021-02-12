#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}


int main() {
    setIO();

    int n, x, a;
    cin >> n >> x;
    unordered_map<int, int> ind;
    unordered_set<int> nums;
    bool half = false;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        nums.insert(a);
        if (a * 2 == x) {
            if (half) {
                cout << ind[a] << " " << i + 1 << "\n";
                return 0;
            } else {
                half = true;
            }
        }
        ind[a] = i + 1;
    }
    for (int i : nums) {
        if (2 * i == x) {
            continue;
        }
        if (nums.find(x - i) != nums.end()) {
            cout << ind[i] << " " << ind[x - i] << "\n";
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << "\n";
    return 0;
}

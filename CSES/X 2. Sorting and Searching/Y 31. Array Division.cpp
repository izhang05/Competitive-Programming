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

const int maxn = 2e5;
int n, k, nums[maxn];

bool pos(long long x) {
    long long cur = 0, used = 1;
    for (int i = 0; i < n; ++i) {
        if (nums[i] > x) {
            return false;
        }
        if (nums[i] + cur > x) {
            cur = nums[i];
            if (++used > k) {
                return false;
            }
        } else {
            cur += nums[i];
        }
    }
    return true;
}

int main() {
    setIO();
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    long long low = 0, high = 1e18, mid, sol;
    while (low <= high) {
        mid = (low + high) / 2;
        if (pos(mid)) {
            high = mid - 1;
            sol = mid;
        } else {
            low = mid + 1;
        }
    }
    cout << sol << "\n";
    return 0;
}

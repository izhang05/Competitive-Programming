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

const int maxn = 2e5;
long long n, t, nums[maxn];

bool pos(long long x) {
    long long made = 0;
    for (int i = 0; i < n; ++i) {
        made += x / nums[i];
        if (made >= t) {
            return true;
        }
    }
    return false;
}

int main() {
    setIO();

    cin >> n >> t;
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

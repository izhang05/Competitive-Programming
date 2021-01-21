#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
//    freopen("solution1.out", "w", stdout);
    freopen("4.in", "r", stdin);
#endif
}

long long tri(long long n) {
    return (n * (n + 1)) / 2;
}

int main() {
    setIO();

    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        if (n % 4 == 1 || n % 4 == 2) {
            cout << 0 << "\n";
            continue;
        }
        vector<int> nums(n);
        long long sol = 0, total = tri(n);
        for (int i = 0; i < n; ++i) {
            nums[i] = i + 1;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(nums[i], nums[j]);
                long long cur = 0;
                int k = 0;
                while (cur < total / 2) {
                    cur += nums[k++];
                }
                if (cur == total / 2) {
                    ++sol;
                }
                swap(nums[i], nums[j]);
            }
        }
        cout << sol << endl;
    }
    return 0;
}

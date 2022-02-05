#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 10;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        nums[i] = i + 1;
    }
    long double cnt = 0, sum = 0;
    do {
        long double cur = 0;
        ++cnt;
        for (int i = 0; i < n; i += 2) {
            cur += abs(nums[i] - nums[i + 1]);
        }
        sum += cur;
    } while (next_permutation(nums.begin(), nums.end()));
    cout << sum / cnt << "\n";
    return 0;
}

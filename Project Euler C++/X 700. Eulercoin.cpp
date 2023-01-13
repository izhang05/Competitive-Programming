#include <bits/stdc++.h>

using namespace std;

int main() {
    __int128 mod = 4503599627370517, a = 1504170715041707, three = 3 * a % mod;
    __int128 sol = a + 2 * a + three, mn = three;
    array<__int128, 3> nums{a, 2 * a, three};
    while (true) {
        __int128 mult = (mod - nums[0] + three - 1) / three;
        for (auto &i: nums) {
            i += (mult - 1) * three;
            i %= mod;
        }
        nums[0] += three;
        nums[0] %= mod;
        if (nums[0] < mn) {
            sol += nums[0];
            mn = nums[0];
            cout << (long long) nums[0] << " " << (long long) sol << endl;
        }
        __int128 mx = *max(nums.begin(), nums.end());
        if (nums[1] == mx) {
            rotate(nums.begin(), nums.begin() + 1, nums.end());
        } else if (nums[2] == mx) {
            nums[1] += three;
            if (nums[1] > mod) {
                nums[1] %= mod;
                if (nums[1] < mn) {
                    sol += nums[1];
                    mn = nums[1];
                    cout << (long long) nums[1] << " " << (long long) sol << endl;
                }
            }
            rotate(nums.begin(), nums.begin() + 2, nums.end());
        } else {
            nums[1] += three, nums[2] += three;
        }
        if (mn == 1) {
            break;
        }
    }
    cout << (long long) sol << "\n";
    return 0;
}

// 77 4527127597205114
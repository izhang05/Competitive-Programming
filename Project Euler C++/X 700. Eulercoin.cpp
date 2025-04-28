#include <bits/stdc++.h>

using namespace std;

int main() {
    long long mod = 4503599627370517, a = 1504170715041707, three = 3 * a % mod;
    long long sol = a + three, mn = three;
    array<long long, 3> nums{a, 2 * a, three};
    while (true) {
        long long mult = (mod - nums[0] + three - 1) / three;
        for (auto &i: nums) {
            i += (mult - 1) * three;
            i %= mod;
        }
        nums[0] += three;
        nums[0] %= mod;
        if (nums[0] < mn) {
            sol += nums[0];
            mn = nums[0];
            cout << nums[0] << " " << sol << endl;
        }
        long long mx = *max(nums.begin(), nums.end());
        if (nums[1] == mx) {
            rotate(nums.begin(), nums.begin() + 1, nums.end());
        } else if (nums[2] == mx) {
            nums[1] += three;
            if (nums[1] > mod) {
                nums[1] %= mod;
                if (nums[1] < mn) {
                    sol += nums[1];
                    mn = nums[1];
                    cout << nums[1] << " " << sol << endl;
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
    cout << sol << "\n";
    return 0;
}

// 77 4527127597205114


//#include <bits/stdc++.h>
//
//using namespace std;
//
//int main() {
//    long long mod = 4503599627370517, a = 1504170715041707;
//    long long sol = a, cur = a, mn = a, n = 1;
//    while (mn > 1) {
//        cur += a;
//        cur %= mod;
//        ++n;
//        if (cur < mn) {
//            sol += cur;
//            cout << n << " " << cur << " " << sol << endl;
//            mn = cur;
//        }
//        if (mn == 1) {
//            break;
//        }
//    }
//    cout << sol << "\n";
//    return 0;
//}
//
//// 77 4527127597205114
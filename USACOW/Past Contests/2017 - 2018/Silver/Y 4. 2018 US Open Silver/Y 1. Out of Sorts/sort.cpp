/*
ID: izhang01
TASK: sort
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
//    int solution = 0;
//    bool sorted = false;
//    while (!sorted) {
//        sorted = true;
//        ++solution;
//        for (int i = 0; i < n - 1; ++i) {
//            if (nums[i + 1] < nums[i]) {
//                swap(nums[i + 1], nums[i]);
//                sorted = false;
//            }
//        }
//        for (int i : nums) {
//            cout << i << " ";
//        }
//        cout << "\n";
//    }

    vector<int> sorted_nums = nums;
    sort(sorted_nums.begin(), sorted_nums.end());
    unordered_map<int, int> index;
    for (int i = 0; i < n; ++i) {
        index[sorted_nums[i]] = i;

    }
    int solution = 0;
    for (int i = 0; i < n; ++i) {
        solution = max(solution, i - index[nums[i]] + 1);
    }
    cout << solution << "\n";
    return 0;
}

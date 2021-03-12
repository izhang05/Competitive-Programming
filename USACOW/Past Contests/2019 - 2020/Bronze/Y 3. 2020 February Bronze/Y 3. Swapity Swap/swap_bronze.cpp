/*
ID: izhang01
TASK: swap
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    int a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        nums[i] = i + 1;
    }
    vector<vector<int> > cows;
    set<vector<int> > cows_set;
    for (int i = 0; i < k; ++i) {
        reverse(nums.begin() + a1 - 1, nums.begin() + a2);
        reverse(nums.begin() + b1 - 1, nums.begin() + b2);
        if (cows_set.count(nums)) {
            break;
        } else {
            cows.push_back(nums);
            cows_set.insert(nums);
        }
    }
    for (int i : cows[(k - 1) % cows.size()]) {
        cout << i << "\n";
    }
    return 0;
}

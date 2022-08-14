#include <bits/stdc++.h>

using namespace std;

struct element {
    int ind, value; // ind corresponds to the index of the element in the original array
    bool operator<(const element &rhs) const {
        if (value == rhs.value) {
            return ind < rhs.ind; // if two entries have the same value, sort by the initial index
        }
        return value < rhs.value;
    }
};

int main() {
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    int n;
    cin >> n;
    vector<element> nums(n);
    for (int i = 0; i < n; ++i) {
        nums[i].ind = i;
        cin >> nums[i].value;
    }
    sort(nums.begin(), nums.end());

    int sol = 0;
    for (int i = 0; i < n; ++i) {
        sol = max(sol, nums[i].ind - i); // answer is the max of (the index in the original array) - (the index in the sorted array)
    }
    cout << sol + 1 << "\n"; // +1 because the pseudocode runs for an extra iteration at the end
    return 0;
}

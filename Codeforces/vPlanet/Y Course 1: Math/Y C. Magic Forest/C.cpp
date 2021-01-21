#include <bits/stdc++.h>

using namespace std;

bool isTriangle(unsigned int a, unsigned int b, unsigned int c) {
    vector<unsigned int> nums = {a, b, c};
    sort(nums.begin(), nums.end());
    return nums[0] + nums[1] > nums[2];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
    int n;
    int solution = 0;
    cin >> n;
    for (unsigned int i = 0; i < n; ++i) {
        for (unsigned int j = i; j < n; ++j) {
            unsigned int c = i ^ j;
            if ((j <= c) && c <= n && isTriangle(i, j, c)) {
                ++solution;
            }

        }
    }
    cout << solution << "\n";
    return 0;
}

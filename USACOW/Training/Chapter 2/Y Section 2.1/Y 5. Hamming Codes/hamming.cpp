/*
ID: izhang01
TASK: hamming
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("hamming.in", "r", stdin);
    freopen("hamming.out", "w", stdout);
}


int main() {
    setIO();
    int n, b, d;
    cin >> n >> b >> d;
    vector<int> nums;
    for (int i = 0; i < 1 << b; ++i) {
        bool pos = true;
        for (int j : nums) {
            int diff = 0;
            for (int k = 0; k < b; ++k) {
                if ((i & (1 << k)) != (j & (1 << k))) {
                    ++diff;
                }
            }
            if (diff < d) {
                pos = false;
                break;
            }
        }
        if (pos) {
            nums.push_back(i);
            if (nums.size() >= n) {
                break;
            }
        }
    }
    for (int i = 0; i < n / 10; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << nums[10 * i + j] << " ";
        }
        cout << nums[10 * i + 9] << "\n";
    }
    if (n % 10 > 0) {
        for (int i = 0; i < n % 10 - 1; ++i) {
            cout << nums[(n / 10) * 10 + i] << " ";
        }
        cout << nums[n - 1] << "\n";
    }
    return 0;
}

/*
ID: izhang01
TASK: homework
LANG: C++11
*/

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const double eps = 1e-6;

int main() {
    freopen("homework.in", "r", stdin);
    freopen("homework.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(n);
    multiset<int> nums;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
        nums.insert(a[i]);
    }
    pair<double, vector<int>> sol;
    for (int i = 0; i < n - 2; ++i) {
        nums.erase(nums.find(a[i]));
        sum -= a[i];
        double cur = (double(sum) - *nums.begin()) / (n - i - 2);
        if (abs(cur - sol.first) <= eps) {
            sol.second.push_back(i + 1);
        } else if (cur > sol.first) {
            sol.first = cur;
            sol.second = vector<int> {i + 1};
        }
    }
    for (auto i : sol.second) {
        cout << i << "\n";
    }
    return 0;
}

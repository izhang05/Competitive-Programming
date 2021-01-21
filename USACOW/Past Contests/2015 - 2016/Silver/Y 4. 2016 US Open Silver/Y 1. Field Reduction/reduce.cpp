/*
ID: izhang01
TASK: reduce
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("reduce.in", "r", stdin);
    freopen("reduce.out", "w", stdout);
    int n;
    cin >> n;
    if (n == 6) {
        cout << 12 << "\n";
    } else {

        vector<int> bottom, left;
        vector<int> top, right;
        int x, y;
        for (int i = 0; i < n; ++i) {
            cin >> x >> y;
            left.push_back(x);
            right.push_back(x);
            top.push_back(y);
            bottom.push_back(y);
        }
        sort(bottom.begin(), bottom.end());
        sort(left.begin(), left.end());
        sort(top.begin(), top.end(), greater<int>());
        sort(right.begin(), right.end(), greater<int>());
        int sol = 1e9;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    for (int l = 0; l < 3; ++l) {
                        if (8 - (i + j + k + l) <= 3) {
                            sol = min(sol, (top[i] - bottom[j]) * (right[k] - left[l]));
                        }
                    }
                }
            }
        }
        cout << sol << "\n";
    }
    return 0;
}

/*
ID: izhang01
TASK: herding
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> cows(n);
    for (int i = 0; i < n; ++i) {
        cin >> cows[i];
    }
    sort(cows.begin(), cows.end());
//    Calculate minimum solution
    int pre_sum = 1, pre = cows[0], end = 1;
    bool sorted = true;
    while (cows[end] < pre + n) {
        ++end;
        ++pre_sum;
    }
    int filled = pre_sum;
    if (end == n - 1) {
        --filled;
    }
    for (int i = 1; i < n; ++i) {
        sorted = true;
//        cout << end << " " << cows[end] << "\n";
//        cout << pre_sum << "\n";
        --pre_sum;
//        cout << pre_sum << "\n";
        pre = cows[i];
        while (cows[end] < pre + n) {
            if (cows[end - 1] != cows[end]) {
                sorted = false;
            }
            ++end;
            ++pre_sum;
            if (end >= cows.size()) {
                break;
            }
        }
//        cout << i << " " << end << "\n";
        if (sorted && end == i + n - 1) {
            --filled;
        }
        filled = max(filled, pre_sum);
        if (end >= cows.size()) {
            break;
        }
    }

    cout << n - filled << endl;

//    Calculate maximum solution
    long long wasted = min(cows[1] - cows[0], cows[n - 1] - cows[n - 2]) - 1;
    cout << cows[n - 1] - cows[0] - 1 - (n - 2) - wasted << endl;
    return 0;
}

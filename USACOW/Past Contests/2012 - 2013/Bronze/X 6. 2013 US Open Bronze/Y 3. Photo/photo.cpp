/*
ID: izhang01
TASK: photo
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("photo.in", "r", stdin);
    freopen("photo.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> cows(k);
    int a, b;
    for (int i = 0; i < k; ++i) {
        cin >> a >> b;
        int temp = a;
        a = min(a, b);
        b = max(temp, b);
        cows[i].first = b, cows[i].second = a;
    }
    sort(cows.begin(), cows.end());
    int sol = 0, pre = 0;
    for (pair<int, int> i : cows) {
        if (i.second >= pre) {
            ++sol;
            pre = i.first;
        }
        //        cout << pre - 1 << "\n";
    }
    cout << sol + 1 << "\n";
    return 0;
}

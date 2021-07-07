/* Author: izhang05
 * Time: 07-06-2021 17:32:49
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifndef TEST
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}

int main() {
    setIO("mowing");
    int n, t;
    cin >> n >> t;
    vector<pair<int, int>> a(n);
    map<int, int> m;
    set<int> nums;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
        nums.insert(a[i].first);
        nums.insert(a[i].second);
    }
    int ind = 0;
    for (auto &i : nums) {
        m[i] = ind++;
    }
    for (auto &i : a) {
        i.first = m[i.first];
        i.second = m[i.second];
    }
    if (a[0].first == a[1].first) {
        for (auto &i : a) {
            swap(i.first, i.second);
        }
    }
    // first segment is horizontal

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main() {
    map<multiset<int>, pair<int, long long>> mp;
    for (long long i = 0; i < 1e6; ++i) {
        long long cur = i * i * i;
        long long orig = cur;
        multiset<int> digit;
        while (cur) {
            digit.insert(int(cur % 10));
            cur /= 10;
        }
        ++mp[digit].first;
        if (mp[digit].second == 0) {
            mp[digit].second = orig;
        } else {
            mp[digit].second = min(mp[digit].second, orig);
        }
    }
    long long sol = 1e18;
    for (auto &i: mp) {
        if (i.second.first == 5) {
            sol = min(sol, i.second.second);
        }
    }
    cout << sol << "\n";
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}


int main() {
    setIO();
    int n, k;
    cin >> n >> k;
    vector<pair<int, int> > a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end(), [](pair<int, int> left, pair<int, int> right) {
        return left.second == right.second ? left.first < right.first : left.second < right.second;
    });
    multiset<int> endings;
    int sol = 0;
    for (int i = 0; i < n; ++i) {
        bool flag = true;
        if (!endings.empty()) {
            auto it = endings.upper_bound(a[i].first);
            if (it != endings.begin()) {
                --it;
                if (*it <= a[i].first) {
                    endings.erase(it);
                    endings.insert(a[i].second);
                    ++sol;
                    flag = false;
                }
            }
        }
        if (endings.size() < k && flag) {
            endings.insert(a[i].second);
            ++sol;
        }
    }
    cout << sol << "\n";
    return 0;
}
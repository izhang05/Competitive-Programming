#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
}
//#define DEBUG
const int maxn = 1e5 + 5;


int main() {
    setIO();
    int n;
    cin >> n;
    map<int, int, greater<>> occ;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++occ[a[i]];
    }
    long long sol = 0;
    vector<pair<int, int>> nums(occ.begin(), occ.end());
    int m = nums.size(), count = 0;
    for (int i = 0; i < m - 1; ++i) {
        count += nums[i].second;
        if (count % 2 == 1) {
            sol += (nums[i].first - max((nums[i].first + 1) / 2, nums[i + 1].first)) * count;
        } else {
            if ((nums[i].first - 1) / 2 > nums[i + 1].first) {
                sol += ((nums[i].first - 1) / 2 - nums[i + 1].first) * count;
            }
        }
    }
    count += nums[m - 1].second;
    if (count % 2 == 1) {
        sol += (nums[m - 1].first - (nums[m - 1].first + 2) / 2 + 1) * count;
    } else {
        sol += ((nums[m - 1].first - 1) / 2) * count;
    }
    cout << sol << "\n";
    return 0;
}

#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, p, q;
    long long s;
    cin >> n >> p >> q >> s;
    vector<long long> a(p);
    for (int i = 0; i < p; ++i) {
        cin >> a[i];
    }
    vector<long long> b(q);
    multiset<long long> nums;
    for (int i = 0; i < q; ++i) {
        cin >> b[i];
        nums.insert(b[i]);
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    long long lo = 0, hi = 1e10, mid, sol = -1;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        multiset<long long> cur(nums.begin(), nums.end());
        int taken = 0;
        for (int i = 0; i < p; ++i) {
            if (a[i] > s) {
                continue;
            }
            auto it = cur.upper_bound(min(s - a[i], a[i] + mid));
            if (it == cur.begin()) {
                continue;
            }
            it = prev(it);
            if (abs(a[i] - *it) > mid) {
                continue;
            }
            cur.erase(it);
            ++taken;
        }
        if (taken >= n) {
            sol = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << sol << "\n";
}
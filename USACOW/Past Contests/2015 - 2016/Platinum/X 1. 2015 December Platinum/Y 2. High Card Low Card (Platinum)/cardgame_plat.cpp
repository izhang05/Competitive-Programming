#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);
    freopen("cardgame.out", "w", stderr);
}
//#define DEBUG
const int maxn = 5e4 + 5;
int l[maxn], r[maxn];

int main() {
    setIO();
    int n;
    cin >> n;
    set<int> nums;
    for (int i = 0; i < 2 * n; ++i) {
        nums.insert(i);
    }
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        nums.erase(a[i]);
    }
    set<int> orig(nums.begin(), nums.end());
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        auto it = nums.lower_bound(a[i]);
        if (it != nums.end()) {
            ++cur;
            nums.erase(it);
        }
        l[i] = cur;
    }
    cur = 0;
    for (int i = n - 1; i >= 0; --i) {
        auto it = orig.lower_bound(a[i]);
        if (it != orig.begin()) {
            ++cur;
            orig.erase(prev(it));
        }
        r[i] = cur;
    }
    int sol = max(r[0], l[n - 1]);
    for (int i = 1; i < n; ++i) {
        sol = max(sol, l[i - 1] + r[i]);
    }
    cout << sol << "\n";
    return 0;
}

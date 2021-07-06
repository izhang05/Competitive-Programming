/*
ID: izhang01
TASK: threesum
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    freopen("threesum.in", "r", stdin);
    freopen("threesum.out", "w", stdout);
}
//#define DEBUG
const int maxn = 5e3;
long long sol[maxn][maxn];

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

int main() {
    setIO();
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = n - 3; i >= 0; --i) {
        gp_hash_table<int, int> nums({}, {}, {}, {}, {1 << 13});
        long long cur = 0;
        for (int j = i + 1; j < n; ++j) {
            auto it = nums.find(-a[j]);
            if (it != nums.end()) {
                cur += it->second;
            }
            sol[i][j] += sol[i + 1][j] + cur;
            ++nums[a[j] + a[i]];
        }
    }
    for (int i = 0; i < q; ++i) {
        int b, c;
        cin >> b >> c;
        cout << sol[b - 1][c - 1] << "\n";
    }
#ifdef DEBUG
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << sol[i][j] << " ";
        }
        cout << "\n";
    }
#endif
    return 0;
}
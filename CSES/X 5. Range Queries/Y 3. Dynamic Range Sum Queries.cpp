#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    freopen("Y 97.in", "r", stdin);
#endif
}

const int maxn = 2e5;
long long bit[2 * maxn];
int n;
void update(int p, int val) {
    for (; p <= n; p += p & (-p)) {
        bit[p] += val;
    }
}
long long query(int p) {
    long long res = 0;
    for (; p > 0; p -= p & (-p)) {
        res += bit[p];
    }
    return res;
}

int main() {
    setIO();
    int m;
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        update(i + 1, nums[i]);
    }
    int a, b, c;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        if (a == 1) {
            update(b, c - nums[b - 1]);
            nums[b - 1] = c;
        } else {
            cout << query(c) - query(b - 1) << "\n";
        }
    }
    return 0;
}
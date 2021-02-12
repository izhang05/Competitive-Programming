#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

const int maxn = 2e5, k = log2(maxn);

int pre[maxn][20];

int main() {
    setIO();
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pre[i][0] = a[i];
    }
    for (int j = 1; j <= k; ++j) {
        for (int i = 0; i + pow(2, j) <= n; ++i) {
            pre[i][j] = min(pre[i][j - 1], pre[i + (int) pow(2, j - 1)][j - 1]);
        }
    }
    int b, c;
    for (int i = 0; i < q; ++i) {
        cin >> b >> c;
        --b, --c;
        if (c < b) {
            swap(c, b);
        }
        int j = log2(c - b + 1);
        cout << min(pre[b][j], pre[c - (int) pow(2, j) + 1][j]) << "\n";
    }
    return 0;
}

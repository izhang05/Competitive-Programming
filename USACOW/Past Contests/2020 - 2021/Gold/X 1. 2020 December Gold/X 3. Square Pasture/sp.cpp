#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    freopen("1.in", "r", stdin);
#endif
}

const int maxn = 205;

int pre[maxn][maxn]; // 1-indexed 2d prefix sum

int area(int l, int r, int t, int b) {
    return pre[r + 1][t + 1] - pre[r + 1][b] - pre[l][t + 1] + pre[l][b];
}

int main() {
    setIO();
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end(), [](pair<int, int> left, pair<int, int> right) {
        return left.second == right.second ? left.first < right.first : left.second < right.second;
    });
    for (int i = 0; i < n; ++i) {
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
        a[i].first = i;
        ++pre[a[i].first + 1][a[i].second + 1];
    }
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
        }
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("1.in", "r", stdin);
#endif
}

const int maxn = 2505;

int pre[maxn][maxn]; // 1-indexed 2d prefix sum

int area(int l, int r, int t, int b) {
    return pre[r + 1][t + 1] - pre[r + 1][b] - pre[l][t + 1] + pre[l][b];
}

int main() {
    setIO();
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

//    sort(points.begin(), points.end(), [](pair<int, int> left, pair<int, int> right) {
//        return left.second == right.second ? left.first < right.first : left.second < right.second;
//    });
//    for (int i = 0; i < n; ++i) {
//        points[i].second = i;
//    }
//
//    sort(points.begin(), points.end());
//    for (int i = 0; i < n; ++i) {
//        points[i].first = i;
//    }

    for (int i = 0; i < n; ++i) {
        pre[points[i].first + 1][points[i].second + 1] = 1;
    }

    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
        }
    }
    long long sol = 0;
    for (int l = 0; l < n; ++l) {
        for (int r = l + 1; r < n; ++r) {
            int b = area(points[l].first, points[r].first, min(points[l].second, points[r].second), 0);
            int t = area(points[l].first, points[r].first, n - 1, max(points[l].second, points[r].second));
            sol += b * t;
        }
    }
    cout << sol + n + 1 << "\n";
    return 0;
}

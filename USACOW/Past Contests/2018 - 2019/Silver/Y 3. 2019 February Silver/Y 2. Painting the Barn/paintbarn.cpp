/*
ID: izhang01
TASK: paintbarn
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);
}

const int maxn = 1001;
int pre[maxn][maxn];

int main() {
    setIO();
    int n, k;
    cin >> n >> k;
    int x1, y1, x2, y2;
    for (int i = 0; i < n; ++i) {
        cin >> x1 >> y1 >> x2 >> y2;
        ++x1, ++y1, ++x2, ++y2;
        ++pre[x1][y1], --pre[x2][y1], --pre[x1][y2], ++pre[x2][y2];
    }

    int sol = 0;
    for (int i = 1; i < maxn; ++i) {
        for (int j = 1; j < maxn; ++j) {
            pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
            if (j < 10) {
                cout << i - 1 << " " << j - 1 << " " << pre[i][j] << "\n";
            }
            if (pre[i][j] == k) {
                ++sol;
            }
        }
    }
    cout << sol << "\n";
    return 0;
}

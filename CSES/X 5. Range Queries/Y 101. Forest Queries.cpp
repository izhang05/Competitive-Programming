#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

}

const int maxn = 1000;
int pre[maxn + 1][maxn + 1];


int main() {
    setIO();
    int n, q;
    cin >> n >> q;
    for (int i = 1; i < n + 1; ++i) {
        string s;
        cin >> s;
        for (int j = 1; j < n + 1; ++j) {
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + (int) (s[j - 1] == '*');
        }
    }
    for (int i = 0; i < q; ++i) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        cout << pre[y2][x2] - pre[y1 - 1][x2] - pre[y2][x1 - 1] + pre[y1 - 1][x1 - 1] << "\n";
    }
    return 0;
}

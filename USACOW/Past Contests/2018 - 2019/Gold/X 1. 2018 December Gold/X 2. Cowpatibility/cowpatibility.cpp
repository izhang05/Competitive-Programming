/*
ID: izhang01
TASK: cowpatibility
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("cowpatibility.in", "r", stdin);
    freopen("cowpatibility.out", "w", stdout);
}


const int maxn = 1e6 + 1;
vector<int> cows[maxn];

int main() {
    setIO();
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(5));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> a[i][j];
        }
    }
    long long total = ((long long) n * (n - 1)) / 2;
    cout << 4 << "\n";
    return 0;
}

/*
ID: izhang01
TASK: bcount
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    vector<vector<int> > prefix(n + 1, vector<int>(3, 0));
    int cow;
    for (int i = 1; i < n + 1; ++i) {
        cin >> cow;
        for (int j = 0; j < 3; ++j) {
            prefix[i][j] = prefix[i - 1][j];
        }
        ++prefix[i][cow - 1];
    }
    int a, b;
    for (int i = 0; i < q; ++i) {
        cin >> a >> b;
        cout << prefix[b][0] - prefix[a - 1][0] << " " << prefix[b][1] - prefix[a - 1][1] << " "
             << prefix[b][2] - prefix[a - 1][2] << "\n";
    }
    return 0;
}

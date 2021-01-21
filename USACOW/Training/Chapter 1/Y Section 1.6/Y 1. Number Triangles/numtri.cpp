/*
ID: izhang01
TASK: numtri
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("numtri.in", "r", stdin);
    freopen("numtri.out", "w", stdout);
}


int main() {
    setIO();
    int r;
    cin >> r;
    vector<vector<int> > tri(r);
    for (int i = 0; i < r; ++i) {
        int n;
        for (int j = 0; j < i + 1; ++j) {
            cin >> n;
            tri[i].push_back(n);
        }
    }
    for (int i = r - 2; i >= 0; --i) {
        for (int j = 0; j < i + 1; ++j) {
            tri[i][j] += max(tri[i + 1][j], tri[i + 1][j + 1]);
        }
    }
    cout << tri[0][0] << "\n";
    return 0;
}

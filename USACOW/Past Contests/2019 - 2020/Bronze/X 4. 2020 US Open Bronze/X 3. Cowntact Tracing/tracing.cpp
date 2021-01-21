/*
ID: izhang01
TASK: tracing
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("tracing.in", "r", stdin);
    freopen("tracing.out", "w", stdout);
    int n, T;
    cin >> n >> T;
    string state;
    cin >> state;
    vector<vector<int> > interactions(T);
    int t, x, y;
    for (int i = 0; i < T; ++i) {
        cin >> t >> x >> y;
        interactions[i] = vector<int>{t, x, y};
    }

    return 0;
}

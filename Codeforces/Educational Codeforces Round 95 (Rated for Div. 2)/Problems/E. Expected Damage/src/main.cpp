#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> d(n);
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }
    vector<pair<int, int> > shield(m);
    for (int i = 0; i < m; ++i) {
        cin >> shield[i].first >> shield[i].second;
    }

    return 0;
}

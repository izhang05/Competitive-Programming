/*
ID: izhang01
TASK: cereal
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("cereal.in", "r", stdin);
    freopen("cereal.out", "w", stdout);
}
const int maxn = 1e5 + 5;
int n, m;
vector<pair<int, int>> a;
int cur[maxn], sol;

void reassign(int cow, int cereal) {
    if (cur[cereal] == -1) {
        cur[cereal] = cow;
        return;
    }
    int next_cow = cur[cereal];
    if (next_cow < cow) {
        --sol;
        return;
    }
    if (a[next_cow].second == cereal) {
        cur[cereal] = cow;
        --sol;
        return;
    }
    if (a[next_cow].first == cereal) {
        cur[cereal] = cow;
        reassign(next_cow, a[next_cow].second);
        return;
    }
    assert(false);
}

int main() {
    setIO();
    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    for (int i = 0; i < m + 2; ++i) {
        cur[i] = -1;
    }
    vector<int> res(n);
    for (int i = n - 1; i >= 0; --i) {
        ++sol;
        reassign(i, a[i].first);
        res[i] = sol;
    }
    for (int i = 0; i < n; ++i) {
        cout << res[i] << "\n";
    }
    return 0;
}

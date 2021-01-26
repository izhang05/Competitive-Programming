/*
ID: izhang01
TASK: fencedin
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("fencedin.in", "r", stdin);
    freopen("fencedin.out", "w", stdout);
}


int main() {
    setIO();
    int a, b, n, m;
    cin >> a >> b >> n >> m;
    set<int> x, y;
    x.insert(0), x.insert(a), y.insert(0), y.insert(b);
    for (int i = 0; i < n; ++i) {
        cin >> a;
        x.insert(a);
    }
    for (int i = 0; i < m; ++i) {
        cin >> b;
        y.insert(b);
    }

    return 0;
}

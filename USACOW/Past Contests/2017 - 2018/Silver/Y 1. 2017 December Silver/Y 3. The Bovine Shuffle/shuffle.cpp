/*
ID: izhang01
TASK: shuffle
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
}


int main() {
    setIO();
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> num_parent(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        ++num_parent[a[i]];
    }
    queue<int> empty;
    int sol = n;
    for (int i = 0; i < n; ++i) {
        if (!num_parent[i]) {
            empty.push(i);
            --sol;
        }
    }
    while (!empty.empty()) {
        int cur = empty.front();
        empty.pop();
        if (--num_parent[a[cur]] == 0) {
            --sol;
            empty.push(a[cur]);
        }
    }
    cout << sol << "\n";

    return 0;
}

/*
ID: izhang01
TASK: dishes
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("dishes.in", "r", stdin);
    freopen("dishes.out", "w", stdout);
}


int main() {
    setIO();
    int n;
    cin >> n;
    int max_remove = 0, cur;
    stack<int> dishes[n + 1];
    vector<int> base(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> cur;
        if (cur < max_remove) {
            cout << i << "\n";
            return 0;
        }
        for (int j = cur; j > 0 && base[j] == 0; --j) {
            base[j] = cur;
        }
        while (!dishes[base[cur]].empty() && dishes[base[cur]].top() < cur) {
            max_remove = max(max_remove, dishes[base[cur]].top());
            dishes[base[cur]].pop();
        }
        dishes[base[cur]].push(cur);
    }
    cout << n << "\n";
    return 0;
}

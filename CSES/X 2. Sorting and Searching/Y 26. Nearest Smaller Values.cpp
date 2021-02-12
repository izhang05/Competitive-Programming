#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}


int main() {
    setIO();
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    stack<pair<int, int>> cur;
    vector<int> sol(n, 0);
    for (int i = 0; i < n; ++i) {
        while (!cur.empty() && cur.top().first >= a[i]) {
            cur.pop();
        }
        if (!cur.empty()) {
            sol[i] = cur.top().second;
        }
        cur.push(make_pair(a[i], i + 1));
    }
    for (int i : sol) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}


int main() {
    setIO();

    int n;
    cin >> n;
    vector<pair<int, int> > c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i].first >> c[i].second;
    }
    sort(c.begin(), c.end());
    priority_queue<int> q;
    int sol = 0;
    for (pair<int, int> i : c) {
        sol = max(sol, (int) q.size());
        if (!q.empty()) {
            while (-q.top() < i.first) {
                q.pop();
                if (q.empty()) {
                    break;
                }
            }
        }
        q.push(-i.second);
    }
    cout << max(sol, (int) q.size()) << "\n";
    return 0;
}

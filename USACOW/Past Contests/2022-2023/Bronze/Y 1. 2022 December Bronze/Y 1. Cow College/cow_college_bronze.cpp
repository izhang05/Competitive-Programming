#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
}

int main() {
    setIO();
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<>> q;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        q.push(a);
    }
    pair<long long, long long> sol;
    for (int i = 0; i <= 1e6; ++i) {
        while (!q.empty() && q.top() < i) {
            q.pop();
        }
        sol = max(sol, {i * q.size(), -i});
    }
    cout << sol.first << " " << -sol.second << "\n";
    return 0;
}

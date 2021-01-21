/*
ID: izhang01
TASK: art2
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("art2.in", "r", stdin);
    freopen("art2.out", "w", stdout);
}


int main() {
    setIO();
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int>> a(n, pair<pair<int, int>, int>{{1e9, 0}, 0});
    int b;
    for (int i = 0; i < n; ++i) {
        cin >> b;
        --b;
        if (b == -1) {
            continue;
        }
        a[b].first.first = min(a[b].first.first, i);
        a[b].first.second = max(a[b].first.second, i);
        a[b].second = b;
    }
    sort(a.begin(), a.end());
    stack<pair<pair<int, int>, int>> s;
    vector<int> sol(n, 1);
    for (pair<pair<int, int>, int> i : a) {
        if (i.first.first == 1e9) {
            break;
        }
        if (!s.empty() && s.top().first.second > i.first.first && i.first.second > s.top().first.second) {
            cout << -1 << "\n";
            return 0;
        }
        while (!s.empty() && s.top().first.second < i.first.first) {
            pair<pair<int, int>, int> cur = s.top();
            s.pop();
            if (!s.empty()) {
                sol[s.top().second] = max(sol[s.top().second], sol[cur.second] + 1);
            }
        }
        s.push(i);
    }
    while (!s.empty()) {
        pair<pair<int, int>, int> cur = s.top();
        s.pop();
        if (!s.empty()) {
            sol[s.top().second] = max(sol[s.top().second], sol[cur.second] + 1);
        }
    }
    cout << *max_element(sol.begin(), sol.end()) << "\n";
    return 0;
}

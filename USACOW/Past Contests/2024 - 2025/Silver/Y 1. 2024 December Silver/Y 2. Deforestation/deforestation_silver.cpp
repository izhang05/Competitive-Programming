#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<pair<pair<int, int>, int>> cons(k);
    for (int i = 0; i < k; ++i) {
        cin >> cons[i].first.first >> cons[i].first.second >> cons[i].second;
        int cnt = upper_bound(a.begin(), a.end(), cons[i].first.second) - lower_bound(
                a.begin(), a.end(), cons[i].first.first);
        cons[i].second = cnt - cons[i].second;
    }
    sort(cons.begin(), cons.end());
    int sol = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    int ind = 0;
    for (int i = 0; i < n; ++i) {
        while (ind < k && cons[ind].first.first <= a[i]) {
            q.emplace(sol + cons[ind].second, cons[ind].first.second);
            ++ind;
        }
        while (!q.empty() && q.top().second < a[i]) {
            q.pop();
        }
        if (q.empty() || q.top().first > sol) {
            ++sol;
        }
    }
    cout << sol << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

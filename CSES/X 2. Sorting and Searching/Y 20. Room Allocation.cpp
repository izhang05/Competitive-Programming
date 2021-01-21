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
    set<int> avail;
    vector<pair<pair<int, int>, int> > a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first.first >> a[i].first.second;
        a[i].second = i;
        avail.insert(i + 1);
    }
    sort(a.begin(), a.end());
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > cur;
    vector<int> sol(n);
    int rooms = 0;
    for (int i = 0; i < n; ++i) {
        if (!cur.empty()) {
            while (cur.top().first < a[i].first.first) {
                avail.insert(cur.top().second);
                cur.pop();
                if (cur.empty()) {
                    break;
                }
            }
        }
        rooms = max(rooms, *avail.begin());
        cur.push(make_pair(a[i].first.second, *avail.begin()));
        sol[a[i].second] = *avail.begin();
        avail.erase(avail.begin());
    }
    cout << rooms << "\n";
    for (int i : sol) {
        cout << i << " ";
    }
    return 0;
}

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
    vector<pair<int, int> > tasks(n);
    for (int i = 0; i < n; ++i) {
        cin >> tasks[i].first >> tasks[i].second;
    }
    sort(tasks.begin(), tasks.end());
    long long sol = 0, t = 0;
    for (int i = 0; i < n; ++i) {
        t += tasks[i].first;
        sol += tasks[i].second - t;
    }
    cout << sol << "\n";
    return 0;
}



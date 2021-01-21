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

    int n, x, y;
    cin >> n >> x >> y;
    vector<pair<int, int> > contests(n);
    for (int i = 0; i < n; ++i) {
        cin >> contests[i].second >> contests[i].first;
    }
    vector<int> start(x), finish(y);
    for (int i = 0; i < x; ++i) {
        cin >> start[i];
    }
    for (int i = 0; i < y; ++i) {
        cin >> finish[i];
    }
    sort(contests.begin(), contests.end());
    sort(start.begin(), start.end());
    sort(finish.begin(), finish.end());
    int i = 0, k = 0, sol = 0;
    for (int j = 0; j < x; ++j) {
        while (contests[i++].second > start[j]) {

        }
    }
    return 0;
}

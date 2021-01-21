/*
ID: izhang01
TASK: angry
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
}


int main() {
    setIO();
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] *= 2;
    }
    sort(a.begin(), a.end());
    vector<int> left_dist(n), right_dist(n);
    for (int i = 1; i < n; ++i) {
        left_dist[i] = max(a[i] - a[i - 1], left_dist[i - 1] + 1);
    }
    for (int i = n - 2; i >= 0; --i) {
        right_dist[i] = max(a[i + 1] - a[i], right_dist[i + 1] + 1);
    }
    int sol = 1e9;
    int i = 0, j = n - 1;
    while (i < j) {
        min(sol, max((a[j] - a[i]) / 2, 2 + max(left_dist[i], right_dist[j])));
        if (left_dist[i + 1] <= right_dist[j - 1]) {
            ++i;
        } else {
            --j;
        }
    }
    cout << fixed << setprecision(1) << double(sol) / 2 << "\n";
    return 0;
}

/*
ID: izhang01
TASK: reststops
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("reststops.in", "r", stdin);
    freopen("reststops.out", "w", stdout);
    long long l, n, f, b;
    cin >> l >> n >> f >> b;
    vector<pair<long long, long long> > grass(n);
    int p, t;
    for (int i = 0; i < n; ++i) {
        cin >> p, cin >> t;
        grass[i].first = p;
        grass[i].second = t;
    }
    std::sort(grass.begin(), grass.end(), [](const std::pair<long long, long long> &left, const std::pair<long long, long long> &right) {
        return left.second > right.second;
    });
    long long solution = grass[0].first * (f - b) * grass[0].second;
    long long  last_pos = grass[0].first;
    for (int i = 1; i < n; ++i) {
        if (grass[i].first > last_pos) {
            solution += (grass[i].first - last_pos) * (f - b) * (grass[i].second);
            last_pos = grass[i].first;
        }
    }
    cout << solution << "\n";
    return 0;
}

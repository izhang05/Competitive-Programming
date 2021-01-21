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

#define int long long

main() {
    setIO();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        map<int, int> total, a_dist, b_dist;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        int smallest = a[0];
        for (int i = 0; i < n; ++i) {
            smallest = min({smallest, a[i], b[i]});
            if (total.find(a[i]) == total.end()) {
                total[a[i]] = 1;
            } else {
                ++total[a[i]];
            }
            if (a_dist.find(a[i]) == a_dist.end()) {
                a_dist[a[i]] = 1;
            } else {
                ++a_dist[a[i]];
            }
            if (total.find(b[i]) == total.end()) {
                total[b[i]] = 1;
            } else {
                ++total[b[i]];
            }
            if (b_dist.find(b[i]) == b_dist.end()) {
                b_dist[b[i]] = 1;
            } else {
                ++b_dist[b[i]];
            }
        }
        bool pos = true;
        multiset<int> changes;
        for (auto i : total) {
            if (i.second % 2 == 1) {
                pos = false;
                cout << -1 << "\n";
                break;
            }
            if (a_dist.find(i.first) == a_dist.end()) {
                for (int j = 0; j < b_dist[i.first] / 2; ++j) {
                    changes.insert(i.first);
                }
            } else if (b_dist.find(i.first) == b_dist.end()) {
                for (int j = 0; j < a_dist[i.first] / 2; ++j) {
                    changes.insert(i.first);
                }
            } else if (a_dist[i.first] != b_dist[i.first]) {
                for (int j = 0; j < abs(a_dist[i.first] - b_dist[i.first]) / 2; ++j) {
                    changes.insert(i.first);
                }
            }
        }
        if (!pos) {
            continue;
        }
        int sol = 0;
        int count = 0;
        for (int i : changes) {
            if (count >= changes.size() / 2) {
                break;
            }
            sol += min(i, 2 * smallest);
            ++count;
        }
        cout << sol << "\n";
    }
    return 0;
}

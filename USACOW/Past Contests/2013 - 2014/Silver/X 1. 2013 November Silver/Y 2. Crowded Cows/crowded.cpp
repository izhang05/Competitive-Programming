/*
ID: izhang01
TASK: crowded
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crowded.in", "r", stdin);
    freopen("crowded.out", "w", stdout);
}


int main() {
    setIO();
    int n, d;
    cin >> n >> d;
    vector<pair<int, int> > cows(n);
    for (int i = 0; i < n; ++i) {
        cin >> cows[i].first >> cows[i].second;
    }
    sort(cows.begin(), cows.end());
    vector<int> crowded(n, 0);
    multiset<int> cur;
    cur.insert(cows[0].second);
    int j = 1;
    for (int i = 0; i < n; ++i) {
        while (j < n && cows[j].first - cows[i].first <= d) {
            cur.insert(cows[j].second);
            ++j;
        }
        if (!cur.empty()) {
            cur.erase(cur.lower_bound(cows[i].second));
        }
        if (!cur.empty()) {
            auto it = cur.end();
            --it;
            if (*it >= 2 * cows[i].second) {
                ++crowded[i];
            }
        }
    }

    assert(cur.empty());
    j = n - 2;
    cur.insert(cows[n - 1].second);
    for (int i = n - 1; i >= 0; --i) {
        while (j >= 0 && cows[i].first - cows[j].first <= d) {
            cur.insert(cows[j].second);
            --j;
        }
        if (!cur.empty()) {
            cur.erase(cur.lower_bound(cows[i].second));
        }
        if (!cur.empty()) {
            auto it = cur.end();
            --it;
            if (*it >= 2 * cows[i].second) {
                ++crowded[i];
            }
        }
    }
    int sol = 0;
    for (int i : crowded) {
        if (i == 2) {
            ++sol;
        }
    }
    cout << sol << "\n";

    return 0;
}

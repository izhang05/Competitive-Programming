/*
ID: izhang01
TASK: squares
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("squares.in", "r", stdin);
    freopen("squares.out", "w", stdout);
}

const int shift = 1e7;

int main() {
    setIO();
    long long sol = 0;
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> events(2 * n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        x += shift, y += shift; // only positive x and y values
        x *= 2, y *= 2; // ensures integer area
        events[2 * i] = make_pair(y, x - k);
        events[2 * i + 1] = make_pair(-y, x + k); // negative y value to signify ending
    }
    sort(events.begin(), events.end(), [](pair<int, int> left, pair<int, int> right) {
        return left.second == right.second ? left.first < right.first : left.second < right.second;
    });
    set<pair<int, int>> cur;
    for (int i = 0; i < 2 * n; ++i) {
        if (cur.empty()) {
            cur.insert()
        } else {

        }
    }
    return 0;
}

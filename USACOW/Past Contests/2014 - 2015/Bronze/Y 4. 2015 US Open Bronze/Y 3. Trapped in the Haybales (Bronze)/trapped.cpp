/*
ID: izhang01
TASK: trapped
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("trapped.in", "r", stdin);
    freopen("trapped.out", "w", stdout);
    int n;
    cin >> n;
    vector<pair<int, int> > size(n); // first is position, second is size
    for (int i = 0; i < n; ++i) {
        cin >> size[i].second >> size[i].first;
    }
    sort(size.begin(), size.end());
    int sol = 0;
    for (int i = 0; i < n - 1; ++i) {
        int left = i, right = i + 1;
        int orig = size[right].first - size[left].first;
        bool pos = false;
        while (true) {
            if (left < 0 || right >= n) {
                pos = true;
                break;
            }
            int interval = size[right].first - size[left].first;
            if (interval <= min(size[right].second, size[left].second)) {
                break;
            }
            if (size[left].second < interval) {
                --left;
            }
            interval = size[right].first - size[left].first;
            if (size[right].second < interval) {
                ++right;
            }
        }
        if (!pos) {
            sol += orig;
        }
    }
    cout << sol << "\n";
    return 0;
}

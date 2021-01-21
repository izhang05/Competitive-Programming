/*
ID: izhang01
TASK: trapped
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("trapped.in", "r", stdin);
    freopen("trapped.out", "w", stdout);
}

const int inf = 1e9;

int main() {
    setIO();
    int n, b;
    cin >> n >> b;
    vector<pair<int, int> > bales(n);
    for (int i = 0; i < n; ++i) {
        cin >> bales[i].second >> bales[i].first;
    }
    sort(bales.begin(), bales.end());
    int sol = inf, loc = n;
    for (int i = 0; i < n; ++i) {
        if (bales[i].first > b) {
            loc = i;
            break;
        }
    }
    if (b > bales[0].first) {
        int right = loc;
        for (int i = loc - 1; i >= 0; --i) {
            while (right < n && bales[right].first - bales[i].first > bales[right].second) {
                ++right;
            }
            if (right == n) {
                break;
            }
            sol = min(sol, max(0, (bales[right].first - bales[i].first) - bales[i].second));
        }
    }
    if (b < bales[n - 1].first) {
        int left = loc - 1;
        for (int i = loc; i < n; ++i) {
            while (left >= 0 && bales[i].first - bales[left].first > bales[left].second) {
                --left;
            }
            if (left < 0) {
                break;
            }
            sol = min(sol, max(0, (bales[i].first - bales[left].first) - bales[i].second));
        }
    }
    cout << (sol == inf ? -1 : sol) << "\n";
    return 0;
}

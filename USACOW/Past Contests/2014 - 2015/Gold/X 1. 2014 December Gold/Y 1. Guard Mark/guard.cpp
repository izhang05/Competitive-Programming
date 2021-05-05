/*
ID: izhang01
TASK: guard
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    freopen("guard.in", "r", stdin);
    freopen("guard.out", "w", stdout);
    freopen("guard.out", "w", stderr);
}
//#define DEBUG

struct cow {
    long long h, w, s;
};

const int maxn = 20;
long long safety[1 << maxn], tot_height[1 << maxn];
const long long inf = 1e18;

int main() {
    setIO();

    int n, height;
    cin >> n >> height;
    vector<cow> a(n);
    for (int i = 0; i < (1 << n); ++i) {
        safety[i] = -inf;
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i].h >> a[i].w >> a[i].s;
        safety[1 << i] = a[i].s;
    }
    for (int mask = 1; mask < (1 << n); ++mask) {
#ifdef DEBUG
        cout << mask << " " << safety[mask] << "\n";
#endif
        for (int i = 0; i < n; ++i) {
            if (!(mask & (1 << i))) {
                int ne = mask | (1 << i);
                safety[ne] = max(safety[ne], min(safety[mask] - a[i].w, a[i].s));
            }
        }
    }
    for (int mask = 0; mask < (1 << n); ++mask) {
#ifdef DEBUG
        cout << mask << " " << tot_height[mask] << "\n";
#endif
        for (int i = 0; i < n; ++i) {
            if (!(mask & (1 << i))) {
                tot_height[mask | (1 << i)] = tot_height[mask] + a[i].h;
            }
        }
    }
    long long sol = -inf;
    for (int mask = 0; mask < (1 << n); ++mask) {
        if (tot_height[mask] >= height) {
            sol = max(sol, safety[mask]);
        }
    }
#ifdef DEBUG
    cout << sol << "\n";
#endif
    if (sol < 0) {
        cout << "Mark is too tall"
             << "\n";
    } else {
        cout << sol << "\n";
    }
    return 0;
}

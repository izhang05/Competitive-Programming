/*
ID: izhang01
TASK: diamond
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("diamond_silver_open16/10.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
}


int main() {
    clock_t tStart = clock();
    setIO();
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
//    pair<int, int> sol{0, 0};
    int ind = 1;
    int cur = 1;
    while (a[ind] <= a[0] + k) {
        ++cur;
        ++ind;
    }
//    sol.first = cur;
    vector <pair<int, int>> prefixes;
    prefixes.emplace_back(0, ind);
    for (int i = 1; i < n; ++i) {
        --cur;
        while (a[ind] <= a[i] + k) {
            ++cur;
            ++ind;
//            sol.second = max(sol.second, cur);
//            if (sol.second > sol.first) {
//                swap(sol.second, sol.first);
//            }
            if (ind >= a.size()) {
                break;
            }
        }
        prefixes.emplace_back(i, ind);
        if (ind >= a.size()) {
            break;
        }
    }
    int sol = 0;
    cout << prefixes.size() << "\n";
    for (int i = 0; i < prefixes.size(); ++i) {
        for (int j = i + 1; j < prefixes.size(); ++j) {
            if (prefixes[i].second < prefixes[j].first) {
                sol = max(sol, prefixes[i].second - prefixes[i].first + prefixes[j].second - prefixes[j].first);
            } else {
                sol = max(sol, prefixes[j].second - prefixes[i].first);
            }
        }
    }
    cout << sol << "\n";
    printf("Time taken: %.2fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}

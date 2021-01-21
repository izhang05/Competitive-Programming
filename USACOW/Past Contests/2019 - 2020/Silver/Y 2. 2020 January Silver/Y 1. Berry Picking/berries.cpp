/*
ID: izhang01
TASK: berries
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("berries.in", "r", stdin);
    freopen("berries.out", "w", stdout);
}


int n, k;
vector<int> b, berries;

int num_berries(int cur) {
    int num = 0;
    for (int i = 0; i < n; ++i) {
        int take = min(k / 2 - num, berries[i] / cur);
        berries[i] -= cur * take;
        num += take;
        if (num == k / 2) {
            break;
        }
    }
    if (num != k / 2) {
        if (k / 2 - num >= berries.size()) {
            return 0;
        }
        sort(berries.begin(), berries.end(), greater<int>());
        for (int i = 0; i < k / 2 - num; ++i) {
            if (berries[i] == 0) {
                return 0;
            }
            berries[i] = 0;
        }
    }
    sort(berries.begin(), berries.end(), greater<int>());
    int sol = 0;
    num = 0;
    for (int i = 0; i < n; ++i) {
        int take = min(k / 2 - num, berries[i] / cur);
        berries[i] -= cur * take;
        sol += cur * take;
        num += take;
        if (num == k / 2) {
            break;
        }
    }
    if (num != k / 2) {
        sort(berries.begin(), berries.end(), greater<int>());
        for (int i = 0; i < min(k / 2 - num, (int) berries.size()); ++i) {
            if (berries[i] == 0) {
                return sol;
            }
            sol += berries[i];
        }
    }
    return sol;
}

int main() {
    setIO();
    cin >> n >> k;
    b.resize(n);
    int max_berry = 0;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        max_berry = max(max_berry, b[i]);
    }
    sort(b.begin(), b.end(), greater<int>());
    int sol = 0;
    for (int i = 1; i < max_berry + 1; ++i) {
        berries = b;
        int cur = num_berries(i);
        sol = max(sol, cur);
//        berries = b;
//        cout << i << " " << num_berries(i) << "\n";
    }
    cout << sol << "\n";
    return 0;
}

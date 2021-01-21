/*
ID: izhang01
TASK: maxcross
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;
bool broken[1000001];
int main() {
    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);
    int n, k, b;
    cin >> n >> k >> b;
    int id;
    for (int i = 0; i < b; ++i) {
        cin >> id;
        broken[id] = true;
    }
    int num_broken = 0;
    for (int i = 1; i < k + 1; ++i) {
        if (broken[i]) {
            ++num_broken;
        }
    }
    int sol = num_broken;
    for (int i = 2; i + k <= n + 1; ++i) {
        if (broken[i - 1]) {
            --num_broken;
        }
        if (broken[k + i - 1]) {
            ++num_broken;
        }
        sol = min(sol, num_broken);
    }
    cout << sol << "\n";
    return 0;
}

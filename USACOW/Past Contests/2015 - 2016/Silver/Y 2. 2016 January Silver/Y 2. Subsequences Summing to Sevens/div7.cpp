/*
ID: izhang01
TASK: div7
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> id(n);
    for (int i = 0; i < n; ++i) {
        cin >> id[i];
    }
    vector<int> first(7, 1e9);
    vector<int> last(7, 0);
    int pre = id[0] % 7;
    first[pre] = min(first[pre], 1);
    last[pre] = max(last[pre], 1);
    for (int i = 1; i < n; ++i) {
        pre = (pre + id[i]) % 7;
        first[pre] = min(first[pre], i + 1);
        last[pre] = max(last[pre], i + 1);
    }
    int sol = 0;
    for (int i = 0; i < 7; ++i) {
        if (first[i] <= n) {
            sol = max(sol, last[i] - first[i]);
        }
    }
    cout << sol << "\n";
    return 0;
}

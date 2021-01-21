/*
ID: izhang01
TASK: proximity
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("proximity.in", "r", stdin);
    freopen("proximity.out", "w", stdout);
}


int main() {
    setIO();
    int n, k, a;
    cin >> n >> k;
    unordered_map<int, int> last;
    int sol = -1;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        if (last.find(a) != last.end() && i - last[a] <= k) {
            sol = max(sol, a);
        }
        last[a] = i;
    }
    cout << sol << "\n";
    return 0;
}

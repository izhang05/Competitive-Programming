/*
ID: izhang01
TASK: hps
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    int n;
    cin >> n;
    vector<char> gestures(n);
    for (int i = 0; i < n; ++i) {
        cin >> gestures[i];
    }
    vector<int> h(n);
    vector<int> p(n);
    vector<int> s(n);
    h[0] = gestures[0] == 'S' ? 1 : 0;
    p[0] = gestures[0] == 'H' ? 1 : 0;
    s[0] = gestures[0] == 'P' ? 1 : 0;
    for (int i = 1; i < n; ++i) {
        h[i] = gestures[i] == 'S' ? h[i - 1] + 1 : h[i - 1];
        p[i] = gestures[i] == 'H' ? p[i - 1] + 1 : p[i - 1];
        s[i] = gestures[i] == 'P' ? s[i - 1] + 1 : s[i - 1];
    }
    int sol = 0, current;
    for (int i = 0; i < n; ++i) {
        current = 0;
        current += max({h[i], p[i], s[i]});
        current += max({h[n - 1] - h[i], p[n - 1] - p[i], s[n - 1] - s[i]});
        sol = max(sol, current);
    }
    cout << sol << "\n";
    return 0;
}

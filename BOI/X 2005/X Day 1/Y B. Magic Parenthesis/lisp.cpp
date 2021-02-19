/*
ID: izhang01
TASK: lisp
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    freopen("lisp.in", "r", stdin);
    freopen("lisp.out", "w", stdout);
#endif
}


int main() {
    setIO();
    int n, m;
    cin >> n >> m;
    string s;
    int depth = 0, j = 0, seen = 0;
    vector<int> sol(m);
    while (seen < n) {
        cin >> s;
        seen += s.size();
        for (char i : s) {
            if (i == '(') {
                ++depth;
            } else if (i == ')') {
                --depth;
            } else {
                sol[j++] = 1;
                --depth;
            }
            if (depth < 0) {
                cout << 0 << "\n";
                return 0;
            }
        }
    }
    sol[m - 1] += depth;
    cout << 1 << "\n";
    for (int i = 0; i < m; ++i) {
        cout << sol[i] << "\n";
    }
    return 0;
}

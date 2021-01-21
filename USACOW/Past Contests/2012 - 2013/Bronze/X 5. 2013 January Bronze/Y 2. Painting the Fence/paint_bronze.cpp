/*
ID: izhang01
TASK: paint
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
}


int main() {
    setIO();
    int n;
    cin >> n;
    int a;
    char b;
    map<int, int> diff;
    int pos = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        if (b == 'L') {
            a *= -1;
            ++diff[pos + a];
            --diff[pos];
        } else {
            ++diff[pos];
            --diff[pos + a];
        }
        pos += a;
    }
    int cur = 0, sol = 0;
    for (auto it = diff.begin(); next(it) != diff.end(); ++it) {
        cur += it->second;
        if (cur >= 2) {
            sol += next(it)->first - it->first;
        }
    }
    cout << sol << "\n";
    return 0;
}

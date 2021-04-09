/*
ID: izhang01
TASK: runround
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    freopen("runround.in", "r", stdin);
    freopen("runround.out", "w", stdout);
    freopen("runround.out", "w", stderr);
}
//#define DEBUG

bool check(long long x) {
#ifdef DEBUG
    cout << x << "\n";
#endif
    vector<int> a;
    set<int> digits;
    while (x) {
        if (digits.find(x % 10) != digits.end()) {
            return false;
        }
        a.push_back(x % 10);
        digits.insert(x % 10);
        x /= 10;
    }
    reverse(a.begin(), a.end());
    set<int> visited;
    int cur = 0;
    visited.insert(0);
    for (int i = 0; i < (int) a.size() - 1; ++i) {
        cur = (cur + a[cur]) % a.size();
#ifdef DEBUG
        cout << cur << "\n";
#endif
        if (visited.find(cur) != visited.end()) {
            return false;
        }
    }
    cur = (cur + a[cur]) % a.size();
    return visited.find(cur) != visited.end();
}

int main() {
    setIO();
    int m;
    cin >> m;
    for (long long i = m + 1;; ++i) {
        if (check(i)) {
            cout << i << "\n";
            return 0;
        }
    }

    return 0;
}

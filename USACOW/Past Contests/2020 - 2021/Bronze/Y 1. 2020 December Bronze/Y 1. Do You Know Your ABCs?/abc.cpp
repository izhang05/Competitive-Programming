/*
ID: izhang01
TASK: abc
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    freopen("1.in", "r", stdin);
#endif
}


int main() {
    setIO();
    int n = 7;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    cout << a[0] << " " << a[1] << " " << a[n - 1] - a[0] - a[1] << "\n";
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}


int main() {
    setIO();

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    multiset<int> towers;
    towers.insert(a[0]);
    for (int i = 1; i < n; ++i) {
        auto it = towers.upper_bound(a[i]);
        if (it != towers.end()) {
            towers.erase(it);
        }
        towers.insert(a[i]);
    }
    cout << towers.size() << "\n";
    return 0;
}

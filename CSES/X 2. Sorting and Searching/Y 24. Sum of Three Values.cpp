#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}


int main() {
    setIO();

    int n, x;
    cin >> n >> x;
    map<int, vector<int> > ind;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (ind.find(a[i]) != ind.end()) {
            ind[a[i]].push_back(i);
        } else {
            ind[a[i]] = vector<int>{i};
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (ind.find(x - (a[i] + a[j])) != ind.end()) {
                for (int k : ind[x - (a[i] + a[j])]) {
                    if (k != i && k != j) {
                        cout << i + 1 << " " << j + 1 << " " << k + 1 << "\n";
                        return 0;
                    }
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << "\n";
    return 0;
}

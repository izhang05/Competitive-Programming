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
    int x;
    set<int> sol;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        sol.insert(x);
    }
    cout << sol.size() << "\n";
    return 0;
}

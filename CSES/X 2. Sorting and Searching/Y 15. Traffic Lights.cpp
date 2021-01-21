#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}


int main() {
    setIO();
    int n, x;
    cin >> x >> n;
    set<int> lights;
    lights.insert(0);
    lights.insert(x);
    multiset<int, greater<> > sol;
    sol.insert(x);
    int a;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        auto it = lights.lower_bound(a);
        sol.erase(sol.find(*it - *--it));
        sol.insert(a - *it);
        sol.insert(*++it - a);
        lights.insert(a);
        cout << *sol.begin() << " ";
    }
    return 0;
}

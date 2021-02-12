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

    int n, m;
    cin >> n >> m;
    multiset<int> ticket;
    int a;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        ticket.insert(a);
    }
    int c;
    for (int i = 0; i < m; ++i) {
        cin >> c;
        auto it = ticket.upper_bound(c);
        if (it == ticket.begin()) {
            cout << -1 << "\n";
        } else {
            --it;
            if (*it <= c) {
                cout << *it << "\n";
                ticket.erase(it);
            } else {
                cout << -1 << "\n";
            }
        }
    }
    return 0;
}

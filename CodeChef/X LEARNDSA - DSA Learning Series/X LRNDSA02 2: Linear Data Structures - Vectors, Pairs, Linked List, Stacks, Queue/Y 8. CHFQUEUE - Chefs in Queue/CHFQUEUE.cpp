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

const int mod = 1e9 + 7;

int main() {
    setIO();

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    reverse(a.begin(), a.end());
    long long sol = 1;
    stack<pair<int, int> > q;
    q.push(make_pair(a[0], 0));
    for (int i = 1; i < n; ++i) {
        while (q.top().first >= a[i]) {
            q.pop();
            if (q.empty()) {
                break;
            }
        }
        if (!q.empty()) {
            sol *= (i - q.top().second + 1);
            sol %= mod;
        }
        q.push(make_pair(a[i], i));
    }
    cout << sol << "\n";
    return 0;
}

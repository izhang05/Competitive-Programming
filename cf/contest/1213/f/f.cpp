#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}

int main() {
    setIO("1");

    int n, k;
    if (n == 1) {
        cout << "YES\na\n" << "\n";
        return 0;
    }
    cin >> n >> k;
    vector<int> a(n), ind(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        ind[a[i]] = i;
    }
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        --b[i];
    }
    vector<pair<int, int>> q;
    for (int i = 0; i < n - 1; ++i) {
        if (ind[b[i]] > ind[b[i + 1]]) {
            q.emplace_back(ind[b[i + 1]], -ind[b[i]]);
        }
    }
    for (int i = 0; i < n; ++i) {
        q.emplace_back(i, -i);
    }
    sort(q.begin(), q.end());
    vector<pair<int, int>> comps;
    int first = q[0].first, last = -q[0].second;
    for (int i = 1; i < int(q.size()); ++i) {
        q[i].second *= -1;
        if (q[i].first <= last) {
            last = max(last, q[i].second);
        } else {
            comps.emplace_back(first, last);
            first = q[i].first, last = q[i].second;
        }
    }
    comps.emplace_back(first, last);
    if (int(comps.size()) < k) {
        cout << "NO" << "\n";
        return 0;
    }
    cout << "YES" << "\n";
    vector<char> sol(n);
    char cur = 'a';
    for (auto &i : comps) {
        for (int j = i.first; j <= i.second; ++j) {
            sol[a[j]] = cur;
        }
        if (cur != 'z') {
            ++cur;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << sol[i];
    }
    cout << "\n";
    return 0;
}

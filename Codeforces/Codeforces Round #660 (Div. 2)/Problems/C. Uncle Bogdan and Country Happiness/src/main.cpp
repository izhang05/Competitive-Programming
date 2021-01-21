#include <bits/stdc++.h>

using namespace std;

vector<int> p, h, parent, on;
vector<vector<int> > child;
vector<vector<int> > adj;
bool pos = true;

void find_parent(int n, int pre) {
    parent[n] = pre;
    for (int i : adj[n]) {
        if (i != pre) {
            child[n].push_back(i);
            find_parent(i, n);
        }
    }
}

int find_on(int n) {
    if (child[n].empty()) {
        on[n] = p[n];
        return p[n];
    }
    int sol = p[n];
    for (int i : child[n]) {
        sol += find_on(i);
    }
    on[n] = sol;
    return sol;
}

void solve(int n, int cur, int good, int bad) {
    cur -= p[n];
//    if (cur <= 0) {
//        return;
//    }
    bad = max(0, bad - p[n]);
    good = min(good, cur);
    for (int i : child[n]) {
        if (abs(h[i]) > on[i] || abs(h[i]) % 2 != on[i] % 2 || (h[i] + on[i]) % 2 == 1) {
            pos = false;
            return;
        }
        int happy = (h[i] + on[i]) / 2;
        good -= happy;
        bad -= on[i] - happy;
        if (bad < 0) {
            good += bad;
            bad = 0;
        }
        if (good < 0) {
            pos = false;
            return;
        }
        solve(i, on[i], happy, on[i] - happy);
        if (!pos) {
            return;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        p.clear();
        h.clear();
        p.resize(n);
        h.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> h[i];
        }
        adj.clear();
        adj.resize(n);
        int a, b;
        for (int i = 0; i < n - 1; ++i) {
            cin >> a >> b;
            --a, --b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        parent.clear();
        child.clear();
        parent.resize(n);
        child.resize(n);
        find_parent(0, -1);
        on.clear();
        on.resize(n);
        find_on(0);
        assert(m == on[0]);
        pos = true;
        solve(0, on[0], (h[0] + on[0]) / 2, on[0] - (h[0] + on[0]) / 2);
        if (pos) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    return 0;
}

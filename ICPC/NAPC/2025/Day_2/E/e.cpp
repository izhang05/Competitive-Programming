#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        --b[i];
    }
    vector<pair<int, int>> sol;
    for (int i = n - 1; i >= 0; --i) {
        int st, en;
        for (int j = 0; j < n; ++j) {
            if (a[j] == i) {
                st = j;
            }
            if (b[j] == i) {
                en = j;
            }
        }
//        cout << i << " " << st << " " << en << "\n";
        if (st > en) {
            cout << -1 << "\n";
            return;
        }
        if (st == en) {
            continue;
        }
        stack<int> stac;
        stac.push(en);
        for (int j = en - 1; j >= st + 1; --j) {
            if (a[j] > a[stac.top()] && a[j] < i) {
                stac.push(j);
            }
        }
        while (!stac.empty()) {
            swap(a[st], a[stac.top()]);
            sol.emplace_back(st + 1, stac.top() + 1);
            st = stac.top();
            stac.pop();
        }
    }

    cout << sol.size() << "\n";
    for (auto i: sol) {
        cout << i.first << " " << i.second << "\n";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

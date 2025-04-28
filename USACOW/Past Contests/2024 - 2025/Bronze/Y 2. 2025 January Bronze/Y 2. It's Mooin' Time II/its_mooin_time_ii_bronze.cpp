#include<bits/stdc++.h>

using namespace std;

const int mxa = 1e6 + 5;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> sec(mxa, -1), last(mxa, -1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sec[a[i]] = last[a[i]];
        last[a[i]] = i;
    }
    vector<set<int>> occ(n);
    for (int i = 0; i < mxa; ++i) {
        if (sec[i] != -1) {
            occ[sec[i]].insert(i);
        }
    }
    set<int> cur;
    long long sol = 0;
    for (int i = 0; i < n; ++i) {
        for (auto &j: occ[i]) {
            if (cur.find(j) != cur.end()) {
                sol += int(cur.size()) - 1;
            } else {
                sol += int(cur.size());
            }
        }
        cur.insert(a[i]);
    }
    cout << sol << "\n";
}
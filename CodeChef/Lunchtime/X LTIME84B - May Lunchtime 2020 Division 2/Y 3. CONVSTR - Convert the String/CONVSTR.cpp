#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("solution.out", "w", stdout);
    freopen("2.in", "r", stdin);
#endif
    int t, n;
    cin >> t;
    string a, b;
    while (t--) {
        cin >> n;
        cin >> a >> b;
        map<int, vector<int> > a_index, b_index;
        bool stop = false;
        set<int> swaps;
        for (int i = 0; i < n; ++i) {
            if (a[i] < b[i]) {
                cout << -1 << "\n";
                stop = true;
//                cout << i << "\n";
//                cout << a[i] << "\n";
//                cout << b[i] << "\n";
                break;
            }
            if (a[i] > b[i]) {
                swaps.insert(b[i] - 'a');
            }
            a_index[a[i] - 'a'].push_back(i);
            b_index[b[i] - 'a'].push_back(i);
        }
        if (stop) {
            continue;
        }
        string sol = to_string(swaps.size()) + "\n";
        for (int i = 25; i >= 0; --i) {
            if (!b_index[i].empty()) {
                if (a_index[i].empty()) {
                    cout << -1 << "\n";
//                    cout << i << "\n";
                    stop = true;
                    break;
                } else {
                    if (swaps.count(i)) {
                        if (find(b_index[i].begin(), b_index[i].end(), a_index[i][0]) == b_index[i].end()) {
                            sol += to_string(b_index[i].size() + 1) + " " + to_string(a_index[i][0]);
                        } else {
                            sol += to_string(b_index[i].size());
                        }
                        for (int j : b_index[i]) {
                            sol += " " + to_string(j);
                        }
                        sol += "\n";
                    }
                }
            }
        }
        if (!stop) {
            cout << sol;
        }
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
//    freopen("solution.out", "w", stdout);
freopen("2.in", "r", stdin);
#endif
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    pair<int, vector<int> > solution{n + 1, vector<int>()};
    vector<int> current;
    for (int i = 0; i + n - 1 < m; ++i) {
        current.clear();
        for (int j = 0; j < n; ++j) {
            if (s[j] != t[j + i]) {
                current.push_back(j + 1);
            }
        }
        if (current.size() < solution.first) {
            solution.first = current.size();
            solution.second = current;
        }
    }
    cout << solution.first << "\n";
    for (int i : solution.second) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}

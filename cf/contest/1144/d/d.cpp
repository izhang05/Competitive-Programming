/* Author: izhang05
 * Time: 06-29-2021 14:55:57
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("out.txt", "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

int main() {
    setIO("1");

    int n;
    cin >> n;
    vector<int> a(n + 1);
    map<int, int> occ;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ++occ[a[i]];
    }
    pair<int, int> most;
    for (auto &i : occ) {
        most = max(most, {i.second, i.first});
    }
    cout << n - most.first << "\n";
    int i = 1;
    for (; i <= n; ++i) {
        if (a[i] == most.second) {
            for (int j = i - 1; j > 0; --j) {
                if (a[j] < most.second) {
                    cout << 1 << " " << j << " " << j + 1 << "\n";
                } else {
                    cout << 2 << " " << j << " " << j + 1 << "\n";
                }
            }
            break;
        }
    }
    for (int j = i + 1; j <= n; ++j) {
        if (a[j] < most.second) {
            cout << 1 << " " << j << " " << j - 1 << "\n";
        } else if (a[j] > most.second) {
            cout << 2 << " " << j << " " << j - 1 << "\n";
        }
    }
    return 0;
}

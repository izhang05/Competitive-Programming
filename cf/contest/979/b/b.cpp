/* Author: izhang05
 * Time: 07-27-2021 22:52:41
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

    int m;
    cin >> m;
    vector<string> a(3);
    for (int i = 0; i < 3; ++i) {
        cin >> a[i];
    }
    int n = (int) a[0].size();
    vector<map<char, int>> occ(3);
    vector<int> mx(3);
    for (int i = 0; i < 3; ++i) {
        for (auto &j : a[i]) {
            ++occ[i][j];
        }
        for (auto &j : occ[i]) {
            mx[i] = max(mx[i], j.second);
        }
        if (m == 1 && mx[i] == n) {
            --mx[i];
        } else {
            ++mx[i];
        }
    }
    if (mx[0] > mx[1] && mx[0] > mx[2]) {
        cout << "Kuro"
             << "\n";
    } else if (mx[1] > mx[0] && mx[1] > mx[2]) {
        cout << "Shiro"
             << "\n";
    } else if (mx[2] > mx[0] && mx[2] > mx[1]) {
        cout << "Katie"
             << "\n";
    } else {
        cout << "Draw" << "\n";
    }
    return 0;
}

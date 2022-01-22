/* Author: izhang
 * Time: 01-22-2022 09:35:03
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

void test_case() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<queue<int>> occ(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        occ[a[i]].push(i);
    }
    vector<int> sol;
    int ind = 0;
    while (ind < n) {
        int mx = ind;
        for (int i = 0; i <= n; ++i) {
            if (occ[i].empty()) {
                sol.push_back(i);
                break;
            } else {
                mx = max(mx, occ[i].front());
            }
        }
        for (int i = ind; i < mx + 1; ++i) {
            occ[a[i]].pop();
        }
        ind = mx + 1;
    }
    cout << sol.size() << "\n";
    for (auto &i : sol) {
        cout << i << " ";
    }
    cout << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}

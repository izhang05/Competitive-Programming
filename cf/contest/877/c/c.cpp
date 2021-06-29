/* Author: izhang05
 * Time: 06-29-2021 15:26:44
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
template<class T>
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}

int main() {
    setIO("1");
    int n;
    cin >> n;
    vector<int> sol;
    sol.reserve(2 * n);
    for (int i = 2; i <= n; i += 2) {
        sol.push_back(i);
    }
    for (int i = 1; i <= n; i += 2) {
        sol.push_back(i);
    }
    for (int i = 2; i <= n; i += 2) {
        sol.push_back(i);
    }
    cout << sol.size() << "\n";
    print(sol);
    return 0;
}

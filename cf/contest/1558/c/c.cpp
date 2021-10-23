/* Author: izhang05
 * Time: 08-24-2021 14:05:02
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
const long long INFL = 0x3f3f3f3f3f3f3f3f;
template<class T>
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] % 2 != i % 2) {
            cout << -1 << "\n";
            return;
        }
    }
    vector<int> sol;
    for (int i = 0; i < n - 1; i += 2) {
        int ind;
        for (int j = 0; j < n; ++j) {
            if (a[j] == i) {
                ind = j;
                break;
            }
        }
        sol.push_back(ind + 1);
        reverse(a.begin(), a.begin() + ind + 1);
        for (int j = 0; j < n; ++j) {
            if (a[j] == i + 1) {
                ind = j;
                break;
            }
        }
        sol.push_back(ind);
        reverse(a.begin(), a.begin() + ind);
        sol.push_back(ind + 2);
        reverse(a.begin(), a.begin() + ind + 2);
        sol.push_back(3);
        reverse(a.begin(), a.begin() + 3);
        sol.push_back(n - i);
        reverse(a.begin(), a.begin() + n - i);
    }

    sol.push_back(n);
    cout << sol.size() << "\n";
    print(sol);
}

int main() {
    setIO("1");

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

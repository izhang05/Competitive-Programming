/* Author: izhang05
 * Time: 06-25-2021 11:35:03
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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> sol(n);
        for (int i = 0; i < n; ++i) {
            sol[i] = i + 1;
        }
        for (int i = 0; i + 1 < n; i += 2) {
            swap(sol[i], sol[i + 1]);
        }
        if (n % 2 == 1) {
            swap(sol[n - 1], sol[n - 2]);
        }
        print(sol);
    }
    return 0;
}

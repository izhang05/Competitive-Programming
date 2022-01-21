/* Author: izhang
 * Time: 01-20-2022 21:50:02
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
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> x(n);
    x[0] = a[0];
    for (int i = 1; i < n; ++i) {
        x[i] = a[i] - a[i - 1];
    }
    vector<int> sol;
    for (int i = 1; i <= n; ++i) {
        bool good = true;
        for (int j = 0; j < n; ++j) {
            if (x[j] != x[j % i]) {
                good = false;
            }
        }
        if (good) {
            sol.push_back(i);
        }
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
    while (test_case_number--) {
        test_case();
    }
    return 0;
}

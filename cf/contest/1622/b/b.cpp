/* Author: izhang05
 * Time: 12-27-2021 09:35:02
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
    string s;
    cin >> s;
    vector<pair<int, int>> z, o;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            z.emplace_back(a[i], i);
        } else {
            o.emplace_back(a[i], i);
        }
    }
    vector<int> sol(n);
    sort(z.begin(), z.end());
    sort(o.begin(), o.end());
    for (int i = 0; i < int(z.size()); ++i) {
        sol[z[i].second] = i + 1;
    }
    for (int i = 0; i < int(o.size()); ++i) {
        sol[o[i].second] = i + int(z.size()) + 1;
    }

    for (int i = 0; i < n; ++i) {
        cout << sol[i] << " \n"[i == n - 1];
    }
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

/* Author: izhang
 * Time: 02-16-2022 17:19:45
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
    set<int> r;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        r.insert(a[i]);
    }
    int sol = 1;
    set<int> l;
    for (int i = 0; i < n; ++i) {
        if (!l.empty()) {
            if (*prev(l.end()) < *r.begin()) {
                ++sol;
                l.clear();
            }
        }
        l.insert(a[i]);
        r.erase(a[i]);
    }
    cout << sol << "\n";
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

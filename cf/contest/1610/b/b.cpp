/* Author: izhang05
 * Time: 12-22-2021 16:30:02
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

void test_case() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    pair<int, int> pos{-1, -1};
    for (int i = 0; i < n; ++i) {
        if (a[i] != a[n - i - 1]) {
            pos.first = a[i], pos.second = a[n - i - 1];
            break;
        }
    }
    if (pos.first == -1) {
        cout << "YES"
             << "\n";
        return;
    }
    vector<int> b;
    for (int i = 0; i < n; ++i) {
        if (a[i] != pos.first) {
            b.push_back(a[i]);
        }
    }
    bool good = true;
    for (int i = 0; i < int(b.size()); ++i) {
        if (b[i] != b[int(b.size()) - i - 1]) {
            good = false;
            break;
        }
    }
    if (good) {
        cout << "YES"
             << "\n";
        return;
    }
    b.clear();
    for (int i = 0; i < n; ++i) {
        if (a[i] != pos.second) {
            b.push_back(a[i]);
        }
    }
    good = true;
    for (int i = 0; i < int(b.size()); ++i) {
        if (b[i] != b[int(b.size()) - i - 1]) {
            good = false;
            break;
        }
    }
    if (good) {
        cout << "YES"
             << "\n";
        return;
    }
    cout << "NO" << "\n";
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

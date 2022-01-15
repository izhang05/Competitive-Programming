/* Author: izhang
 * Time: 01-12-2022 13:16:51
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
    vector<pair<int, int>> a(n);
    set<pair<int, int>> occ;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
        occ.insert({a[i].first, a[i].second});
    }
    sort(a.begin(), a.end(), [](auto left, auto right) {
        return left.first == right.first ? left.second > right.second : left.first < right.first;
    });
    for (int i = 0; i < n; ++i) {
        for (int j = a[i].first; j <= a[i].second; ++j) {
            bool good = true;
            if (j > a[i].first && occ.find({a[i].first, j - 1}) == occ.end()) {
                good = false;
            }
            if (j < a[i].second && occ.find({j + 1, a[i].second}) == occ.end()) {
                good = false;
            }
            if (good) {
                cout << a[i].first << " " << a[i].second << " " << j << "\n";
                break;
            }
        }
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

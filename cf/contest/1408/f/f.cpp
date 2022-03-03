/* Author: izhang
 * Time: 03-02-2022 18:52:07
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

vector<pair<int, int>> sol;
void solve(int l, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < 1 << size; j += 1 << (i + 1)) {
            for (int k = 0; k < 1 << i; ++k) {
                sol.emplace_back(l + j + k, l + j + k + (1 << i));
            }
        }
    }
}

void test_case() {
    int n;
    cin >> n;
    int size = __lg(n);
    solve(0, size), solve(n - (1 << size), size);
    cout << sol.size() << "\n";
    for (auto &i : sol) {
        cout << i.first + 1 << " " << i.second + 1 << "\n";
    }
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}

/* Author: izhang05
 * Time: 12-08-2021 22:18:36
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
set<long long> sol;
vector<int> a;

void gen(int l, int r, long long cur) {
    sol.insert(cur);
    if (a[l] == a[r]) {
        return;
    }
    int mid = (a[l] + a[r]) / 2;
    int ind;
    long long cur_sum = 0;
    for (int i = l; i <= r; ++i) {
        if (a[i] > mid) {
            ind = i;
            break;
        }
        cur_sum += a[i];
    }
    gen(l, ind - 1, cur_sum);
    gen(ind, r, cur - cur_sum);
}

void test_case() {
    int n, q;
    cin >> n >> q;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sol.clear();
    sort(a.begin(), a.end());
    gen(0, n - 1, accumulate(a.begin(), a.end(), 0ll));
    while (q--) {
        int num;
        cin >> num;
        cout << (sol.find(num) != sol.end() ? "Yes" : "No") << "\n";
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

/* Author: izhang
 * Time: 02-25-2022 23:31:49
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
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        ++cnt[a];
    }
    long long sol = 0;
    map<int, int> avail;
    cout << cnt[0];
    if (cnt[0]) {
        avail[0] += cnt[0];
    }
    for (int i = 1; i <= n; ++i) {
        if (avail.empty()) {
            for (int j = i; j <= n; ++j) {
                cout << " " << -1;
            }
            cout << "\n";
            return;
        }
        int num = prev(avail.end())->first;
        sol += i - 1 - num;
        if (--avail[num] == 0) {
            avail.erase(num);
        }
        if (cnt[i]) {
            avail[i] += cnt[i];
        }
        cout << " " << sol + cnt[i];
    }
    cout << "\n";
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

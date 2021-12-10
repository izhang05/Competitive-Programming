#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
#endif
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n = 300;
    map<int, __int128> cnt;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        ++cnt[a];
    }
    for (int i = 0; i < 256; ++i) {
        map<int, __int128> new_cnt;
        for (auto &j: cnt) {
            if (j.first) {
                new_cnt[j.first - 1] += j.second;
            } else {
                new_cnt[6] += j.second;
                new_cnt[8] += j.second;
            }
        }
        swap(cnt, new_cnt);
    }
    __int128 sol = 0;
    for (auto &i: cnt) {
        sol += i.second;
    }
    vector<int> res;
    while (sol) {
        res.push_back(sol % 10);
        sol /= 10;
    }
    reverse(res.begin(), res.end());
    for (auto &i: res) {
        cout << i;
    }


}

int main() {
    setIO("6");

    int test_case_number = 1;
    while (test_case_number--) {
        solve();
    }
    return 0;
}

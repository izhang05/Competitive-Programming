/* Author: izhang05
 * Time: 12-23-2021 02:14:13
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
    vector<long long> cnt(80), a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        if (__builtin_popcountll(a[i]) == 1) {
            ++cnt[2 * __lg(a[i])];
        } else {
            ++cnt[2 * __lg(a[i]) + 1];
        }
    }
    vector<int> sol;
    for (int i = 0; i <= n; ++i) {
        vector<long long> cur_cnt(cnt.begin(), cnt.end()), seq(80);
        long long rem = i;
        for (int j = 78; j >= 0; j -= 2) {
            long long mn = INFL;
            for (int k = 0; k <= j; k += 2) {
                mn = min(mn, cur_cnt[k]);
            }
            mn = min(mn, rem);
            rem -= mn;
            seq[j] = mn;
            for (int k = 0; k <= j; k += 2) {
                cur_cnt[k] -= mn;
            }
        }
        if (rem) {
            break;
        }
        bool good = true;
        for (int j = 79; j >= 0; --j) {
            for (int k = j - j % 2; k < 80 && cur_cnt[j]; k += 2) {
                int sub = min(cur_cnt[j], seq[k]);
                cur_cnt[j] -= sub;
                seq[k] -= sub;
            }
            if (cur_cnt[j]) {
                good = false;
                break;
            }
        }
        if (good) {
            sol.push_back(i);
        }
    }
    if (sol.empty()) {
        cout << -1 << "\n";
        return;
    }
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

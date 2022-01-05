/* Author: izhang
 * Time: 01-04-2022 18:29:19
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
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long double PI = acos((long double) -1);
struct chash {                                       /// use most bits rather than just the lowest ones
    const uint64_t C = (long long) (2e18 * PI) + 71; // large odd number
    const int RANDOM = (int) rng();
    long long operator()(long long x) const { /// https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
        return __builtin_bswap64((x ^ RANDOM) * C);
    }
};
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5, k = 320;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
vector<int> nums[k];
int cnt[k][maxn];

void test_case() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        nums[i / k].push_back(a[i]);
        ++cnt[i / k][a[i]];
    }
    int sol = 0, q;
    cin >> q;
    int rem = k;
    while (q--) {
        int t, l, r;
        cin >> t >> l >> r;
        l += sol - 1;
        l %= n;
        r += sol - 1;
        r %= n;
        if (l > r) {
            swap(l, r);
        }
        if (t == 1) {
            int cur = 0;
            int val;
            for (int i = 0; i < k; ++i) {
                if (cur + int(nums[i].size()) - 1 >= r) {
                    val = nums[i][r - cur];
                    --cnt[i][val];
                    nums[i].erase(nums[i].begin() + r - cur);
                    break;
                }
                cur += int(nums[i].size());
            }
            cur = 0;
            for (int i = 0; i < k; ++i) {
                if (cur + int(nums[i].size()) >= l) {
                    ++cnt[i][val];
                    nums[i].insert(nums[i].begin() + l - cur, val);
                    break;
                }
                cur += int(nums[i].size());
            }
            if (--rem == 0) {
                rem = k;
                for (int i = 0; i < k; ++i) {
                    for (auto &j : nums[i]) {
                        --cnt[i][j];
                    }
                }
                int ind = 0;
                for (auto &i : nums) {
                    for (int j = 0; j < int(i.size()); ++j, ++ind) {
                        a[ind] = i[j];
                    }
                    i.clear();
                }
                for (int i = 0; i < n; ++i) {
                    nums[i / k].push_back(a[i]);
                    ++cnt[i / k][a[i]];
                }
            }
        } else {
            int x;
            cin >> x;
            x += sol - 1;
            x %= n;
            ++x;
            sol = 0;
            int cur = 0;
            for (int i = 0; i < k; ++i) {
                if (cur >= l && cur + int(nums[i].size()) - 1 <= r) {
                    sol += cnt[i][x];
                } else {
                    for (int j = max(0, l - cur); j < min(r - cur + 1, int(nums[i].size())); ++j) {
                        if (nums[i][j] == x) {
                            ++sol;
                        }
                    }
                }
                cur += (int) nums[i].size();
            }
            cout << sol << "\n";
        }
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

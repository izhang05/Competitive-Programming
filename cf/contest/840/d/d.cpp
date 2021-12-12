/* Author: izhang05
 * Time: 12-11-2021 14:16:29
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 3e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
int a[maxn], sol[maxn], k = 5;
map<int, int> best[maxn];
struct query {
    int l, r, k, ind;
};

void dnc(int l, int r, const vector<query> &que) {
    if (r - l <= 1) {
        return;
    }
    int m = (l + r) / 2;
    map<int, int> cnt;
    map<int, int> cur_best;
    ++cnt[a[m - 1]];
    ++cur_best[a[m - 1]];
    for (int i = m - 2; i >= l; --i) {
        ++cnt[a[i]];
        if (cur_best.find(a[i]) != cur_best.end()) {
            ++cur_best[a[i]];
        } else {
            if ((int) cur_best.size() == k) {
                for (auto &j : cur_best) {
                    if (j.second < cnt[a[i]]) {
                        cur_best.erase(j.first);
                    }
                    cur_best[a[i]] = cnt[a[i]];
                    break;
                }
            } else {
                cur_best[a[i]] = cnt[a[i]];
            }
        }
        best[i] = cur_best;
    }

    cnt.clear();
    cur_best.clear();
    ++cnt[a[m]];
    ++cur_best[a[m]];
    for (int i = m + 1; i < r; ++i) {
        ++cnt[a[i]];
        if (cur_best.find(a[i]) != cur_best.end()) {
            ++cur_best[a[i]];
        } else {
            if ((int) cur_best.size() == k) {
                for (auto &j : cur_best) {
                    if (j.second < cnt[a[i]]) {
                        cur_best.erase(j.first);
                    }
                    cur_best[a[i]] = cnt[a[i]];
                    break;
                }
            } else {
                cur_best[a[i]] = cnt[a[i]];
            }
        }
        best[i] = cur_best;
    }
    vector<query> left, right;
    for (auto &i : que) {
        if (i.l < m && i.r >= m) {
            set<int> cand;
            sol[i.ind] = -2;
            for (auto &j : best[i.l]) {
                cand.insert(j.first);
            }
            for (auto &j : best[i.r]) {
                cand.insert(j.first);
            }
            for (auto &j : cand) {
                int cur_cnt = 0;
                for (int n = i.l; n <= i.r; ++n) {
                    if (a[n] == j) {
                        ++cur_cnt;
                    }
                }
                if (cur_cnt > (i.r - i.l + 1) / i.k) {
                    sol[i.ind] = j;
                    break;
                }
            }

        } else if (i.r < m) {
            left.push_back(i);
        } else {
            right.push_back(i);
        }
    }
    dnc(l, m, left), dnc(m, r, right);
}

void test_case() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }
    vector<query> que(q);
    for (int i = 0; i < q; ++i) {
        cin >> que[i].l >> que[i].r >> que[i].k;
        --que[i].l, --que[i].r;
        que[i].ind = i;
        if (que[i].l == que[i].r) {
            sol[i] = a[que[i].l];
        }
    }
    dnc(0, n, que);
    for (int i = 0; i < q; ++i) {
        cout << sol[i] + 1 << "\n";
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

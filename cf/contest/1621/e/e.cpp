/* Author: izhang
 * Time: 01-07-2022 16:16:38
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
struct group {
    int k, ind;
    vector<long long> a;
    long long avg, sum;
    auto operator<=>(const group &other) const {
        return avg <=> other.avg;
    }
};
vector<int> a;
vector<group> b;
bool pre1[maxn], sol[maxn];
int pre2[maxn], pre3[maxn];

void test_case() {
    int n, m;
    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    int cur = 0;
    b.resize(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i].k;
        b[i].ind = cur;
        cur += b[i].k;
        b[i].a.resize(b[i].k);
        for (auto &j : b[i].a) {
            cin >> j;
        }
        b[i].sum = accumulate(b[i].a.begin(), b[i].a.end(), 0ll);
        b[i].avg = (b[i].sum - 1) / b[i].k;
    }
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    pre1[0] = pre2[0] = pre3[0] = 0;
    for (int i = 1; i <= m; ++i) {
        pre1[i] = pre1[i - 1] + (a[i - 1] <= b[i - 1].avg);
        if (i != m) {
            pre2[i] = pre2[i - 1] + (a[i] <= b[i - 1].avg);
        }
        if (i >= 2) {
            pre3[i] = pre3[i - 1] + (a[i - 2] <= b[i - 1].avg);
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < b[i].k; ++j) {
            group new_avg;
            new_avg.avg = (b[i].sum - 1 - b[i].a[j]) / (b[i].k - 1);
            int ind = m - (lower_bound(b.rbegin(), b.rend(), new_avg) - b.rbegin()) - 1;
            if (ind < i) {
                sol[b[i].ind + j] = (pre1[ind + 1] == 0) && (pre2[i] - pre2[ind + 1] <= 0) && (pre1[m] - pre1[i + 1] <= 0) && a[ind + 1] > new_avg.avg;
            } else {
                sol[b[i].ind + j] = (pre1[i] == 0) && (pre3[ind] - pre3[i] <= 0) && (pre1[m] - pre1[ind + 1] <= 0) && a[ind] > new_avg.avg;
            }
        }
    }
    for (int i = 0; i < cur; ++i) {
        cout << sol[i];
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

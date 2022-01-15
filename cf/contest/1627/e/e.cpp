/* Author: izhang
 * Time: 01-15-2022 09:35:01
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
struct ladder {
    pair<int, int> start, end;
    int h;
    long long cost;
};

struct event {
    int x, h, t, ind;
    bool operator<(const event &rhs) const {
        return x == rhs.x ? t < rhs.t : x < rhs.x;
    }
    bool operator>(const event &rhs) const {
        return x == rhs.x ? t < rhs.t : x > rhs.x;
    }
};

void test_case() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<long long> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    vector<ladder> l(k);
    vector<vector<event>> e(n);
    for (int i = 0; i < k; ++i) {
        cin >> l[i].start.first >> l[i].start.second >> l[i].end.first >> l[i].end.second >> l[i].h;
        --l[i].start.first, --l[i].start.second, --l[i].end.first, --l[i].end.second;
        l[i].cost = INFL;
        e[l[i].start.first].push_back({l[i].start.second, l[i].h, 1, i});
        e[l[i].end.first].push_back({l[i].end.second, l[i].h, -1, i});
    }
    for (auto &i : e) {
        sort(i.begin(), i.end());
    }
    for (auto &i : e[0]) {
        l[i.ind].cost = c[0] * i.x;
    }
    for (int i = 1; i < n; ++i) {
        long long mn = INFL;
        for (auto &j : e[i]) {
            if (j.t == -1) {
                mn = min(mn, l[j.ind].cost - l[j.ind].h - c[i] * j.x);
            } else {
                l[j.ind].cost = min(l[j.ind].cost, mn + c[i] * j.x);
            }
        }
        if (i == n - 1) {
            if (mn > INFL / 4) {
                cout << "NO ESCAPE\n";
            } else {
                cout << mn + c[i] * (m - 1) << "\n";
            }
        }
        mn = INFL;
        sort(e[i].begin(), e[i].end(), greater<>());
        for (auto &j : e[i]) {
            if (j.t == -1) {
                mn = min(mn, l[j.ind].cost - l[j.ind].h + c[i] * j.x);
            } else {
                l[j.ind].cost = min(l[j.ind].cost, mn - c[i] * j.x);
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

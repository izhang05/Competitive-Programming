/* Author: izhang05
 * Time: 07-12-2021 18:50:56
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5, k = 450;

struct query {
    int l, r, ind;
    bool operator<(query other) const {
        if (l / k != other.l / k) {
            return l < other.l;
        }
        return (l / k & 1) ? (r < other.r) : (r > other.r);
    }
};
int cnt[maxn], cur = 0, a[maxn], ind_to_num[maxn];
map<int, int> ind;

void add(int x) {
    if (cnt[a[x]] == ind_to_num[a[x]]) {
        --cur;
    }
    if (++cnt[a[x]] == ind_to_num[a[x]]) {
        ++cur;
    }
}

void remove(int x) {
    if (cnt[a[x]] == ind_to_num[a[x]]) {
        --cur;
    }
    --cnt[a[x]];
    if (cnt[a[x]] == ind_to_num[a[x]]) {
        ++cur;
    }
}
int main() {
    setIO("1");

    int n, q;
    cin >> n >> q;
    set<int> nums;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        nums.insert(a[i]);
    }
    int in = 0;
    for (auto &i : nums) {
        ind[i] = in;
        ind_to_num[in] = i;
        ++in;
    }
    for (auto &i : a) {
        i = ind[i];
    }
    vector<query> queries(q);
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        queries[i] = {l, r, i};
    }
    sort(queries.begin(), queries.end());
    vector<long long> sol(q);
    int l = 0, r = -1;
    for (auto &i : queries) {
        while (r < i.r) {
            ++r;
            add(r);
        }
        while (l > i.l) {
            --l;
            add(l);
        }
        while (r > i.r) {
            remove(r);
            --r;
        }
        while (l < i.l) {
            remove(l);
            ++l;
        }
        sol[i.ind] = cur;
    }
    for (auto &i : sol) {
        cout << i << "\n";
    }
    return 0;
}

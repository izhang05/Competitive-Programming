/* Author: izhang
 * Time: 06-24-2024 16:25:01
**/
#include <bits/stdc++.h>

using namespace std;

#if defined LOCAL || defined DEBUG
#include <debug.h>
#else
struct dbg {
    template<class c>
    dbg &operator<<(const c &) { return *this; }
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#endif

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

struct item {
    long long sum, cnt;
};

struct segtree {
    int size{};
    vector<item> t;
    item neutral = {0, 0};

    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        t.resize(2 * size);
    }

    static item merge(item a, item b) {
        return {a.sum + b.sum, a.cnt + b.cnt};
    }

    static item single(long long v) {
        return {v, 1};
    }

    void upd(int p, long long v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            t[x] = merge(t[x], single(v));
            return;
        }
        int m = (lx + rx) / 2;
        if (p < m) {
            upd(p, v, 2 * x + 1, lx, m);
        } else {
            upd(p, v, 2 * x + 2, m, rx);
        }
        t[x] = merge(t[2 * x + 1], t[2 * x + 2]);
    }

    void upd(int p, long long v) {
        upd(p, v, 0, 0, size);
    }

    item query(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) {
            return neutral;
        }
        if (lx >= l && rx <= r) {
            return t[x];
        }
        int m = (lx + rx) / 2;

        return merge(query(l, r, 2 * x + 1, lx, m), query(l, r, 2 * x + 2, m, rx));
    }

    item query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
};

void test_case() {
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    set<int> inds;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        inds.insert(a[i]);
    }
    vector<int> mx(n);
    vector<long long> sum(n);
    for (int i = 0; i < n - 1; ++i) {
        mx[i + 1] = max(mx[i], a[i]);
        sum[i + 1] = sum[i] + a[i];
    }
    map<int, int> ind;
    int cur = 0;
    for (auto &i : inds) {
        ind[i] = cur++;
    }
    vector<long long> sol(n);
    segtree seg;
    seg.init(n);
    priority_queue<int> nums;
    int mx_ind = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] > a[mx_ind]) {
            mx_ind = i;
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        //        item cur_q = seg.query(ind[a[i]] + 1, n);
        //        sol[i] = cur_q.cnt;
        //        if (a[0] + cur_q.sum + c >= a[i] || mx[i] >= a[i]) {
        //            sol[i] += i;
        //        }
        //        seg.upd(ind[a[i]], a[i]);
        //
        sol[i] = inf;
        if (i == mx_ind && a[0] + c < a[i]) {
            sol[i] = 0;
        }

        long long cur_num = a[i] + sum[i] + c;
        multiset<int> rem;
        long long cnt = i;
        while (!nums.empty() && nums.top() > cur_num) {
            cur_num += nums.top();
            rem.insert(nums.top());
            nums.pop();
            ++cnt;
        }
        for (auto &j : rem) {
            nums.push(j);
        }
        nums.push(a[i]);
        sol[i] = min(sol[i], cnt);
    }

    for (auto &i : sol) {
        cout << i << " ";
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

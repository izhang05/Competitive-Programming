#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7, INF = 1e9;

int madd(int a, int b) {
    int c = a + b;
    if (c >= MOD) c -= MOD;
    return c;
}

int msubt(int a, int b) {
    int c = a - b;
    if (c < 0) c += MOD;
    return c;
}

int mmult(int a, int b) {
    return (1ll * a * b) % MOD;
}

int mpow(int a, int b) {
    int c = 1;
    for (; b > 0; a = mmult(a, a), b /= 2) if (b & 1) c = mmult(c, a);
    return c;
}

int minv(int a) {
    return mpow(a, MOD - 2);
}

int n, m, ans[2], whichone = 0;

string str;

vector<int> nums, ops;

struct Fenwick {
    vector<int> tree;

    Fenwick(int n = 0) {
        tree.assign(n + 1, 1);
    }

    int get(int r) {
        int c = 1;
        for (int i = r + 1; i > 0; i -= i & -i) c = mmult(c, tree[i]);
        return c;
    }

    int query(int l, int r) {
        return mmult(get(r), minv(get(l - 1)));
    }

    void update(int x, int y) {
        for (int i = x + 1; i < tree.size(); i += i & -i) tree[i] = mmult(tree[i], y);
    }
};

Fenwick fw;

set<pair<int, int>> set0, set1;

void debug() {
    for (auto p: set0) cout << p.first << " " << p.second << "\n";
    cout << "\n";
    for (auto p: set1) cout << p.first << " " << p.second << "\n";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    cin >> str;

    nums.assign(n, 0);
    ops.assign(n - 1, 0);

    fw = Fenwick(n);

    for (int i = 0; i < n; i++) {
        nums[i] = str[i * 2] - '0';

        fw.update(i, nums[i]);
    }

    for (int i = 0; i < n - 1; i++) ops[i] = str[i * 2 + 1] == '*';

    pair<int, int> p = {0, 0};

    for (int i = 1; i < n; i++) {
        if (ops[i - 1]) p.second = i;
        else {
            set0.insert(p);
            p = {i, i};
        }
    }

    set0.insert(p);

    p = {0, 0};

    for (int i = 1; i < n; i++) {
        if (!ops[i - 1]) p.second = i;
        else {
            set1.insert(p);
            p = {i, i};
        }
    }

    set1.insert(p);

    for (auto p: set0) ans[0] = madd(ans[0], fw.query(p.first, p.second));
    for (auto p: set1) ans[1] = madd(ans[1], fw.query(p.first, p.second));

    cout << ans[whichone] << "\n";

    while (m--) {
        char qt;

        cin >> qt;

        if (qt == 's') {
            int x, y;

            cin >> x >> y;

            x--, y--;

            auto it0x = prev(set0.upper_bound({x, INF}));
            auto it0y = prev(set0.upper_bound({y, INF}));
            auto it1x = prev(set1.upper_bound({x, INF}));
            auto it1y = prev(set1.upper_bound({y, INF}));

            ans[0] = msubt(ans[0], fw.query(it0x->first, it0x->second));

            if (it0y != it0x) ans[0] = msubt(ans[0], fw.query(it0y->first, it0y->second));

            ans[1] = msubt(ans[1], fw.query(it1x->first, it1x->second));

            if (it1y != it1x) ans[1] = msubt(ans[1], fw.query(it1y->first, it1y->second));

            fw.update(x, minv(nums[x]));
            fw.update(y, minv(nums[y]));

            swap(nums[x], nums[y]);

            fw.update(x, nums[x]);
            fw.update(y, nums[y]);

            ans[0] = madd(ans[0], fw.query(it0x->first, it0x->second));

            if (it0y != it0x) ans[0] = madd(ans[0], fw.query(it0y->first, it0y->second));

            ans[1] = madd(ans[1], fw.query(it1x->first, it1x->second));

            if (it1y != it1x) ans[1] = madd(ans[1], fw.query(it1y->first, it1y->second));
        } else if (qt == 'f') {
            int x;

            cin >> x;

            x--;

            if (ops[x]) { // divide
                auto itboth = prev(set0.upper_bound({x, INF}));

                ans[0] = msubt(ans[0], fw.query(itboth->first, itboth->second));

                pair<int, int> p = *itboth;

                set0.erase(itboth);

                ans[0] = madd(ans[0], fw.query(p.first, x));

                set0.insert({p.first, x});

                ans[0] = madd(ans[0], fw.query(x + 1, p.second));

                set0.insert({x + 1, p.second});
            } else { // merge
                auto itleft = prev(set0.upper_bound({x, INF}));
                auto itright = prev(set0.upper_bound({x + 1, INF}));

                ans[0] = msubt(ans[0], fw.query(itleft->first, itleft->second));
                ans[0] = msubt(ans[0], fw.query(itright->first, itright->second));

                pair<int, int> p = {itleft->first, itright->second};

                set0.erase(itleft);
                set0.erase(itright);

                ans[0] = madd(ans[0], fw.query(p.first, p.second));
                set0.insert(p);
            }

            if (!ops[x]) { // divide
                auto itboth = prev(set1.upper_bound({x, INF}));

                ans[1] = msubt(ans[1], fw.query(itboth->first, itboth->second));

                pair<int, int> p = *itboth;

                set1.erase(itboth);

                ans[1] = madd(ans[1], fw.query(p.first, x));

                set1.insert({p.first, x});

                ans[1] = madd(ans[1], fw.query(x + 1, p.second));

                set1.insert({x + 1, p.second});
            } else { // merge
                auto itleft = prev(set1.upper_bound({x, INF}));
                auto itright = prev(set1.upper_bound({x + 1, INF}));

                ans[1] = msubt(ans[1], fw.query(itleft->first, itleft->second));
                ans[1] = msubt(ans[1], fw.query(itright->first, itright->second));

                pair<int, int> p = {itleft->first, itright->second};

                set1.erase(itleft);
                set1.erase(itright);

                ans[1] = madd(ans[1], fw.query(p.first, p.second));
                set1.insert(p);
            }

            ops[x] ^= 1;
        } else if (qt == 'a') {
            whichone ^= 1;
        }

        cout << ans[whichone] << "\n";
    }
}

#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
template<class T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T>
using indexed_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<class T>
void print(T a) {
    for (auto i : a) {
        cout << i << " ";
    }
    cout << "\n";
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
int n;
map<pair<int, int>, int> mem;

int ask(int l, int r, int add) {
    if (mem.find({l, r}) != mem.end()) {
        return mem[{l, r}];
    }
    cout << "?" << " " << l + 1 << " " << r + 1 << endl;
    int a;
    cin >> a;
    return mem[{l, r}] = add - a;
}

void sub(int p, int l, int r) {
    if (p >= l && p <= r) {
        --mem[{l, r}];
    } else {
        return;
    }
    if (l != r) {
        int m = (l + r) / 2;
        sub(p, l, m);
        sub(p, m + 1, r);
    }
}

void answer(int x) {
    cout << "!" << " " << x + 1 << endl;
    sub(x, 0, n - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int t;
    cin >> n >> t;
    while (t--) {
        int k;
        cin >> k;
        int lo = 0, hi = n - 1, mid;
        int used = 0;
        while (lo < hi) {
            mid = (lo + hi) / 2;
            int zero = ask(lo, mid, mid - lo + 1);
            if (used + zero >= k) {
                hi = mid;
            } else {
                used += zero;
                lo = mid + 1;
            }
        }
        answer(lo);
    }
    return 0;
}
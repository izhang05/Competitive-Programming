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

int ask(int l, int r) {
    cout << "?" << " " << l << " " << r << endl;
    int a;
    cin >> a;
    return a;
}

void answer(int x) {
    cout << "!" << " " << x << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int n, t;
    cin >> n >> t;
    while (t--) {
        int k;
        cin >> k;
        int lo = 1, hi = n, mid, sol;
        int used = 0;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            int zero = mid - lo + 1;
            zero -= ask(lo, mid);
            if (used + zero >= k) {
                hi = mid - 1;
                sol = mid;
            } else {
                used += zero;
                lo = mid + 1;
            }
        }
        answer(sol);
    }
    return 0;
}

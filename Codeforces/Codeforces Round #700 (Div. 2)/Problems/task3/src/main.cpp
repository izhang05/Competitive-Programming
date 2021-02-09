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

void sol(int a) {
    cout << "! " << a << endl;
    exit(0);
}

void que(int a) {
    cout << "? " << a << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int lo = 1, hi = n, mid;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        int down, cur, above;
        if (mid - 1 != 0) {
            que(mid - 1);
            cin >> down;
        } else {
            down = 2e9;
        }
        que(mid);
        cin >> cur;
        if (mid + 1 <= n) {
            que(mid + 1);
            cin >> above;
        } else {
            above = 2e9;
        }
        if (cur < down && cur < above) {
            sol(mid);
            return 0;
        }
        if (cur > down) {
            hi = mid - 1;
        } else if (cur > above) {
            lo = mid + 1;
        }
    }
    return 0;
}

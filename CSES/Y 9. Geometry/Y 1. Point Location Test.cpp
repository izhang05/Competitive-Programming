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

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    //freopen("solution.out", "w", stdout);
    freopen("Y 1.in", "r", stdin);
#endif
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

struct point {
    long long x, y;
    void operator-=(const point &rhs) {
        x -= rhs.x;
        y -= rhs.y;
    }
    point operator-(const point &rhs) const {
        return point{x - rhs.x, y - rhs.y};
    }
    long long operator*(const point &rhs) const {
        return (long long) x * rhs.y - (long long) y * rhs.x;
    }
};


int main() {
    setIO();

    int t;
    cin >> t;
    while (t--) {
        point a{}, b{}, c{};
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
        b -= a;
        c -= a;

        long long cross = b * c;
        if (cross < 0) {
            cout << "RIGHT"
                 << "\n";
        } else if (cross > 0) {
            cout << "LEFT"
                 << "\n";
        } else {
            cout << "TOUCH"
                 << "\n";
        }
    }
    return 0;
}

induction c with d hd,
rw add_zero,
rw add_zero,
refl,
rw add_succ,
rw add_succ,
rw add_succ,
rw hd,
refl,
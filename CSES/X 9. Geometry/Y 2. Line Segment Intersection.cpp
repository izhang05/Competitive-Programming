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
    freopen("Y 2.in", "r", stdin);
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
    long long triangle(const point &b, const point &c) const {
        return (b - *this) * (c - *this);
    }
};

void test_case() {
    point p1{}, p2{}, p3{}, p4{};
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;
    for (int rep = 0; rep < 2; ++rep) {
        if ((p2 - p1) * (p4 - p3) == 0) {
            // collinear or parallel
            if (p1.triangle(p2, p3) != 0) {
                // parallel
                cout << "NO"
                     << "\n";
                return;
            } else {
                // collinear
                for (int rep = 0; rep < 2; ++rep) {
                    if (max(p1.x, p2.x) < min(p3.x, p4.x) || max(p1.y, p2.y) < min(p3.y, p4.y)) {
                        cout << "NO" << "\n";
                        return;
                    }
                    swap(p1, p3);
                    swap(p2, p4);
                }
            }
            cout << "YES" << "\n";
            return;
        }
        long long sign1 = (p2 - p1) * (p3 - p1), sign2 = (p2 - p1) * (p4 - p1);
        if ((sign1 < 0 && sign2 < 0) || (sign1 > 0 && sign2 > 0)) {
            cout << "NO"
                 << "\n";
            return;
        }
        swap(p1, p3);
        swap(p2, p4);
    }
    cout << "YES"
         << "\n";
}

int main() {
    setIO();

    int t;
    cin >> t;
    while (t--) {
        test_case();
    }
    return 0;
}

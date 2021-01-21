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
#ifdef DEBUG
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}

int main() {
    setIO();
    long long n, m, b, air, water = 0;
    cin >> n >> m;
    air = n * m;
    map<long long, long long> change;
    long long cur = m;
    for (int i = 0; i < m; ++i) {
        cin >> b;
        if (b) {
            ++change[b];
            --cur;
            air -= b;
        }
    }
    change[0] = 0;
    change[n] = 0;
    for (auto it = change.begin(); next(it) != change.end(); ++it) {
        cur += it->second;
        if (water + (next(it)->first - it->first) * cur < air - (next(it)->first - it->first) * (cur - next(it)->second)) {
            water += (next(it)->first - it->first) * cur;
            air -= (next(it)->first - it->first) * cur;
        } else {
            if (cur > 0) {
                long long diff = air - water;
                if (abs(water + cur * ((diff / 2) / cur) - (air - cur * ((diff / 2) / cur))) <= abs(water + cur * ((diff / 2) / cur + 1) - (air - cur * ((diff / 2) / cur + 1)))) {
                    if (water + cur * ((diff / 2) / cur) == 0) {
                        break;
                    }
                    cout << it->first + (diff / 2) / cur << " " << water + cur * ((diff / 2) / cur) << "\n";
                } else {
                    if (water + cur * ((diff / 2) / cur + 1) == 0) {
                        break;
                    }
                    cout << it->first + (diff / 2) / cur + 1 << " " << water + cur * ((diff / 2) / cur + 1) << "\n";
                }
                return 0;
            }
        }
    }
    cout << 0 << " " << 0 << "\n";
    return 0;
}

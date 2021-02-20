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
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}
//#define DEBUG
void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen("8.in", "r", stdin);
    freopen("8.out", "w", stdout);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

long long n;
int check(long long x) {
    long long used = 0, found = 0;
    for (int i = 1; i < n + 1; ++i) {
        used += min(n, (x - i) / i + 1);
        if ((x - i) % i == 0 && x <= i * n) {
            ++found;
        }
    }
#ifdef DEBUG
    cout << x << " " << used << " " << found << "\n";
#endif
    if (used < (n * n) / 2 + 1) {
        return 0;
    } else if (used - found > (n * n) / 2 + 1) {
        return 2;
    } else {
        if (found) {
            return 1;
        } else {
            return 0;
        }
    }
}

int main() {
#ifdef LOCAL
    auto start_time = chrono::high_resolution_clock::now();
#endif
    setIO();
    cin >> n;
#ifdef DEBUG
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            cout << i * j << "\t";
        }
        cout << "\n";
    }
#endif
    long long lo = 1, hi = n * n, mid;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        int res = check(mid);
        if (res == 1) {
            cout << mid << "\n";
            return 0;
        }
        if (res == 0) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

#ifdef LOCAL
    auto end_time = chrono::high_resolution_clock::now();
    cout << setprecision(6) << fixed;
    cout << "Execution time: " << chrono::duration_cast<chrono::duration<double>>(end_time - start_time).count() << " seconds" << endl;
#endif
    return 0;
}

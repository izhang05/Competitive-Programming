#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
const long long dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

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

const long long inf = 0x3f3f3f3f;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<long long> a(n);
        long long mx = 0;
        for (long long i = 0; i < n; ++i) {
            cin >> a[i];
            mx = max(mx, a[i]);
        }
        if (n == 1 || n == 2) {
            cout << 0 << "\n";
            continue;
        }

        long long diff = -1, m;
        if (a[1] >= a[0]) {
            diff = a[1] - a[0], m = -1;
        } else {
            // a[1] < a[0]
            long long mdiff = a[0] - a[1];
            for (int i = 1; i < n - 1; ++i) {
                if (a[i] > a[i + 1]) {
                    if (a[i] - a[i + 1] != mdiff) {
                        cout << -1 << "\n";
                        continue;
                    }
                } else {
                    diff = a[i + 1] - a[i];
                    break;
                }
            }
            if (diff == -1) {
                cout << 0 << "\n";
                continue;
            }
            m = a[0] + diff - a[1];
            if (m <= mx) {
                cout << -1 << "\n";
                continue;
            }
        }
//        cout << m << " " << mx << "\n";
        bool sol = true;
        for (long long i = 1; i < n - 1; ++i) {
            if (a[i + 1] < a[i]) {
                long long cur = a[i] + diff - a[i + 1];
                if (m == -1) {
                    m = cur;
                } else {
                    if (m != cur) {
                        sol = false;
                        break;
                    }
                }
                if (m <= mx) {
                    sol = false;
                    break;
                }
            } else {
                if (a[i + 1] - a[i] != diff) {
                    sol = false;
                    break;
                }
            }
        }
        for (int i = 0; i < n - 1; ++i) {
            if ((a[i] + diff) % m != a[i + 1]) {
                sol = false;
                break;
            }
        }
        if (!sol) {
            cout << -1 << "\n";
            continue;
        }
        if (m == -1) {
            cout << 0 << "\n";
            continue;
        }
        cout << m << " " << diff << "\n";
//        } else {
//            // a[1] < a[0]
//            long long diff = a[0] - a[1], m = -1;
//            bool sol = true;
//            for (long long i = 1; i < n - 1; ++i) {
//                if (a[i + 1] > a[i]) {
//                    if (a[i] - diff >= 0) {
//                        sol = false;
//                        break;
//                    }
//                    long long cur = a[i + 1] - (a[i] - diff);
//                    if (m == -1) {
//                        m = cur;
//                    } else {
//                        if (m != cur) {
//                            sol = false;
//                            break;
//                        }
//                    }
//                    if (m <= mx) {
//                        sol = false;
//                        break;
//                    }
//                } else {
//                    if (a[i] - a[i + 1] != diff) {
//                        sol = false;
//                        break;
//                    }
//                }
//            }
//            if (!sol) {
//                cout << -1 << "\n";
//                continue;
//            }
//            if (m == -1) {
//                cout << 0 << "\n";
//                continue;
//            }
//            cout << m << " " << m - diff << "\n";
//        }
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <utility>
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
    cout << endl;
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
#define int long long
int ask(vector<int> a) {
    cout << "? ";
    print(a);
    cout.flush();
    int res;
    cin >> res;
    return res;
}

void answer(int sol) {
    cout << "! " << sol << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int n, k;
    cin >> n >> k;
    int rem = n - k, size = -1;
    if (rem % k == 0) {
        int sol = 0;
        for (int i = 0; i < n / k; ++i) {
            vector<int> cur;
            for (int j = 1; j <= k; ++j) {
                cur.push_back(k * i + j);
            }
            sol ^= ask(cur);
        }
        answer(sol);
        return 0;
    }
    for (int i = 2; i <= rem; i += 2) {
        if (rem % i == 0 && rem / i <= k) {
            size = rem / i;
            break;
        }
    }
    if (size == -1) {
        cout << -1 << endl;
        return 0;
    }
    vector<int> a;
    for (int i = 1; i <= k; ++i) {
        a.push_back(i);
    }
    int sol = ask(a);
    for (int i = 0; i < rem / size; ++i) {
        vector<int> cur;
        for (int j = 1; j <= size; ++j) {
            cur.push_back(k + size * i + j);
        }
        for (int j = k; j >= k - size; --j) {
            cur.push_back(j);
        }
        sol ^= ask(cur);
    }
    answer(sol);
    return 0;
}

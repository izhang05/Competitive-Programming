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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), occ(3);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            ++occ[a[i] % 3];
        }
        long long sol = 0;
        int goal = n / 3;
        while (!(occ[0] == occ[1] && occ[1] == occ[2])) {
//            cout << occ[0] << " " << occ[1] << " " << occ[2] << endl;
            for (int i = 0; i < 3; ++i) {
                int next = (i + 1) % 3;
                if (occ[next] < goal) {
                    int move = min(goal - occ[next], occ[i]);
                    sol += move;
                    occ[i] -= move;
                    occ[next] += move;
                }
            }
        }
        cout << sol << "\n";
    }
    return 0;
}

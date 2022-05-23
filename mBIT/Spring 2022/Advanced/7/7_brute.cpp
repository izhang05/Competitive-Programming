#define print_debug true

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

const long long MOD = 1000000007;

using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
        indexed_set;

typedef long long ll;


const ll inf = 1e18;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> T(n), E(n);
    vector<ll> C(n);
    for (int i = 0; i < n; ++i) {
        cin >> T[i] >> E[i] >> C[i];
        E[i]--;
    }

    ll ans = inf;

    if (n > 60) assert(false);
    for (int i = 0; i < (1 << n); ++i) {
        vector<pair<pair<int, int>, ll>> v;
        ll cost = 0;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                v.push_back({{E[j], T[j]}, C[j]});
                cost += C[j];
            }
        }

        sort(v.begin(), v.end());
        int ind = 0;
        bool good = true;
        for (int j = 0; j < m; ++j) {
            while (ind < (int) v.size()) {
                if (v[ind].first.first >= j && v[ind].first.second > 0) {
                    v[ind].first.second--;
                    break;
                } else {
                    ind++;
                }
            }

            if (ind == (int) v.size()) {
                good = false;
                break;
            }
        }

        if (good) {
            ans = min(ans, cost);
        }
    }
    cout << (ans == inf ? -1 : ans) << "\n";
}
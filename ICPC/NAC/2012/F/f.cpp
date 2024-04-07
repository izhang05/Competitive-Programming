#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
template<class T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    indexed_set<pair<int, int>> num;
    vector<int> a(n), ind(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        num.insert({i, a[i]});
        ind[a[i]] = i;
    }
    long long sol = 0;
    for (auto &i: ind) {

    }

}
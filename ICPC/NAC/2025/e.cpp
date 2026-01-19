#include <bits/extc++.h>

using namespace std;

using namespace __gnu_pbds;

template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int INF = 1e9 + 5;

int n, k;

vector<int> h, a, arr, arrswap;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    cin >> n >> k;

    h = a = arr = arrswap = vector(n + 1, 0);

    for(int i = 1; i <= n; i++) cin >> h[i];
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n; i++) {
        if(h[i] >= a[i]) arr[i] = h[i] - a[i];
        else arr[i] = -k * (a[i] - h[i]);
    }

    swap(h, a);

    for(int i = 1; i <= n; i++) {
        if(h[i] >= a[i]) arrswap[i] = h[i] - a[i];
        else arrswap[i] = -k * (a[i] - h[i]);
    }

    vector<pair<int, int>> sortedarr;

    for(int i = 1; i <= n; i++){
        if(arr[i] > 0) sortedarr.push_back({arr[i], i});
    }

    sort(sortedarr.begin(), sortedarr.end(), greater<pair<int, int>>());

    vector<array<int, 3>> segs;
    set<pair<int, int>> st;

    st.insert({1, n});

    for(auto [val, indx] : sortedarr) {
        auto it = st.upper_bound({indx, INF});
        assert(it != st.begin());
        it = prev(it);
        auto [l, r] = *it;
        st.erase(it);

        segs.push_back({l, r, indx});

        if(l <= indx - 1) st.insert({l, indx - 1});
        if(indx + 1 <= r) st.insert({indx + 1, r});
    }

    for(auto [l, r] : st) segs.push_back({l, r, -1});

    vector<long long> prefarr, sufarr;

    prefarr = sufarr = vector(n + 2, 0ll);

    for(int i = 1; i <= n; i++) prefarr[i] = prefarr[i - 1] + arr[i];
    for(int i = n; i >= 1; i--) sufarr[i] = sufarr[i + 1] + arr[i];

    vector<vector<pair<long long, int>>> prefquery(n + 2), sufquery(n + 2);

    for(auto [l, r, indx] : segs) {
        if(indx == -1){
            for(int i = l; i <= r; i++) {
                prefquery[i - 1].push_back({prefarr[i], 1});
                if(l - 2 >= 0) prefquery[l - 2].push_back({prefarr[i], -1});
            }
        }
        else {
            if(indx - l < r - indx) { // iter left
                int val = -arr[indx] + arrswap[indx];

                for(int i = l; i <= indx; i++) {
                    sufquery[indx + 1].push_back({sufarr[i] + val, 1});
                    if(r + 2 <= n + 1) sufquery[r + 2].push_back({sufarr[i] + val, -1});
                }
            }
            else { // iter right
                int val = -arr[indx] + arrswap[indx];

                for(int i = indx; i <= r; i++) {
                    prefquery[indx - 1].push_back({prefarr[i] + val, 1});
                    if(l - 2 >= 0) prefquery[l - 2].push_back({prefarr[i] + val, -1});
                }
            }
        }
    }

    long long ans = 0;

    Tree<pair<long long, int>> orderedset;

    for(int i = 0; i <= n + 1; i++) {
        orderedset.insert({prefarr[i], i});

        for(auto [val, mul] : prefquery[i]) {
            // for(auto x : orderedset) cout << x.first << " ";
            // cout << "\n";
            // cout << val << " " << orderedset.order_of_key({val, -1}) << "\n";

            ans += mul * orderedset.order_of_key({val + 1, -1});
        }
    }

    orderedset.clear();

    for(int i = n + 1; i >= 0; i--) {
        orderedset.insert({sufarr[i], i});

        for(auto [val, mul] : sufquery[i]) {
            ans += mul * orderedset.order_of_key({val + 1, -1});
        }
    }

    cout << ans;
}
#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


void solve() {
    int n;
    cin >> n;
    vector<pair<ll, ll> > a(n);
    multiset<pair<ll, ll> > s;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
        s.insert({a[i].second, a[i].first});
    }
    sort(all(a));
    int sol = 0;
    ll time = 0;
    int i = 0;
    while (!s.empty()) {
        ++sol;
        time += s.begin()->first;
        s.erase(s.find(*s.begin()));
        while (i < n && a[i].first < time) {
            s.erase({a[i].second, a[i].first});
            ++i;
        }
    }
    cout << sol << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

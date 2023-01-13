#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <typename T, typename U>
bool ckmax(T &t, const U &u) {
    return u>t ? t=u,true : false;
}

multiset<char> VALID;

void solve() {
    ll n, k, max_h = 0; cin >> n >> k;
    vector<int> a (n), b (n);
    for (int &x : a) cin >> x, ckmax(max_h, x);
    for (int &x : b) cin >> x;

    vector<ll> cnt (max_h+1,0);
    for (int i = 0; i < n; ++i) {
        cnt[b[i]]++;
        cnt[a[i]]--;
    }

    for (int i = 1; i <= max_h; ++i) cnt[i] += cnt[i-1];
    for (int i = 1; i <= max_h; ++i) cnt[i] += cnt[i-1];

    map<ll,int> idx; idx[0] = 0;
    for (int i = 1; i <= max_h; ++i) {
        ll val = cnt[i]-k; idx[cnt[i]] = i;
        if (idx.find(val) == idx.end()) continue;
        cout << idx[val]+1 << ' ' << i+1 << '\n';
        return;
    }

    cout << "IMPOSSIBLE\n";
}

int main() {
    for (const char c : "ZLOSIJT") if (c) VALID.insert(c);
    cout.precision(9);
    // cin.tie(nullptr)->sync_with_stdio(false);
    int T; cin >> T;
    while (T--) solve();
}
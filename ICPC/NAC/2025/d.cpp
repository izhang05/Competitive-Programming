#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const string imp = "impossible";

int main(){
    int n,m,w,h;
    cin >> n >> m >> w >> h;
    vector<pair<ll, ll>>up(n),bot(m);
    vector<ll> mx(w+1, 1e9), mn(w+1, -1e9);
    if (h % 2 == 1) {
        ++h;
    }
    for(int i=0;i<n;i++) {
        cin >> up[i].first >> up[i].second;
        up[i].second += h;
        mx[up[i].first] = min(mx[up[i].first], up[i].second);
    }
    for(int i=0;i<m;i++) {
        cin >> bot[i].first >> bot[i].second;
        bot[i].second += h;
        mn[bot[i].first] = max(mn[bot[i].first], bot[i].second);
    }
    ll small = h, big = h;
    int cur_up = 0, cur_bot = 0;
    for(int i = 0; i <= w; ++i) {
        while(cur_up + 1 < n && up[cur_up + 1].first <= i) {
            ++cur_up;
        }
        while(cur_bot + 1 < m && bot[cur_bot + 1].first <= i) {
            ++cur_bot;
        }
        if (up[cur_up].first != i) {
            ll rise_up = up[cur_up + 1].second - up[cur_up].second,
            run_up = up[cur_up+1].first - up[cur_up].first;
            ll x_d = i - up[cur_up].first;
            mx[i] = min(mx[i],(up[cur_up].second * run_up + 1ll * rise_up * x_d + run_up - 1) / run_up);
        }
        if (bot[cur_bot].first != i) {
            ll rise_bot = bot[cur_bot+1].second - bot[cur_bot].second,
            run_bot = bot[cur_bot+1].first - bot[cur_bot].first;
            ll x_d = i - bot[cur_bot].first;
            mn[i] = max(mn[i], (bot[cur_bot].second * run_bot + 1ll * rise_bot * x_d) / run_bot);
        }
        if (mx[i] - mn[i] <= 1) {
            cout << imp << endl;
            return 0;
        }
        small = max(small - 1, mn[i] + 1);
        big = min(big + 1, mx[i] - 1);
        if (abs(small) % 2 != i % 2) {
            ++small;
        }
        if (abs(big) % 2 != i % 2) {
            --big;
        }
        // cout << i << " " << small << " " << big << endl;
        if (small > big) {
            cout << imp << endl;
            return 0;
        }
    }
    cout << small - h << " " << big -h << endl;
    return 0;
}
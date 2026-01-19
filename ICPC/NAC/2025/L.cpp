#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const string imp = "impossible";

ll s(__int128_t optx, __int128_t r, __int128_t w, __int128_t h, __int128_t C) {
    __int128_t ans = 0;
    for (__int128_t i = -C; i <= C + 1; ++ i) {
        __int128_t x = optx + i;
        if (x < 0) {
            continue;
        }
        __int128_t ymax = 2*(ll)sqrt((4 * r * r - x *x *w*w)/(long double)(h*h)),ymin = 0;
        while(ymax > ymin + 1) {
            __int128_t y = (ymax + ymin) / 2;
            if (x * x * w * w + y * y * h * h > 4 * r * r) {
                ymax = y;
            } else {
                ymin = y;
            }
        }
        if (x * x * w * w + ymax * ymax * h * h <= 4 * r * r) {
            ans = max(ans, x * ymax);
        }
        if (x * x * w * w + ymin * ymin * h * h <= 4 * r * r) {
            ans = max(ans, x * ymin);
        }
    }
    return (ll)ans;
}

void solve() {
    ll r,w,h;
    cin >> r >> w >> h;
    ll optx = (ll)((sqrt(2) * r)/(long double)w);
    ll opty = (ll)(sqrt(2) * r/(long double)h);
    ll C = 1000;
    ll sol = s(optx, r, w, h, C);
    sol = max(sol, s(opty, r, h, w, C));

    cout << sol << "\n";
}


int main(){
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
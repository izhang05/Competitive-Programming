#include <iostream>
#include <map>
#include <set>
#include <utility>

using namespace std;

#define ll long long
#define MAXN 500500

ll n, arr[MAXN], avg = 0;
ll old[MAXN];
map<ll, ll> cnt;
ll offset = 0; // to be added to keys before checking

int main() {

    scanf("%lld", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
        old[i] = arr[i];
        avg += arr[i];
    }
    avg /= n;

    for (int i = 1; i < n; i++)
        arr[i] += arr[i - 1];
    for (ll i = 0; i < n; i++)
        arr[i] -= (i + 1) * avg;

    for (int i = 0; i < n; i++)
        cnt[arr[i]]++;

    ll ans = n;
    for (int i = 0; i < n; i++) {
        ans = min(ans, n - cnt[-offset]);

        ll cval = old[i] - avg;
        cnt[cval - offset]--;

        offset -= old[i];
        offset += avg;

        cnt[-offset]++;

    }

    printf("%lld\n", ans);


}



//#include <bits/stdc++.h>
//
//using namespace std;
//
////#define DEBUG
//void setIO(const string &name) {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cin.exceptions(istream::failbit);
//#ifdef LOCAL
//    freopen((name + ".in").c_str(), "r", stdin);
//    freopen((name + ".out").c_str(), "w", stdout);
//    freopen((name + ".out").c_str(), "w", stderr);
//#endif
//}
//
//const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
//
//
//int main() {
//    setIO("1");
//
//    int n, x, y;
//    cin >> n >> x >> y;
//    if (x + y > n + 1) {
//        cout << -1 << "\n";
//        return 0;
//    }
//    int cnt = 0;
//    for (int i = y + 1; i <= n - x; ++i) {
//        ++cnt;
//    }
//    if (cnt > x || cnt > y) {
//        cout << -1 << "\n";
//        return 0;
//    }
//    for (int i = y + 1; i <= n - x; ++i) {
//        cout << i << " ";
//    }
//    for (int i = n; i > n - x; --i) {
//        cout << i << " ";
//    }
//    for (int i = 1; i < y + 1; ++i) {
//        cout << i << " ";
//    }
//    cout << "\n";
//    return 0;
//}

#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());

//#define DEBUG
void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    freopen("A.out", "w", stderr);
#endif
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5;
int n;

long long t[2 * maxn], pre[2 * maxn], suf[2 * maxn], sum[2 * maxn];


void update(int p, long long val) {
    p += n;
    sum[p] = val;
    pre[p] = suf[p] = t[p] = max(0ll, val);
    for (; p > 1; p /= 2) {
        int left = p, right = p ^1;
        if (left > right) {
            swap(left, right);
        }
        sum[p / 2] = sum[left] + sum[right];
        pre[p / 2] = max(pre[left], sum[left] + pre[right]);
        suf[p / 2] = max(suf[right], sum[right] + suf[left]);
        t[p / 2] = max({t[left], t[right], suf[left] + pre[right]});
    }
}

long long query(int l, int r) {
    long long res = 0;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
        if (l & 1) {
            res = calc(res, t[l++]);
        }
        if (r & 1) {
            res = calc(res, t[--r]);
        }
    }
    return res;
}

int main() {
    setIO();

    int m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        update(i, a);
    }
#ifdef DEBUG
    for (int j = 1; j < 2 * n; ++j) {
        cout << t[j] << "\n";
    }
    cout << "\n";
    cout << "\n";
#endif
    cout << t[1] << "\n";
    for (int i = 0; i < m; ++i) {
        int b, c;
        cin >> b >> c;
        update(b, c);
        cout << t[1] << "\n";
    }
    return 0;
}

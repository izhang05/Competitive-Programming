#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    freopen("3.in", "r", stdin);
    freopen("3.out", "w", stdout);
#endif
}

//#define DEBUG
int n, q;
vector<int> a;
long long block[450];
int bls;

long long sum(int x) {
    long long ans = 0;
    for (int i = 0; i < x / bls; ++i) {
        ans += block[i];
    }
    for (int i = (x / bls) * bls; i < x; ++i) {
        ans += a[i];
    }
    return ans;
}

void upd(int x, int y) {
    block[x / bls] -= a[x];
    a[x] = y;
    block[x / bls] += y;
}

int main() {
    setIO();
    cin >> n >> q;
    a.resize(n);
    bls = int(sqrt(n));
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        block[i / bls] += a[i];
    }
    for (int i = 0; i < q; ++i) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            upd(x - 1, y);
        } else {
            cout << sum(y) - sum(x - 1) << "\n";
        }
    }
    return 0;
}


//#include <bits/stdc++.h>
//
//using namespace std;
//
//void setIO() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//#ifdef LOCAL
//    freopen("Y 97.in", "r", stdin);
//#endif
//}
//
//const int maxn = 2e5;
//long long bit[2 * maxn];
//int n;
//void update(int p, int val) {
//    for (; p <= n; p += p & (-p)) {
//        bit[p] += val;
//    }
//}
//long long query(int p) {
//    long long res = 0;
//    for (; p > 0; p -= p & (-p)) {
//        res += bit[p];
//    }
//    return res;
//}
//
//int main() {
//    setIO();
//    int m;
//    cin >> n >> m;
//    vector<int> nums(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> nums[i];
//        update(i + 1, nums[i]);
//    }
//    int a, b, c;
//    for (int i = 0; i < m; ++i) {
//        cin >> a >> b >> c;
//        if (a == 1) {
//            update(b, c - nums[b - 1]);
//            nums[b - 1] = c;
//        } else {
//            cout << query(c) - query(b - 1) << "\n";
//        }
//    }
//    return 0;
//}
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
#endif
}
const int inf = 0x3f3f3f3f, maxn = 4e6 + 5, maxs = 25;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
vector<int> a;

long long vals[maxs][maxn], p;

void gen(int l, int r, int depth) {
    if (r - l <= 1) {
        return;
    }
    int m = (l + r) / 2;
    vals[depth][m - 1] = a[m - 1];
    for (int i = m - 2; i >= l; --i) {
        vals[depth][i] = (vals[depth][i + 1] * a[i]) % p;
    }
    vals[depth][m] = a[m];
    for (int i = m + 1; i < r; ++i) {
        vals[depth][i] = (vals[depth][i - 1] * a[i]) % p;
    }
    gen(l, m, depth + 1);
    gen(m, r, depth + 1);
}

void test_case() {
    int n, q;
    cin >> n >> p >> q;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int size = 1;
    while (size < n) {
        size *= 2;
    }
    a.resize(size, 1);
    vector<int> b(q / 64 + 2);
    for (int i = 0; i < q / 64 + 2; ++i) {
        cin >> b[i];
    }
    gen(0, size, 0);
    int bits = __builtin_clz(size);
    int sol = 0, pre_l, pre_r;
    for (int i = 0; i < q; ++i) {
        int l, r;
        if (i % 64 == 0) {
            l = (b[i / 64] + sol) % n;
            r = (b[i / 64 + 1] + sol) % n;
        } else {
            l = (pre_l + sol) % n;
            r = (pre_r + sol) % n;
        }
        if (l > r) {
            swap(l, r);
        }
        if (l == r) {
            sol = (a[l] + 1) % p;
        } else {
            int depth = __builtin_clz(l ^ r) - bits - 1;
            sol = (vals[depth][l] * vals[depth][r] + 1) % p;
        }
        pre_l = l, pre_r = r;
    }
    cout << sol << "\n";
}

int main() {
    setIO("3");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}

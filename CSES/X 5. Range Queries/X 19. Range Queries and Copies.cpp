#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}

using namespace std;
const int LOGN = 30, max_v = 2e6;
long long sum[max_v * LOGN];
int lc[max_v * LOGN], rc[max_v * LOGN];
int n, q, s = 1, ind = 1, len = 2;
void dup(int &k) {
    ind++;
    lc[ind] = lc[k];
    rc[ind] = rc[k];
    sum[ind] = sum[k];
    k = ind;
}

void U(int p, long long val, int &k, int L, int R) {
    if (p < L || R <= p || R <= L) {
        return;
    }
    dup(k);
    if (L + 1 == R) {
        assert(p == L);
        sum[k] = val;
        return;
    }
    int mid = (L + R) / 2;
    U(p, val, lc[k], L, mid);
    U(p, val, rc[k], mid, R);
    sum[k] = sum[lc[k]] + sum[rc[k]];
}

long long S(int qL, int qR, int k, int L, int R) {
    if (qR <= L || R <= qL || R <= L || !k) {
        return 0ll;
    }
    if (qL <= L && R <= qR) {
        return sum[k];
    }
    int mid = (L + R) / 2;
    return S(qL, qR, lc[k], L, mid) + S(qL, qR, rc[k], mid, R);
}

int main() {
    setIO("19");

    return 0;
}

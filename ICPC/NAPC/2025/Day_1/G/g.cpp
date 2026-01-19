#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef complex<double> C;
typedef vector<double> vd;
void fft(vector<C>& a) {
    int n = sz(a), L = 31 - __builtin_clz(n);
    static vector<complex<long double>> R(2, 1);
    static vector<C> rt(2, 1);
    for (static int k = 2; k < n; k *= 2) {
        R.resize(n); rt.resize(n);
        auto x = polar(1.0L, acos(-1.0L) / k);
        rep(i,k,2*k) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
    }
    vi rev(n);
    rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
    rep(i,0,n) if(i < rev[i]) swap(a[i], a[rev[i]]);
    for (int k = 1; k < n; k *= 2)
        for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
            C z = rt[j+k] * a[i+j+k];
            a[i + j + k] = a[i + j] - z;
            a[i + j] += z;
        }
}

vd conv(const vd& a, const vd& b){
    if (a.empty() || b.empty()) return {};
    vd res(sz(a) + sz(b) - 1);
    int L = 32 - __builtin_clz(sz(res)), n = 1 << L;
    vector<C> in(n), out(n);
    copy(all(a), begin(in));
    rep(i,0,sz(b)) in[i].imag(b[i]);
    fft(in);
    for (C& x : in) x *= x;
    rep(i,0,n) out[i] = in[-i & (n - 1)] - conj(in[i]);
    fft(out);
    rep(i,0,sz(res)) res[i] = imag(out[i]) / (4 * n);
    return res;
}

int n, q;

vector<int> perm;
vector<vector<long long>> sums;

vector<int> uniqsizes;

vector<bool> vis;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;

    perm.assign(n + 1, 0);
    for(int i = 1; i <= n; i++) cin >> perm[i];

    sums.assign(n + 1, {});

    vis.assign(n + 1, false);

    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            vector<double> a, b;

            int x = i;

            while(!vis[x]){
                vis[x] = true;

                a.push_back(x);

                x = perm[x];
            }

            b.push_back(a[0]);
            for(int j = a.size() - 1; j >= 1; j--) b.push_back(a[j]);

//            for(auto x : a) cout << x << " ";
//            cout << '\n';
//            for(auto x : b) cout << x << " ";
//            cout << '\n';

            vector<double> c = conv(a, b);

//            for(auto x : c) cout << x << " ";
//            cout << '\n';

            if(sums[a.size()].empty()){
                sums[a.size()].assign(a.size(), 0ll);
                uniqsizes.push_back(a.size());
            }

            for(int i = 0; i < c.size(); i++) sums[a.size()][i % a.size()] += round(c[i]);
        }
    }

    while(q--){
        int k;
        cin >> k;

        long long ans = 0;

        for(auto s : uniqsizes){
            int md = k % s;

            ans += sums[s][md];
        }

        cout << ans << '\n';
    }
}

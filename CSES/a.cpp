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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

using cd = complex<double>;

void fft(vector<cd> &a) {
    int n = a.size(), L = 31 - __builtin_clz(n);
    static vector<complex<long double>> R(2, 1);
    static vector<cd> rt(2, 1); // (^ 10% faster if double)
    for (static int k = 2; k < n; k *= 2) {
        R.resize(n);
        rt.resize(n);
        auto x = polar(1.0L, acos(-1.0L) / k);
        for (int i = k; i < 2 * k; ++i) {
            rt[i] = R[i] = i & 1 ? R[i / 2] * x : R[i / 2];
        }
    }
    vector<int> rev(n);
    for (int i = 0; i < n; ++i) {
        rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
    }
    for (int i = 0; i < n; ++i) {
        if (i < rev[i]) {
            swap(a[i], a[rev[i]]);
        }
    }
    for (int k = 1; k < n; k *= 2) {
        for (int i = 0; i < n; i += 2 * k) {
            for (int j = 0; j < k; ++j) {
                // C z = rt[j+k] * a[i+j+k]; // (25% faster if hand-rolled)  /// include-line
                auto x = (double *) &rt[j + k], y = (double *) &a[i + j + k]; /// exclude-line
                cd z(x[0] * y[0] - x[1] * y[1], x[0] * y[1] + x[1] * y[0]);   /// exclude-line
                a[i + j + k] = a[i + j] - z;
                a[i + j] += z;
            }
        }
    }
}

template<int M>
vector<long long> convMod(const vector<long long> &a, const vector<long long> &b) {
    if (a.empty() || b.empty()) {
        return {};
    }
    vector<long long> res(a.size() + b.size() - 1);
    int B = 32 - __builtin_clz((res).size()), n = 1 << B, cut = int(sqrt(M));
    vector<cd> L(n), R(n), outs(n), outl(n);
    for (int i = 0; i < (int) a.size(); ++i) {
        L[i] = cd((int) a[i] / cut, (int) a[i] % cut);
    }
    for (int i = 0; i < (int) b.size(); ++i) {
        R[i] = cd((int) b[i] / cut, (int) b[i] % cut);
    }
    fft(L), fft(R);
    for (int i = 0; i < n; ++i) {
        int j = -i & (n - 1);
        outl[j] = (L[i] + conj(L[j])) * R[i] / (2.0 * n);
        outs[j] = (L[i] - conj(L[j])) * R[i] / (2.0 * n) / 1i;
    }
    fft(outl), fft(outs);
    for (int i = 0; i < (int) res.size(); ++i) {
        auto av = (long long) lround(real(outl[i])), cv = (long long) lround(imag(outs[i]));
        long long bv = (long long) lround((imag(outl[i]))) + (long long) lround(real(outs[i]));
        res[i] = ((av % M * cut + bv) % M * cut + cv) % M;
    }
    return res;
}

int main() {
    setIO("1");

    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<long long> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    auto sol = convMod<mod>(a, b);
    for (auto &i : sol) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}

/* Author: izhang05
 * Time: 11-02-2021 13:28:56
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("out.txt", "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

template<class T, int N, int MOD>
struct matrix {
    typedef matrix M;
    array<array<T, N>, N> d{};
    int n = N;
    M operator*(const M &m) const {
        assert(N == m.n);
        M a;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                for (int k = 0; k < N; ++k) {
                    a.d[i][j] += d[i][k] * m.d[k][j];
                    a.d[i][j] %= MOD;
                }
            }
        }
        return a;
    }
    vector<T> operator*(const vector<T> &vec) const {
        vector<T> ret(N);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                ret[i] += d[i][j] * vec[j];
                ret[i] %= MOD;
            }
        }
        return ret;
    }
    void operator*=(const M &m) {
        *this = *this * m;
    }
    M operator^(long long p) const {
        assert(p >= 0);
        M a, b(*this);
        for (int i = 0; i < N; ++i) {
            a.d[i][i] = 1;
        }
        while (p) {
            if (p & 1) a = a * b;
            b = b * b;
            p >>= 1;
        }
        return a;
    }
    void operator^=(long long m) {
        *this = *this ^ m;
    }
    M operator+(const M &m) const {
        assert(N == m.n);
        M a;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                a.d[i][j] += d[i][j] + m.d[i][j];
            }
        }
        return a;
    }
    void operator+=(const M &m) {
        *this = *this + m;
    }
    bool operator==(M &m) const {
        if (N != m.n) {
            return false;
        }
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (d[i][j] != m.d[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
};

void solve() {
    matrix<long long, 2, mod> m;
    m.d = {{{{19, 7}}, {{6, 20}}}};
    long long n;
    cin >> n;
    m ^= n;
    cout << m.d[0][0] << "\n";
}

int main() {
    setIO("1");
    int test_case_number = 1;
    while (test_case_number--) {
        solve();
    }
    return 0;
}

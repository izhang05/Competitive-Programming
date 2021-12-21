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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 21;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
long long dp[maxn];
template<class T, int N>
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

int main() {
    setIO("1");


    int n, k, q;
    cin >> n >> k >> q;
    matrix<long long, maxn> adj;
    for (int i = 0; i < n; ++i) {
        string s;
        for (int j = 0; j < n; ++j) {
            adj.d[i][j] = s[j] - '0';
        }
    }
    while (q--) {
        pair<int, int> b, r;
        cin >> b.first >> r.first >> b.second >> r.second;
        --b.first, --r.first, --b.second, --r.second;

    }

    //    if (q == 8) {
    //        cout << "1\n"
    //                "0\n"
    //                "1\n"
    //                "3\n"
    //                "2\n"
    //                "2\n"
    //                "0\n"
    //                "5"
    //             << "\n";
    //    } else if (q == 6) {
    //        cout << "26\n"
    //                "49\n"
    //                "29\n"
    //                "27\n"
    //                "18\n"
    //                "22"
    //             << "\n";
    //    } else if (q == 5) {
    //        cout << "713313311\n"
    //                "716721076\n"
    //                "782223918\n"
    //                "335511486\n"
    //                "539247783"
    //             << "\n";
    //    }
    return 0;
}

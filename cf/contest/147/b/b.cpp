/* Author: izhang05
 * Time: 11-05-2021 09:28:56
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 305;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
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
                a.d[i][j] = d[i][j];
            }
        }
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                for (int k = 0; k < N; ++k) {
                    a.d[i][j] = max(a.d[i][j], d[i][k] + m.d[k][j]);
                    //                    cout << i << " " << j << " " << k << " " << d[i][k] + m.d[k][j] << "\n";
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
        bool first = true;
        while (p) {
            if (p & 1) {
                if (first) {
                    a = b;
                    first = false;
                } else {
                    a = a * b;
                }
            }
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
    int n, m;
    cin >> n >> m;
    matrix<long long, maxn> mat;
    for (int i = 0; i < maxn; ++i) {
        for (int j = 0; j < maxn; ++j) {
            mat.d[i][j] = -INFL;
        }
    }
    for (int i = 0; i < m; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        --a, --b;
        mat.d[a][b] = c, mat.d[b][a] = d;
    }
    //    for (int i = 0; i < n; ++i) {
    //        for (int j = 0; j < n; ++j) {
    //            cout << mat.d[i][j] << " ";
    //        }
    //        cout << "\n";
    //    }
    //    matrix<long long, maxn> cur = mat ^ 2;
    //    cout << "k: " << 2 << "\n";
    //    for (int i = 0; i < n; ++i) {
    //        for (int j = 0; j < n; ++j) {
    //            cout << cur.d[i][j] << " ";
    //        }
    //        cout << "\n";
    //    }
    int lo = 1, hi = n + 2, mid, res = 0;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        matrix<long long, maxn> cur = mat ^ mid;
        //        cout << "k: " << mid << "\n";
        //        for (int i = 0; i < n; ++i) {
        //            for (int j = 0; j < n; ++j) {
        //                cout << cur.d[i][j] << " ";
        //            }
        //            cout << "\n";
        //        }

        bool good = false;
        for (int i = 0; i < n; ++i) {
            if (cur.d[i][i] > 0) {
                good = true;
                break;
            }
        }
        if (good) {
            res = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << res << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        solve();
    }
    return 0;
}

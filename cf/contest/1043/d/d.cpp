/* Author: izhang
 * Time: 01-20-2022 21:50:02
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

const long long m1 = 1e9 + 9, p = 9973;

long long pw[maxn]; // Stores the powers of p modulo m1
int n;

struct shash {
    vector<int> s;
    long long hsh[maxn];

    void calc_hashes() {
        hsh[0] = 1;
        for (int i = 0; i < n; ++i) {
            hsh[i + 1] = ((hsh[i] * p) % m1 + s[i]) % m1;
        }
    }

    long long get_hash(int a, int b) { // [a, b]
        return (hsh[b + 1] - (hsh[a] * pw[b - a + 1]) % m1 + m1) % m1;
    }

    void init(const vector<int> &S) {
        s = S;
        calc_hashes();
    }
};

void test_case() {
    pw[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        pw[i] = (pw[i - 1] * p) % m1;
    }
    int m;
    cin >> n >> m;
    vector<vector<int>> a(m, vector<int>(n)), ind(m, vector<int>(n));
    vector<shash> s(m);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            --a[i][j];
            ind[i][a[i][j]] = j;
        }
        s[i].init(a[i]);
    }
    long long sol = 0;
    for (int i = 0; i < n; ++i) {
        int lo = i, hi = n - 1, mid, res = i - 1;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            bool good = true;
            long long hsh = s[0].get_hash(i, mid);
            for (int j = 1; j < m && good; ++j) {
                int start = ind[j][a[0][i]], end = mid - i + start;
                if (end >= n || s[j].get_hash(ind[j][a[0][i]], end) != hsh) {
                    good = false;
                }
            }
            if (good) {
                res = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        sol += res - i + 1;
    }
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}

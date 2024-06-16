/* Author: izhang
 * Time: 06-03-2024 10:35:01
**/
#include <bits/stdc++.h>

using namespace std;

#if defined LOCAL || defined DEBUG
#include <debug.h>
#else
struct dbg {
    template<class c>
    dbg &operator<<(const c &) { return *this; }
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#endif

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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

void test_case() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> b[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 1) {
                for (int k = 0; k < n; ++k) {
                    swap(a[k][0], a[k][j]);
                }
            }
            if (b[i][j] == 1) {
                swap(b[i], b[0]);
                for (int k = 0; k < n; ++k) {
                    swap(b[k][0], b[k][j]);
                }
            }
        }
    }
    sort(a.begin(), a.end(), [](auto left, auto right) {
        return left[0] < right[0];
    });
    sort(b.begin(), b.end(), [](auto left, auto right) {
        return left[0] < right[0];
    });
    dbg() << imie(a);
    dbg() << imie(b);
    vector<int> a0 = a[0], b0 = b[0];
    sort(a0.begin(), a0.end());
    sort(b0.begin(), b0.end());
    if (a0 != b0) {
        cout << "NO"
             << "\n";
        return;
    }
    map<int, int> tmp_ind;
    for (int i = 0; i < m; ++i) {
        tmp_ind[b[0][i]] = i;
    }
    vector<int> ind(m);
    for (int i = 0; i < m; ++i) {
        ind[i] = tmp_ind[a[0][i]];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] != b[i][ind[j]]) {
                cout << "NO"
                     << "\n";
                return;
            }
        }
    }

    cout << "YES"
         << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}

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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxx = 1e6 + 1;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

void test_case() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<long long> d(maxx);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++d[a[i]];
    }
    sort(a.begin(), a.end());
    long long sol = 0;
    for (int i = 1; i < maxx; ++i) {
        for (long long j = 2; i * j < maxx; ++j) {
            d[i] += d[i * j];
        }
    }
    for (int i = 1; i < maxx; ++i) {
        if (d[i]) {
            bool good = true;
            for (long long j = 2; i * j < maxx; ++j) {
                if (d[i * j] == d[i]) {
                    good = false;
                }
            }
            sol += good;
        }
    }
    cout << sol - n << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}

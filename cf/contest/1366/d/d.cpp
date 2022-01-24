/* Author: izhang
 * Time: 01-23-2022 20:53:10
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxc = 1e7 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
int f[maxc];

void test_case() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 2; i < maxc; ++i) {
        if (!f[i]) {
            for (int j = i + i; j < maxc; j += i) {
                if (!f[j]) {
                    f[j] = i;
                }
            }
        }
    }
    vector<int> d1(n), d2(n);
    for (int i = 0; i < n; ++i) {
        bool found = false;
        vector<int> factors;
        int cur = a[i];
        while (f[cur]) {
            factors.push_back(f[cur]);
            int cur_f = f[cur];
            while (cur % cur_f == 0) {
                cur /= cur_f;
            }
        }
        if (cur != 1) {
            factors.push_back(cur);
        }
        if (factors.size() <= 1) {
            d1[i] = d2[i] = -1;
            continue;
        }
        d1[i] = factors[0];
        d2[i] = accumulate(factors.begin() + 1, factors.end(), 1, multiplies<>());
    }
    for (auto &i : d1) {
        cout << i << " ";
    }
    cout << "\n";
    for (auto &i : d2) {
        cout << i << " ";
    }
    cout << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}

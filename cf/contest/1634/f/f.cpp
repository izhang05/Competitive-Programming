/* Author: izhang
 * Time: 02-06-2022 09:35:02
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
int mod;

void sub(int &a, int b) {
    a -= b;
    if (a < 0) {
        a += mod;
    }
}

void add(int &a, int b) {
    a += b;
    if (a > mod) {
        a -= mod;
    }
}

void test_case() {
    int n, q;
    cin >> n >> q >> mod;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        a[i] -= b[i];
    }
    while (q--) {
        char t;
        int l, r;
        cin >> t >> l >> r;
        --l;
    }
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

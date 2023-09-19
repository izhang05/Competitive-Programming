/* Author: izhang
 * Time: 09-11-2023 18:23:44
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxs = 35;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

void test_case() {
    int n;
    cin >> n;
    vector<long long> a(n), in(maxs), out(maxs);
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % n != 0) {
        cout << "No"
             << "\n";
        return;
    }
    for (auto &i : a) {
        i -= sum / n;
        if (i == 0) {
            continue;
        }
        bool found = false;
        for (int j = 0; j < maxs && !found; ++j) {
            for (int k = 0; k < maxs && !found; ++k) {
                if ((1ll << j) - (1ll << k) == i) {
                    ++in[j], ++out[k];
                    found = true;
                }
            }
        }
        if (!found) {
            cout << "No"
                 << "\n";
            return;
        }
    }
    for (int i = 0; i < maxs; ++i) {
        if (in[i] != out[i]) {
            cout << "No"
                 << "\n";
            return;
        }
    }
    cout << "Yes"
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

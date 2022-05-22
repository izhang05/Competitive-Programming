/* Author: izhang
 * Time: 05-21-2022 14:00:05
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 5e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
long long sieve[maxn];

void test_case() {
    int n;
    cin >> n;
    map<int, int> occ;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        ++occ[a];
    }
    long long sol = 0;
    for (auto &i : occ) {
        sol += (long long) (i.second) * (i.second - 1);
        sol += sieve[i.first] * i.second;
        dbg() << i.first << " " << i.second << " " << sieve[i.first];
        for (int j = i.first; j < maxn; j += i.first) {
            sieve[j] += i.second;
        }
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

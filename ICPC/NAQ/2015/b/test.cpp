/* Author: izhang
 * Time: 09-18-2023 19:48:20
**/
#include <bits/stdc++.h>

using namespace std;

#include <debug.h>
//#if defined LOCAL || defined DEBUG
//
//
//#else
//struct dbg {
//    template<class c>
//    dbg &operator<<(const c &) { return *this; }
//};
//#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
//#endif

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
const int mxn = 60;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long rnd(long long l, long long r) { // [l, r]
    return uniform_int_distribution<long long>(l, r)(rng);
}

int main() {
    int trials = 10000;
    cout << fixed << setprecision(16);
    for (int i = 1; i < mxn; ++i) {
        int cnt = 0;
        for (int j = 0; j < trials; ++j) {
            vector<int> cur(i + 2, 0);
            cur[0] = cur.back() = 1;
            bool good = false;
            while (!good) {
                vector<int> pos;
                good = true;
                for (int k = 1; k < i + 2; ++k) {
                    if (!cur[k] & !cur[k - 1]) {
                        good = false;
                    }
                    if (!cur[k]) {
                        pos.push_back(k);
                    }
                }
                if (good) {
                    break;
                }
                cur[pos[rnd(0, int(pos.size()) - 1)]] = 1;
            }
            for (auto &k: cur) {
                cnt += !k;
            }
        }
        long double val = (long double) cnt / trials;
        cout << i << " " << val << " " << val / i << endl;
    }
    return 0;
}

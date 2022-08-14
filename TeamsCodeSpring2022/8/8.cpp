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

struct road {
    int s, e, l;
};

void test_case() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    vector<int> a(n);
    for (int i = 1; i < n; ++i) {
        cin >> a[i];
    }
    vector<road> roads(m);
    vector<int> dist(n, inf);
    dist[0] = 0;
    for (auto &i: roads) {
        cin >> i.s >> i.e >> i.l;
        --i.s;
        for (int j = i.e - 1; j >= i.s; --j) {
            int sum = 0;
            for (int k = j + 1; k < i.e && k - j <= i.l; ++k) {
                sum ^= a[k];
                dist[k] = min(dist[k], dist[j] + sum - 16);
                dbg() << j << " " << k << " " << sum - 16;
            }
        }
    }
    cout << dist[n - 1] << "\n";
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

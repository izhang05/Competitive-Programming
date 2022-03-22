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
long long get_hash(const pair<long long, long long> &a) {
    return 2475531 * a.first + a.second; // random large number
}
const int maxn = 21;
int occ[1 << maxn][maxn];

void test_case() {
    int n;
    cin >> n;
    int x, y;
    cin >> x >> y;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    unordered_map<long long, int> comp;
    int ind = 0;
    for (int i = 0; i < 1 << (n / 2); ++i) {
        int cnt = 0;
        pair<long long, long long> cur;
        for (int j = 0; j < n / 2; ++j) {
            if (i & (1 << j)) {
                ++cnt;
                cur.first += a[j].first, cur.second += a[j].second;
            }
        }
        if (comp.find(get_hash(cur)) == comp.end()) {
            comp[get_hash(cur)] = ind++;
        }
        ++occ[comp[get_hash(cur)]][cnt];
    }
    vector<long long> sol(n + 1);
    for (int i = 0; i < 1 << (n - n / 2); ++i) {
        int cnt = 0;
        pair<long long, long long> cur = {x, y};
        for (int j = 0; j < n - n / 2; ++j) {
            if (i & (1 << j)) {
                ++cnt;
                cur.first -= a[j + n / 2].first, cur.second -= a[j + n / 2].second;
            }
        }
        dbg() << cur;
        if (comp.find(get_hash(cur)) != comp.end()) {
            int cur_ind = comp[get_hash(cur)];
            for (int j = 0; j <= n / 2; ++j) {
                sol[cnt + j] += occ[cur_ind][j];
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << sol[i] << "\n";
    }
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}

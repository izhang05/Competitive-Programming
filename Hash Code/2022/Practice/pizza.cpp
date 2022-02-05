#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace chrono;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("input_data/in" + name + ".txt").c_str(), "r", stdin);
    freopen(("output_data/out" + name + ".txt").c_str(), "w", stdout);
#endif
}


using namespace __gnu_pbds;
const long double PI = acos((long double) -1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_real_distribution<double> d(0.0, 1.0);

struct chash {                                       /// use most bits rather than just the lowest ones
    const uint64_t C = (long long) (2e18 * PI) + 71; // large odd number
    const int RANDOM = rng();

    long long operator()(long long x) const { /// https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
        return __builtin_bswap64((x ^ RANDOM) * C);
    }
};

long long rnd(long long l, long long r) {
    return uniform_int_distribution<long long>(l, r)(rng);
}

const int maxn = 1e5 + 5;

long double p(int old, int m, long double temp) {
    if (m >= old) {
        return 1.0;
    }
    return exp((m - old) / temp);
}

gp_hash_table<int, null_type, chash> used;
gp_hash_table<string, int> ind;

struct state {
    vector<int> l, d;
};

state a[maxn];
string topping[10 * maxn];
int cnt[maxn];
bool vis[10 * maxn];

int n;

int calc() {
    int res = 0;
    for (int i = 0; i < n; ++i) {
        bool cur = true;
        for (auto &j: a[i].l) {
            if (used.find(j) == used.end()) {
                cur = false;
                break;
            }
        }
        for (auto &j: a[i].d) {
            if (used.find(j) != used.end()) {
                cur = false;
                break;
            }
        }
        res += cur;
    }
    return res;
}

int main() {
    setIO("5");
    cin >> n;
    int m = 0;
    for (int i = 0; i < n; ++i) {
        int sz;
        cin >> sz;
        a[i].l.resize(sz);
        for (int j = 0; j < sz; ++j) {
            string s;
            cin >> s;
            if (ind.find(s) == ind.end()) {
                topping[m] = s;
                ind[s] = m++;
            }
            a[i].l[j] = ind[s];
            ++cnt[a[i].l[j]];
        }
        cin >> sz;
        a[i].d.resize(sz);
        for (int j = 0; j < sz; ++j) {
            string s;
            cin >> s;
            if (ind.find(s) == ind.end()) {
                topping[m] = s;
                ind[s] = m++;
            }
            a[i].d[j] = ind[s];
            --cnt[a[i].d[j]];
        }
    }
//    for (int i = 0; i < m; ++i) {
//        if (rnd(0, 1)) {
//            vis[i] = true;
//            used.insert(i);
//        }
//    }
    ifstream fin("output_data/log5.txt");
    int x;
    fin >> x;
    for (int i = 0; i < x; ++i) {
        int y;
        fin >> y;
        vis[y] = true;
        used.insert(y);
    }
    int pre = calc();
    long double temp = 1e5, r = 0.999999;
    temp = 0.1;
    int mx = pre;
    int i = 0;
    auto start = steady_clock::now();
    while (true) {
        int change = rnd(0, m - 1);
        if (vis[change]) {
            used.erase(change);
        } else {
            used.insert(change);
        }
        vis[change] ^= 1;
        int cur = calc();
        if (cur > mx) {
            cout << cur << "\n";
            cout << used.size();
            for (auto &i: used) {
                cout << " " << topping[i];
            }
            cout << "\n";
            cout << used.size() << "\n";
            for (auto &i: used) {
                cout << i << " ";
            }
            cout << endl;
        }
        mx = max(mx, cur);
        if (i % 10000 == 0) {
            cout << pre << " " << cur << endl;
        }
        if (p(pre, cur, temp) < d(rng)) {
            if (vis[change]) {
                used.erase(change);
            } else {
                used.insert(change);
            }
            vis[change] ^= 1;
        } else {
            pre = cur;
        }
        temp *= r;
        ++i;
    }
    cout << mx << "\n";
    cout << pre << "\n";
    cout << used.size();
    for (auto &i: used) {
        cout << " " << topping[i];
    }
    cout << "\n";
    cout << used.size() << "\n";
    for (auto &i: used) {
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}

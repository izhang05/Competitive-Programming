#include <bits/stdc++.h>

using namespace std;

#if defined LOCAL || DEBUG
#include <debug.h>
#else
struct dbg {
    template<class c>
    dbg &operator<<(const c &) { return *this; }
};
#endif

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

long long sum(long long a, long long b) { // returns sum from [a ... b)
    a %= mod, b %= mod;
    long long sol = (b * (b - 1)) / 2 % mod;
    sol -= (a * (a - 1)) / 2 % mod;
    sol %= mod;
    return (sol + mod) % mod;
}


int main() {
    setIO("1");
    int n;
    cin >> n;
    vector<pair<long long, long long>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
//    if (n == 3) {
//        cout << "15\n"
//                "36\n"
//                "18"
//             << "\n";
//        return 0;
//    } else if (n == 9) {
//        cout << "4005\n"
//                "4656\n"
//                "7607\n"
//                "3482\n"
//                "3507\n"
//                "3753\n"
//                "4058\n"
//                "1107\n"
//                "24531"
//             << "\n";
//        return 0;
//    }
    map<long long, long long> cur;
    long long sol = 0;
    set<pair<long long, long long>> range;
    range.insert({0, 1});
    for (int i = 0; i < n; ++i) {
        dbg() << i << " range:" << range;
        long long pos = a[i].first;
        long long add = a[i].second - cur[pos];
        cur[pos] = a[i].second;
        while (add) {
            auto it = range.lower_bound({pos, INFL}), p = prev(it);
            if (it == range.end() || it->first - max(p->second, pos) > add) {
                if (pos <= p->second) {
                    sol += sum(p->second, p->second + add);
                    sol %= mod;
                    range.insert({p->first, p->second + add});
                    range.erase(p);
                } else {
                    sol += sum(pos, pos + add);
                    sol %= mod;
                    range.insert({pos, pos + add});
                }
                add = 0;
            } else {
                if (pos <= p->second) {
                    sol += sum(p->second, it->first);
                    sol %= mod;
                    add -= it->first - p->second;
                    range.insert({p->first, it->second});
                    range.erase(it);
                    range.erase(p);
                } else {
                    sol += sum(pos, it->first);
                    sol %= mod;
                    add -= it->first - pos;
                    range.insert({pos, it->second});
                    range.erase(it);
                }
            }
        }
        cout << sol << endl;
    }
    return 0;
}

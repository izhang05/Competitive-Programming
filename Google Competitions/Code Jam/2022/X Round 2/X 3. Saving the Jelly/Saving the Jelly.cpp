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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
const string pos = "POSSIBLE", imp = "IMPOSSIBLE";

long long dist(pair<long long, long long> a, pair<long long, long long> b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}
const int maxn = 12;

void test_case() {
    int n;
    cin >> n;
    vector<pair<long long, long long>> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    pair<long long, long long> blue;
    cin >> blue.first >> blue.second;
    for (int i = 0; i < n; ++i) {
        cin >> b[i].first >> b[i].second;
    }
    vector<int> order(n);
    for (int i = 0; i < n; ++i) {
        order[i] = i;
    }
    vector<vector<int>> closer(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                if (dist(a[i], b[k]) < dist(a[i], b[j])) {
                    closer[i][j] |= 1 << k;
                }
            }
        }
    }
    dbg() << closer[0][0];
    do {
        vector<int> good(n, 0);
        bool bad = false;
        for (int i = 0; i < n; ++i) {
            if (dist(a[i], b[order[i]]) > dist(a[i], blue)) {
                bad = true;
                break;
            }
        }
        if (bad) {
            continue;
        }
        int cur = 0;
        vector<pair<int, int>> sol;
        bool changed = true;
        while (changed) {
            changed = false;
            for (int i = 0; i < n; ++i) {
                if (good[i]) {
                    continue;
                }
                if ((closer[i][order[i]] & cur) == closer[i][order[i]]) {
                    changed = true;
                    cur |= 1 << order[i];
                    good[i] = true;
                    sol.emplace_back(i + 1, order[i] + 2);
                }
            }
        }
        if (int(sol.size()) == n) {
            cout << pos << "\n";
            for (auto &i : sol) {
                cout << i.first << " " << i.second << "\n";
            }
            return;
        }
    } while (std::next_permutation(order.begin(), order.end()));
    cout << imp << "\n";
}

int main() {
    setIO("1");
    int test_case_number = 1;
    cin >> test_case_number;
    for (int i = 1; i <= test_case_number; ++i) {
        dbg() << imie(i);
        cout << "Case #" << i << ": ";
        test_case();
    }
}

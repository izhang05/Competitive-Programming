#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());

//#define DEBUG
void setIO(string name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

long long sq(long long a) {
    return a * a;
}

long long cost(long long a, long long b, long long c) {
    return sq(a - b) + sq(a - c) + sq(b - c);
}

int main() {
    setIO("1");

    int t;
    cin >> t;
    while (t--) {
        vector<int> n(3);
        for (int i = 0; i < 3; ++i) {
            cin >> n[i];
        }
        vector<vector<long long>> gem(3, vector<long long>());
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < n[i]; ++j) {
                int a;
                cin >> a;
                gem[i].push_back(a);
            }
            sort(gem[i].begin(), gem[i].end());
        }
        sort(gem.begin(), gem.end());
        long long sol = 8e18;
        do {
            for (auto i : gem[0]) {
                auto it1 = upper_bound(gem[1].begin(), gem[1].end(), i);
                auto it2 = lower_bound(gem[2].begin(), gem[2].end(), i);
                if (it1 != gem[1].begin() && it2 != gem[2].end()) {
                    --it1;
                    sol = min(sol, cost(i, *it1, *it2));
                }
            }
        } while (next_permutation(gem.begin(), gem.end()));
        cout << sol << "\n";
    }
    return 0;
}

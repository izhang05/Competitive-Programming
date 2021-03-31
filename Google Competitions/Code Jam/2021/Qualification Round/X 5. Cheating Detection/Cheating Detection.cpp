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

const int pl = 100, q = 10000;

bool s[pl][q];
long double diff[q];

long double f(long double x) {
    return (long double) 1 / (1 + exp(-x));
}

void solve() {
    for (auto &i : s) {
        string cur;
        cin >> cur;
        for (int j = 0; j < q; ++j) {
            i[j] = cur[j] - '0';
        }
    }
#ifdef DEBUG
    cout << "\n";
#endif
    int num_buckets = 96;
    vector<vector<int>> buckets(num_buckets);
    for (int i = 0; i < q; ++i) {
        int cur = 0;
        for (auto &j : s) {
            if (j[i]) {
                ++cur;
            }
        }
        cur = max(1, cur);
        cur = min(99, cur);
        long double p = (long double) cur / 100;
        diff[i] = log(-p / (p - 1));
        int ind = floor((diff[i] + 3) * (num_buckets / 6));
        ind = max(0, ind);
        ind = min(num_buckets - 1, ind);
        buckets[ind].push_back(i);
    }
    pair<long double, int> sol = {1e18, 1};
    vector<pair<long double, int>> occ;
    for (int i = 0; i < pl; ++i) {
        long double index = 0;
        for (int j = 0; j < num_buckets / 2; ++j) {
            if (!buckets[j].empty()) {
                int solved = 0;
                for (auto k : buckets[j]) {
                    if (s[i][k]) {
                        ++solved;
                    }
                }
                long double cur = (long double) solved / buckets[j].size();
//                index -= cur;
                index -= (num_buckets / 2 - j) * cur;
            }
        }
        for (int j = num_buckets / 2; j < num_buckets; ++j) {
            if (!buckets[j].empty()) {
                int solved = 0;
                for (auto k : buckets[j]) {
                    if (s[i][k]) {
                        ++solved;
                    }
                }
                long double cur = (long double) solved / buckets[j].size();
//                index += cur;
                index += (j - (num_buckets / 2 - 1)) * cur;
            }
        }
#ifdef DEBUG
        cout << i + 1 << " " << index << "\n";
#endif
        sol = min(sol, {index, i + 1});
        occ.emplace_back(index, i + 1);
    }
    sort(occ.begin(), occ.end());
#ifdef DEBUG
    cout << "\n";
    for (auto j : occ) {
        cout << j.second << " " << j.first << "\n";
    }
#endif
    cout << sol.second << "\n";
}

int main() {
    setIO("1");
    int t;
    cin >> t;
    int _;
    cin >> _;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
}

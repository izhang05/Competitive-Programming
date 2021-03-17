#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());

//#define DEBUG
void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    freopen("1.out", "w", stderr);
#endif
}

template<class T>
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;

pair<int, int> dp[maxn];

int main() {
    setIO();

    long long n, d;
    cin >> n >> d;
    vector<long long> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
        dp[i].second = -1;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = i - 1; j >= 0; --j) {
            if (abs(h[i] - h[j]) >= d) {
                dp[i] = max(dp[i], {dp[j].first + 1, j});
                break;
            }
        }
    }
#ifdef DEBUG
    for (int i = 0; i < n; ++i) {
        cout << dp[i].first << " ";
    }
    cout << "\n";
#endif
    pair<int, int> sol;
    for (int i = 0; i < n; ++i) {
        sol = max(sol, {dp[n - 1].first, i});
    }
    cout << sol.first + 1 << "\n";
    int cur = sol.second;
    vector<int> path;
    while (cur != -1) {
        path.push_back(cur + 1);
        cur = dp[cur].second;
    }
    reverse(path.begin(), path.end());
    print(path);
    return 0;
}

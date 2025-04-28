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

const int mxn = 2e5 + 5;
map<int, long long> cows;
const long long INFL = 1e18;
long long sol = 0, sum = 0, mn = INFL, cnt = 0, a, b;
set<int> vis;

void dfs(int c) {
    vis.insert(c);
    ++cnt;
    mn = min(mn, cows[c]);
    sum += cows[c];
    if (vis.find(a - c) == vis.end() && cows.find(a - c) != cows.end()) {
        dfs(a - c);
    }
    if (vis.find(b - c) == vis.end() && cows.find(b - c) != cows.end()) {
        dfs(b - c);
    }
}


int main() {
    setIO("1");
    int n;
    cin >> n >> a >> b;
    for (int i = 0; i < n; ++i) {
        int d, num;
        cin >> num >> d;
        cows[d] = num;
    }
    for (auto &i: cows) {
        if (vis.find(i.first) == vis.end()) {
            sum = 0, mn = INFL, cnt = 0;
            dfs(i.first);
            if (cnt % 2 == 0) {
                sol += sum;
            } else {
                sol += sum - mn;
            }
        }
    }
    cout << sol << "\n";
    return 0;
}

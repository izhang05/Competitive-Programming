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

int n, k;
int solve(const vector<int> &a, const vector<int> &b) {
    map<int, int> ind;
    for (int i = 0; i < k; ++i) {
        ind[a[i]] = i;
    }
    map<int, int> cnt;
    for (int i = 0; i < k; ++i) {
        if (ind.find(b[i]) != ind.end()) {
            cnt[(i - ind[b[i]] + k) % k]++;
        }
    }
    int sol = 0;
    for (auto &i : cnt) {
        sol = max(sol, i.second);
    }
    return sol;
}

int main() {
    setIO("1");

    cin >> n >> k;
    set<int> nums;
    vector<int> a(k);
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
        nums.insert(a[i]);
    }
    vector<int> b(k);
    for (int i = 0; i < k; ++i) {
        cin >> b[i];
        nums.insert(b[i]);
    }
    int sol = solve(a, b);
    reverse(b.begin(), b.end());
    sol = max(sol, solve(a, b)) + n - int(nums.size());
    cout << sol << "\n";
    return 0;
}

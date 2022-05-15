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
const string imp = "IMPOSSIBLE";
vector<pair<int, int>> sol;

void solve(int n, int add, int cut, int cur) {
    if (n == 1) {
        return;
    }
    if (cur % (n - 1) == 0) {
        ++cur;
    }
    bool found = false;
    for (int i = 1; i <= 4; ++i) {
        if (cur < min(i * (n - 1), 4 * n - 5) && cut >= 4 * n - 4 - 2 * i) {
            sol.emplace_back(cur + add, cur + add + 4 * n - 3 - 2 * i);
            solve(n - 2, add + 4 * n - 4, cut - (4 * n - 4 - 2 * i), cur + 1 - 2 * i);
            found = true;
            break;
        }
        if (cur <= i * (n - 1)) {
            cur = i * (n - 1) + 1;
        }
    }
    if (!found) {
        solve(n - 2, add + 4 * n - 4, cut, 0);
    }
}


void test_case() {
    int n, k;
    cin >> n >> k;
    if (k < n - 1) {
        cout << imp << "\n";
        return;
    }
    int cut = n * n - 1 - k;
    if (cut % 2 == 1) {
        cout << imp << "\n";
        return;
    }
    sol.clear();
    solve(n, 1, cut, 0);
    cout << int(sol.size()) << "\n";
    for (auto &i : sol) {
        cout << i.first << " " << i.second << "\n";
    }
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

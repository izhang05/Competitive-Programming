#include <bits/stdc++.h>

using namespace std;

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

int n;
long long solve(const vector<int> &a) {
    vector<pair<int, int>> nums(n);
    for (int i = 0; i < n; ++i) {
        nums[i] = {a[i], i};
    }
    sort(nums.begin(), nums.end());
    reverse(nums.begin(), nums.end());
    set<int> seen;
    long long sol = 0;
    for (auto &i : nums) {
        auto it = seen.lower_bound(i.second);
        if (it != seen.end()) {
            sol += *it - i.second + 1;
        }
        seen.insert(i.second);
    }
    return sol;
}

void test_case() {
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    long long sol = solve(a);
    reverse(a.begin(), a.end());
    sol += solve(a);
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}

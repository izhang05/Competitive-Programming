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

void test_case() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < 30; ++i) {
        nums[i] = 1 << i;
    }
    nums[n - 1] = 1e9;
    for (int i = n - 2; i >= 30; --i) {
        nums[i] = nums[i + 1] - 1;
    }
    long long our_sum = 0;
    for (auto &i : nums) {
        cout << i << " ";
        our_sum += i;
    }
    cout << endl;
    long long sum = 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    dbg() << imie(our_sum);
    dbg() << imie(sum);
    long long goal = (sum + our_sum) / 2;
    vector<int> sol;
    sort(a.begin(), a.end());
    while (goal >= (1ll << 30)) {
        int which = -1;
        if (nums.empty()) {
            which = 1;
        } else if (a.empty()) {
            which = 0;
        }
        if (which == -1) {
            if (nums.back() > a.back()) {
                which = 0;
            } else {
                which = 1;
            }
        }
        if (which == 0) {
            goal -= nums.back();
            sol.push_back(nums.back());
            nums.pop_back();
        } else {
            goal -= a.back();
            sol.push_back(a.back());
            a.pop_back();
        }
    }
    for (int i = 0; i < 30; ++i) {
        if (goal & (1 << i)) {
            sol.push_back(1 << i);
        }
    }
    for (auto &i : sol) {
//        dbg() << i;
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    setIO("1");
    int test_case_number = 1;
    cin >> test_case_number;
    for (int i = 1; i <= test_case_number; ++i) {
        test_case();
    }
}

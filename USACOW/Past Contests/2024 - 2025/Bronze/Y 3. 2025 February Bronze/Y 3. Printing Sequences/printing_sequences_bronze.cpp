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

vector<int> a;

bool ans(int l, int r, int k) {
    dbg() << a;
    dbg() << l << " " << r << " " << k;
    if (l == r) {
        return true;
    }
    if (k == 1) {
        set<int> nums;
        for (int i = l; i < r; ++i) {
            nums.insert(a[i]);
        }
        return nums.size() == 1;
    }
    set<int> nums;
    for (int i = l; i < r; ++i) {
        nums.insert(a[i]);
    }
    if (nums.size() > k) {
        return false;
    }
    nums.clear();
    for (int i = l; i < r; ++i) {
        nums.insert(a[i]);
        if (nums.size() == 1) {
            if (ans(i + 1, r, k - 1)) {
                return true;
            }
        } else {
            break;
        }
    }
    nums.clear();
    for (int i = r - 1; i >= l; --i) {
        nums.insert(a[i]);
        if (nums.size() == 1) {
            if (ans(l, i, k - 1)) {
                return true;
            }
        } else {
            break;
        }
    }
    nums.clear();

    for (int i = l + 1; i < r; ++i) {
        if ((r - l) % (i - l) != 0) {
            continue;
        }
        bool bad = false;
        for (int j = i, orig = l; j < r; ++j) {
            if (a[j] != a[orig]) {
                bad = true;
                break;
            }
            ++orig;
            if (orig >= i) {
                orig = l;
            }
        }
        if (bad) {
            continue;
        }
        if (ans(l, i, k)) {
            return true;
        }
    }
    return false;
}

void solve() {
    int n, k;
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << (ans(0, n, k) ? "YES" : "NO") << "\n";
}

int main() {
    setIO("1");
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

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


int main() {
    setIO("1");
    int n;
    cin >> n;
    vector<int> a(n);
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    string sol;
    bool dir = true; // false - left, true - right
    int cur = 0;
    while (sum) {
        dbg() << cur << " " << dir << " " << a;
        if (cur == 0) {
            --a[cur];
            ++cur;
            sol += 'R';
            dir = true;
        } else if (cur == n) {
            --a[cur - 1];
            --cur;
            sol += 'L';
            dir = false;
        } else {
            if (dir) {
                if (a[cur]) {
                    --a[cur];
                    ++cur;
                    sol += 'R';
                    dir = true;
                } else {
                    --a[cur - 1];
                    --cur;
                    sol += 'L';
                    dir = false;
                }
            } else {
                if (a[cur - 1] > 1 || a[cur] == 0) {
                    --a[cur - 1];
                    --cur;
                    sol += 'L';
                    dir = false;
                } else {
                    --a[cur];
                    ++cur;
                    sol += 'R';
                    dir = true;
                }
            }
        }
        --sum;
    }
    cout << sol << "\n";
    return 0;
}

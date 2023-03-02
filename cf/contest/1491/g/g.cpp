/* Author: izhang
 * Time: 02-20-2023 17:09:28
**/
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

vector<pair<int, int>> sol;
int n;

void two(const vector<int> &a, const vector<int> &b) {
    for (int i = 0; i < int(b.size()); ++i) {
        sol.emplace_back(a[0], b[i]);
    }
    for (int i = 1; i < int(a.size()); ++i) {
        sol.emplace_back(b[0], a[i]);
    }
    sol.emplace_back(a[0], b[0]);
}
void one(const vector<int> &a) {
    if (a.size() == 1) {
        return;
    }
    if (a.size() == 2) {
        for (int i = 0; i < n; ++i) {
            if (a[0] != i && a[1] != i) {
                two(a, {i});
                return;
            }
        }
    }
    sol.emplace_back(a[0], a[1]);
    sol.emplace_back(a[1], a[2]);
    for (int i = 3; i < int(a.size()); ++i) {
        sol.emplace_back(a[1], a[i]);
    }
    sol.emplace_back(a[0], a[2]);
    sol.emplace_back(a[0], a[1]);
}

void test_case() {
    cin >> n;
    vector<int> p(n), visited(n, false);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
    }
    vector<int> pre;
    for (int i = 0; i < n; ++i) {
        if (visited[i]) {
            continue;
        }
        vector<int> cur_p;
        int cur = i;
        while (!visited[cur]) {
            visited[cur] = true;
            cur_p.push_back(cur);
            cur = p[cur];
        }
        if (pre.empty()) {
            pre = cur_p;
        } else {
            two(pre, cur_p);
            pre.clear();
        }
        dbg() << cur_p;
    }
    if (!pre.empty()) {
        one(pre);
    }
    cout << sol.size() << "\n";
    for (auto &i : sol) {
        cout << i.first + 1 << " " << i.second + 1 << "\n";
    }
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}

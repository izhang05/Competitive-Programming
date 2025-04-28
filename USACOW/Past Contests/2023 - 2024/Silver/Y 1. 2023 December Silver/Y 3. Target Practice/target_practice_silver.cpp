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
    int t, n;
    cin >> t >> n;
    set<int> targets;
    for (int i = 0; i < t; ++i) {
        int a;
        cin >> a;
        targets.insert(a);
    }
    string s;
    cin >> s;
    map<int, int> cnt;
    int cur = 0;
    for (auto &i : s) {
        if (i == 'F' && targets.find(cur) != targets.end()) {
            ++cnt[cur];
        } else if (i == 'L') {
            --cur;
        } else if (i == 'R') {
            ++cur;
        }
    }
    map<int, map<int, int>> diff;
    map<int, int> diff_cnt;
    int sol = cnt.size(), cur_cnt = sol;
    reverse(s.begin(), s.end());
    for (auto &i : s) {
        if (i == 'L') {
            ++cur;
            // change to R
            sol = max(sol, cur_cnt + diff_cnt[2]);

            // change to F
            int cur_sol = cur_cnt + diff_cnt[1];
            if (targets.find(cur) != targets.end() && cnt[cur] == 0 && diff[1][cur] == 0) {
                ++cur_sol;
            }
            sol = max(sol, cur_sol);
        } else if (i == 'R') {
            --cur;
            // change to L
            sol = max(sol, cur_cnt + diff_cnt[-2]);

            // change to F
            int cur_sol = cur_cnt + diff_cnt[-1];
            if (targets.find(cur) != targets.end() && cnt[cur] == 0 && diff[-1][cur] == 0) {
                ++cur_sol;
            }
            sol = max(sol, cur_sol);
        } else if (i == 'F') {
            if (targets.find(cur) != targets.end() && --cnt[cur] == 0) {
                --cur_cnt;
                for (int j = -2; j <= 2; ++j) {
                    if (diff[j][cur]) {
                        ++diff_cnt[j];
                    }
                }
            }
            // change to L
            sol = max(sol, cur_cnt + diff_cnt[-1]);

            // change to R
            sol = max(sol, cur_cnt + diff_cnt[1]);
            for (int j = -2; j <= 2; ++j) {
                if (targets.find(cur + j) != targets.end()) {
                    if (++diff[j][cur + j] == 1 && !cnt[cur + j]) {
                        ++diff_cnt[j];
                    }
                }
            }
        }
    }
    cout << sol << "\n";
    return 0;
}

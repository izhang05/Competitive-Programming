/* Author: izhang
 * Time: 10-15-2023 00:45:01
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

int sdiff = 0, tdiff = 0;
vector<pair<int, int>> cur;
pair<int, vector<pair<int, int>>> sol;

void add(int a, int b) {
    cur.emplace_back(a, b);
    sdiff += b - a;
    tdiff += a - b;
}

void solve(string s, string t) {
    vector<int> sd, td;
    int s_top = s[0] - 'a', t_top = t[0] - 'a';
    int n = int(s.size()), m = int(t.size());
    for (int i = 1; i < n; ++i) {
        if (s[i] != s[i - 1]) {
            sd.push_back(i);
        }
    }
    for (int i = 1; i < m; ++i) {
        if (t[i] != t[i - 1]) {
            td.push_back(i);
        }
    }
    if (sd.empty() && td.empty()) {
        cout << 0 << "\n";
        exit(0);
    }
    reverse(sd.begin(), sd.end());
    reverse(td.begin(), td.end());
    if (s_top == t_top) {
        if (sd.size() > td.size()) {
            add(sd.back(), 0);
            s_top ^= 1;
            sd.pop_back();
        } else {
            add(0, td.back());
            t_top ^= 1;
            td.pop_back();
        }
    }
    while (!sd.empty() && !td.empty()) {
        add(sd.back() + sdiff, td.back() + tdiff);
        sd.pop_back(), td.pop_back();
        dbg() << sd << " " << sdiff;
        dbg() << td << " " << tdiff;
    }
    while (!sd.empty()) {
        if (s_top == t_top) {
            add(sd.back() + sdiff, 0);
            sd.pop_back();
            s_top ^= 1;
        } else {
            add(sd.back() + sdiff, m + tdiff);
            sd.pop_back();
        }
    }
    while (!td.empty()) {
        if (s_top == t_top) {
            add(0, td.back() + tdiff);
            td.pop_back();
            t_top ^= 1;
        } else {
            add(n + sdiff, td.back() + tdiff);
            td.pop_back();
        }
    }
    dbg() << cur;
    if ((int) cur.size() < sol.first) {
        sol.first = (int) cur.size();
        swap(sol.second, cur);
    }
}

void test_case() {
    string s, t;
    cin >> s >> t;
    vector<int> sd, td;
    int n = int(s.size()), m = int(t.size());
    for (int i = 1; i < n; ++i) {
        if (s[i] != s[i - 1]) {
            sd.push_back(i);
        }
    }
    for (int i = 1; i < m; ++i) {
        if (t[i] != t[i - 1]) {
            td.push_back(i);
        }
    }
    if (sd.empty() && td.empty()) {
        cout << 0 << "\n";
        return;
    }
//    reverse(sd.begin(), sd.end());
//    reverse(td.begin(), td.end());
    sol.first = inf;
    solve(s, t);
    if ((int) sd.size() - (int) td.size() >= -20) {
        int diff = ((int) sd.size() - (int) td.size()) / 2;
        for (int i = diff - 50; i <= diff + 50; ++i) {
            if (i < 0 || i >= (int) sd.size()) {
                continue;
            }
            string new_s = s.substr(sd[i]), new_t = s.substr(0, sd[i]) + t;
            dbg() << new_s << " " << new_t;
            cur.clear();
            cur.emplace_back(sd[i], 0);
            sdiff = tdiff = 0;
            solve(new_s, new_t);
        }
    }
    if ((int) td.size() - (int) sd.size() >= -20) {
        int diff = ((int) td.size() - (int) sd.size()) / 2;
        for (int i = diff - 50; i <= diff + 50; ++i) {
            if (i < 0 || i >= (int) td.size()) {
                continue;
            }
            string new_s = t.substr(0, td[i]) + s, new_t = t.substr(td[i]);
            dbg() << new_s << " " << new_t;
            cur.clear();
            cur.emplace_back(0, td[i]);
            sdiff = tdiff = 0;
            solve(new_s, new_t);
        }
    }
    cout << sol.first << "\n";
    for (auto &i : sol.second) {
        cout << i.first << " " << i.second << "\n";
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

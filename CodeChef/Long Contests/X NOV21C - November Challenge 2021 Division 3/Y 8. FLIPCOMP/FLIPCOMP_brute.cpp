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

[[maybe_unused]] const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
long long sol;

void gen(vector<int> s, long long cur) {
//    cout << "cur: " << cur << "\n";
//    for (auto &i : s) {
//        cout << i << " ";
//    }
//    cout << "\n";
    int n = int(s.size());
    bool same = true;
    for (int i = 1; i < n; ++i) {
        if (s[i] != s[0]) {
            same = false;
            break;
        }
    }
    if (same) {
        sol = min(sol, cur);
        return;
    }
    for (int i = 0; i < n; ++i) {
        if ((!i || s[i - 1] != s[i]) && (i == n - 1 || s[i + 1] != s[i])) {
            s[i] ^= 1;
            gen(s, cur + 1);
            s[i] ^= 1;
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        if (s[i + 1] != s[i]) {
            continue;
        }
        int j = i;
        while (j < n && s[i] == s[j]) {
            ++j;
        }
        vector<int> c(i + 1);
        for (int k = 0; k <= i; ++k) {
            c[k] = s[k];
        }
        for (int k = j; k < n; ++k) {
            c.push_back(s[k]);
        }
        gen(c, cur + 1);
        i = j - 1;
    }
}

void solve() {
    string tmp;
    cin >> tmp;
    vector<int> s(tmp.size());
    for (int i = 0; i < (int) tmp.size(); ++i) {
        s[i] = tmp[i] - '0';
    }
    sol = INFL;
    gen(s, 0);
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        solve();
    }
    return 0;
}

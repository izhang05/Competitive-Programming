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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

void test_case() {
    int n, m, p;
    cin >> n >> m >> p;
    vector<string> a(n);
    set<string> b;
    for (auto &i : a) {
        cin >> i;
    }
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        b.insert(s);
    }
    set<pair<int, string>> s;
    s.insert({0, ""});
    for (int i = 0; i < p; ++i) {
        set<pair<int, string>> new_s;
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            if (a[j][i] == '1') {
                ++cnt;
            }
        }
        for (auto &j : s) {
            new_s.insert({j.first + cnt, j.second + "0"});
            new_s.insert({j.first + n - cnt, j.second + "1"});
        }

        while (int(new_s.size()) > 105) {
            new_s.erase(prev(new_s.end()));
        }
        swap(s, new_s);
    }

    for (auto &i : s) {
        if (b.find(i.second) == b.end()) {
            cout << i.first << "\n";
            return;
        }
    }
}

int main() {
    setIO("1");
    int test_case_number = 1;
    cin >> test_case_number;
    for (int i = 1; i <= test_case_number; ++i) {
        cout << "Case #" << i << ": ";
        test_case();
    }
}

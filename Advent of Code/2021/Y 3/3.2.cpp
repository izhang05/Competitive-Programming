#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
#endif
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n = 1000;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    long long oxy = 0, car = 0;
    set<int> valid;
    for (int j = 0; j < n; ++j) {
        valid.insert(j);
    }
    for (int i = 0; i < 12; ++i) {
        set<int> to_e;
        vector<int> cnt(12);
        for (auto &j: valid) {
            for (int k = 0; k < 12; ++k) {
                if (a[j][k] == '1') {
                    ++cnt[k];
                }
            }
        }
        if (cnt[i] * 2 >= valid.size()) {
            for (auto &j: valid) {
                if (a[j][i] == '0') {
                    to_e.insert(j);
                }
            }
        } else {
            for (auto &j: valid) {
                if (a[j][i] == '1') {
                    to_e.insert(j);
                }
            }
        }
        for (auto &j: to_e) {
            valid.erase(j);
        }
        if (valid.size() == 1) {
            for (int j = 0; j < 12; ++j) {
                if (a[*valid.begin()][j] == '1') {
                    oxy |= 1 << (12 - j - 1);
                }
            }
            break;
        }
    }
    valid.clear();
    for (int j = 0; j < n; ++j) {
        valid.insert(j);
    }
    for (int i = 0; i < 12; ++i) {
        set<int> to_e;
        vector<int> cnt(12);
        for (auto &j: valid) {
            for (int k = 0; k < 12; ++k) {
                if (a[j][k] == '1') {
                    ++cnt[k];
                }
            }
        }
        if (cnt[i] * 2 >= valid.size()) {
            for (auto &j: valid) {
                if (a[j][i] == '1') {
                    to_e.insert(j);
                }
            }
        } else {
            for (auto &j: valid) {
                if (a[j][i] == '0') {
                    to_e.insert(j);
                }
            }
        }
        for (auto &j: to_e) {
            valid.erase(j);
        }
        cout << valid.size() << "\n";
        if (valid.size() == 1) {
            for (int j = 0; j < 12; ++j) {
                if (a[*valid.begin()][j] == '1') {
                    car |= 1 << (12 - j - 1);
                }
            }
            break;
        }

    }

    cout << oxy * car << "\n";

}

int main() {
    setIO("3");

    int test_case_number = 1;
    while (test_case_number--) {
        solve();
    }
    return 0;
}

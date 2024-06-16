/* Author: izhang
 * Time: 05-25-2024 20:51:55
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

void test_case() {
    string s;
    cin >> s;
    vector<string> p;
    string cur;
    for (auto &i : s) {
        if (i != '.') {
            cur += i;
        } else {
            if (cur.size() == 0) {
                cout << "NO"
                     << "\n";
                return;
            }
            p.push_back(cur);
            cur.clear();
        }
    }
    if (cur.empty()) {
        cout << "NO\n";
        return;
    } else {
        p.push_back(cur);
    }

    if (p.size() <= 1) {
        cout << "NO"
             << "\n";
        return;
    }
    if (p[0].size() > 8) {
        cout << "NO"
             << "\n";
        return;
    }
    if (p.back().size() > 3) {
        cout << "NO"
             << "\n";
        return;
    }
    for (auto &i : p) {
        if (i.size() > 11) {
            cout << "NO"
                 << "\n";
            return;
        }
    }
    for (int i = 1; i < int(p.size()) - 1; ++i) {
        if (p[i].size() < 2) {
            cout << "NO"
                 << "\n";
            return;
        }
    }
    cout << "YES"
         << "\n";
    cout << p[0] << ".";
    for (int i = 1; i < int(p.size()) - 1; ++i) {
        if (p[i].size() <= 4) {
            cout << p[i][0] << "\n";
            for (int j = 1; j < (int) p[i].size(); ++j) {
                cout << p[i][j];
            }
            cout << ".";
        } else {
            for (int j = 0; j < 3; ++j) {
                cout << p[i][j];
            }
            cout << "\n";
            for (int j = 3; j < (int) p[i].size(); ++j) {
                cout << p[i][j];
            }
            cout << ".";
        }
    }
    cout << p.back() << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}

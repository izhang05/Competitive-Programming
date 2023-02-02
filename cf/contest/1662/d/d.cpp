/* Author: izhang
 * Time: 01-30-2023 14:03:07
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
    string u, v;
    cin >> u >> v;
    int n = int(u.size()), m = int(v.size());
    int a1 = 0, b1 = 0, c1 = 0;
    for (auto &i : u) {
        if (i == 'A') {
            ++a1;
        } else if (i == 'B') {
            ++b1;
        } else if (i == 'C') {
            ++c1;
        }
    }
    int a2 = 0, b2 = 0, c2 = 0;
    for (auto &i : v) {
        if (i == 'A') {
            ++a2;
        } else if (i == 'B') {
            ++b2;
        } else if (i == 'C') {
            ++c2;
        }
    }
    if (!(a1 % 2 == a2 % 2 && b1 % 2 == b2 % 2 && c1 % 2 == c2 % 2)) {
        cout << "NO"
             << "\n";
        return;
    }
    string tmp = u;
    u.clear();
    for (auto &i : tmp) {
        if (i != 'B') {
            u += i;
        }
    }
    tmp = v;
    v.clear();
    for (auto &i : tmp) {
        if (i != 'B') {
            v += i;
        }
    }
    bool found = true;
    while (found) {
        dbg() << u;
        found = false;
        auto it = u.find("AA");
        while (it != string::npos) {
            found = true;
            u.erase(it, 2);
            it = u.find("AA");
        }
        it = u.find("CC");
        while (it != string::npos) {
            found = true;
            u.erase(it, 2);
            it = u.find("CC");
        }
    }
    found = true;
    while (found) {
        found = false;
        auto it = v.find("AA");
        while (it != string::npos) {
            found = true;
            v.erase(it, 2);
            it = v.find("AA");
        }
        it = v.find("CC");
        while (it != string::npos) {
            found = true;
            v.erase(it, 2);
            it = v.find("CC");
        }
    }
    dbg() << imie(u);
    dbg() << imie(v);
    cout << (u == v ? "YES" : "NO") << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}

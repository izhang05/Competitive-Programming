/* Author: izhang
 * Time: 09-18-2023 19:09:01
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
    getline(cin, s);
    set<char> occ, missing;
    for (auto &i: s) {
        occ.insert(tolower(i));
    }
    for (char i = 'a'; i <= 'z'; ++i) {
        if (occ.find(i) == occ.end()) {
            missing.insert(i);
        }
    }
    if (missing.empty()) {
        cout << "pangram" << "\n";
    } else {
        cout << "missing ";
        for (auto &i: missing) {
            cout << i;
        }
        cout << "\n";
    }
}

int main() {
    setIO("1");

    int test_case_number = 1;
    cin >> test_case_number;
    string s;
    getline(cin, s);
    while (test_case_number--) {
        test_case();
    }
    return 0;
}

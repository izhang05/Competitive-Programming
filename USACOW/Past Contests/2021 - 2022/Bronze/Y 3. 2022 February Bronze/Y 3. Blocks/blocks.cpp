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
    int n;
    cin >> n;
    vector<string> b(4);
    for (int i = 0; i < 4; ++i) {
        cin >> b[i];
    }
    sort(b.begin(), b.end());
    set<string> pos;
    do {
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 6; ++j) {
                for (int k = 0; k < 6; ++k) {
                    for (int l = 0; l < 6; ++l) {
                        string cur;
                        cur += b[0][i];
                        pos.insert(cur);
                        cur += b[1][j];
                        pos.insert(cur);
                        cur += b[2][k];
                        pos.insert(cur);
                        cur += b[3][l];
                        pos.insert(cur);
                    }
                }
            }
        }
    } while (next_permutation(b.begin(), b.end()));
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        cout << (pos.find(s) != pos.end() ? "YES" : "NO") << "\n";
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

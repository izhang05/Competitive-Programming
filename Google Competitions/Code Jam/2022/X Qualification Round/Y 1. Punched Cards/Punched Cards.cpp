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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

void test_case() {
    int r, c;
    cin >> r >> c;
    cout << "..+";
    for (int i = 0; i < c - 1; ++i) {
        cout << "-+";
    }
    cout << "\n";
    cout << ".";
    for (int i = 0; i < c; ++i) {
        cout << ".|";
    }
    cout << "\n";
    for (int i = 0; i < r - 1; ++i) {
        cout << "+";
        for (int j = 0; j < c; ++j) {
            cout << "-+";
        }
        cout << "\n";
        cout << "|";
        for (int j = 0; j < c; ++j) {
            cout << ".|";
        }
        cout << "\n";
    }
    cout << "+";
    for (int i = 0; i < c; ++i) {
        cout << "-+";
    }
    cout << "\n";
}

int main() {
    setIO("1");
    int test_case_number = 1;
    cin >> test_case_number;
    for (int i = 1; i <= test_case_number; ++i) {
        cout << "Case #" << i << ":\n";
        test_case();
    }
}

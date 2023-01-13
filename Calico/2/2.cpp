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
//    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("out.txt", "w", stderr);
#endif
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;


bool solve(int y, string s) {
    if (int(s.size()) > 50) {
        return false;
    }
    if (y < 2010) {
        return true;
    }
    s += " ";
    string cur;
    for (auto &i: s) {
        if (i != ' ') {
            cur += i;
        } else {
            if (cur == "california" || cur == "cal" || cur == "berkeley" || cur == "California" || cur == "Cal" ||
                cur == "Berkeley") {
                return false;
            } else {
                return true;
            }
        }
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int Y;
        cin >> Y;
        cin.ignore();
        string N;
        getline(cin, N);
        cout << (solve(Y, N) ? "VALID" : "INVALID") << '\n';
    }
}

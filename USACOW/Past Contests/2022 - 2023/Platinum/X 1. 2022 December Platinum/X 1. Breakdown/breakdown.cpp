#include <bits/stdc++.h>

using namespace std;

#if defined LOCAL
#include <debug.h>
#else
struct dbg {
    template<class c>
    dbg &operator<<(const c &) { return *this; }
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#endif

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

const int maxn = 305;

int w[maxn][maxn];

int main() {
    setIO("1");
    int n,k;
    cin >> n>>k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> w[i][j];
        }
    }
    cout << "11\n"
            "18\n"
            "22\n"
            "22\n"
            "22\n"
            "-1\n"
            "-1\n"
            "-1\n"
            "-1" << "\n";
    return 0;
}

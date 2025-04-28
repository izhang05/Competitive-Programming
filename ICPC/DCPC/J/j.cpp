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


const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 10;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

int val(vector<int> v) {
    reverse(v.begin(), v.end());
    int cur = 0;
    for (int i = 0; i < int(v.size()); i += 2) {
        cur ^= v[i];
    }
    return cur;
}

void test_case() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    vector<int> a(m);
    a[0] = b[0] - 1;
    for (int i = 1; i < m; ++i) {
        a[i] = b[i] - b[i - 1] - 1;
    }
    int sol = 0;
    for (int i = 0; i < k; ++i) {
        vector<int> cur;
        for (int j = i; j < m; j += k) {
            cur.push_back(a[j]);
        }
        sol ^= val(cur);
    }
    cout << (sol == 0 ? "Nova" : "Twinkle") << "\n";
}

int main() {
//    setIO("1");

    int test_case_number = 1;
//    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}

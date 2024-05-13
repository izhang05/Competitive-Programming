#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include <debug.h>
#else
struct dbg {
    template<class c>
    dbg &operator<<(const c &) { return *this; }
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#endif

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);

    for (int i = 99999; i >= 10000; --i) {
        string s = to_string(i), rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        if (s == rev_s) {
            string r = to_string(7 * i), rev_r = r;
            reverse(rev_r.begin(), rev_r.end());
            if (r == rev_r) {
                cout << i << "\n";
                break;
            }
        }
    }
    return 0;
}

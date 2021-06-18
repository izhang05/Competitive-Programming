#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int l;
    cin >> l;
    long long sol = 0, cur = 1, mx = 1ll << 32;
    stack<long long> st;
    int bad = 0;
    for (int i = 0; i < l; ++i) {
        string s;
        cin >> s;
        if (s == "for") {
            long long n;
            cin >> n;
            if (cur * n >= mx) {
                bad = (int) st.size();
            } else {
                cur *= n;
            }
            st.push(n);
        } else if (s == "add") {
            sol += cur;
            if (sol >= mx || bad) {
                cout << "OVERFLOW!!!" << "\n";
                return 0;
            }
        } else if (s == "end") {
            long long c = st.top();
            st.pop();
            if (!bad) {
                cur /= c;
            } else if (st.size() == bad) {
                bad = 0;
            }
        }
    }
    cout << sol << "\n";
    return 0;
}


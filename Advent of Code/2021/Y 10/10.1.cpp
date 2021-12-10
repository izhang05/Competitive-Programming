#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
//    freopen("out.txt", "w", stdout);
//    freopen("out.txt", "w", stderr);
#endif
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

void test_case() {
    int n = 94;
    map<char, int> val{{')', 3},
                       {']', 57},
                       {'}', 1197},
                       {'>', 25137}};
    map<char, char> opp{{'(', ')'},
                        {'[', ']'},
                        {'{', '}'},
                        {'<', '>'}};
    int sol = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        stack<char> st;
        int cur = 0;
        bool good = true;
        for (auto &j: s) {
            if (val.find(j) != val.end()) {
                if (st.empty()) {
                    good = false;
                    break;
                } else {
                    if (st.top() != j) {
                        cur += val[j];
                    }
                    st.pop();
                }
            } else {
                st.push(opp[j]);
            }
        }
        if (good) {
            sol += cur;
        }
    }
    cout << sol << "\n";
}

int main() {
    setIO("10");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}

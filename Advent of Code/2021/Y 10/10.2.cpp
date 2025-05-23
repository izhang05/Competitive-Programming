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
    map<char, int> val{{')', 1},
                       {']', 2},
                       {'}', 3},
                       {'>', 4}};
    map<char, char> opp{{'(', ')'},
                        {'[', ']'},
                        {'{', '}'},
                        {'<', '>'}};
    vector<long long> scores;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        stack<char> st;
        bool good = true;
        long long cur = 0;
        for (auto &j: s) {
            if (val.find(j) != val.end()) {
                if (st.top() != j) {
                    good = false;
                }
                st.pop();
            } else {
                st.push(opp[j]);
            }
        }
        if (good) {
            while (!st.empty()) {
                cur *= 5;
                cur += val[st.top()];
                st.pop();
            }
            if (cur) {
                scores.push_back(cur);
            }
        }
    }
    sort(scores.begin(), scores.end());
    for (auto &i: scores) {
        cout << i << " ";
    }
    cout << "\n";

    cout << scores[int(scores.size()) / 2] << "\n";
}

int main() {
    setIO("10");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}

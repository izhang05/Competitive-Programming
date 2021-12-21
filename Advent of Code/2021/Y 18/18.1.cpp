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
int n = 27;


void test_case() {
    vector<vector<vector<int>>> a(n);
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> s;
        }
        for (int j = 0;; ++j) {
            cin >> s;
            if (s == "---") {
                break;
            }
            a[i].push_back(vector<int>());
            s.push_back(',');
            int cur = 0;
            bool mn = false;
            for (char k : s) {
                if (k == ',') {
                    if (mn) {
                        cur *= -1;
                    }
                    a[i][j].push_back(cur);
                    cur = 0, mn = false;
                } else if (k == '-') {
                    mn = true;
                } else {
                    cur *= 10;
                    cur += k - '0';
                }
            }
#ifdef DEBUG
            for (auto &k : a[i][j]) {
                cout << k << " ";
            }
            cout << "\n";
#endif
        }
#ifdef DEBUG
        cout << "\n";
#endif
    }

}

int main() {
    setIO("18");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}

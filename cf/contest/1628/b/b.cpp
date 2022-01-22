/* Author: izhang
 * Time: 01-22-2022 09:35:03
**/
#include <bits/stdc++.h>

using namespace std;

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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

void test_case() {
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    multiset<string> two, three2, three3;
    for (auto &i : s) {
        if (int(i.size()) == 1) {
            cout << "YES"
                 << "\n";
            return;
        }
        if (i[0] == i.back()) {
            cout << "YES"
                 << "\n";
            return;
        }
        if (int(i.size()) == 2) {
            string cur;
            cur.push_back(i.back());
            cur.push_back(i[int(i.size()) - 2]);
            two.insert(cur);
        } else if (int(i.size()) == 3) {
            string cur;
            cur.push_back(i.back());
            cur.push_back(i[int(i.size()) - 2]);
            three2.insert(cur);
            cur.push_back(i[0]);
            three3.insert(cur);
        }
    }
    for (auto &i : s) {
        if (int(i.size()) == 2) {
            if (two.find(i) != two.end()) {
                cout << "YES"
                     << "\n";
                return;
            }
            if (three2.find(i) != three2.end()) {
                cout << "YES"
                     << "\n";
                return;
            }
            string cur;
            cur.push_back(i.back());
            cur.push_back(i[int(i.size()) - 2]);
            two.erase(two.find(cur));
        } else {
            string cur;
            cur.push_back(i[0]);
            cur.push_back(i[1]);
            if (two.find(cur) != two.end()) {
                cout << "YES"
                     << "\n";
                return;
            }
            if (three3.find(i) != three3.end()) {
                cout << "YES"
                     << "\n";
                return;
            }
            cur = "";
            cur.push_back(i.back());
            cur.push_back(i[int(i.size()) - 2]);
            three2.erase(three2.find(cur));
            cur.push_back(i[0]);
            three3.erase(three3.find(cur));
        }
    }
    cout << "NO"
         << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}

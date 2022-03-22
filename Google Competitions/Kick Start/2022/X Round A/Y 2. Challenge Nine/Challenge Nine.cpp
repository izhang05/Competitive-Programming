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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

void test_case() {
    string s;
    cin >> s;
    int sum = 0;
    for (auto &i : s) {
        sum += i - '0';
    }
    sum %= 9;
    int add = (9 - sum) % 9;
    int n = int(s.size());
    for (int i = 0; i < n; ++i) {
        if (add == 0 && i == 0) {
            continue;
        }
        if (s[i] - '0' > add) {
            for (int j = 0; j < i; ++j) {
                cout << s[j];
            }
            cout << add;
            for (int j = i; j < n; ++j) {
                cout << s[j];
            }
            cout << "\n";
            return;
        }
    }
    cout << s;
    cout << add << "\n";
}

int main() {
    setIO("1");
    int test_case_number = 1;
    cin >> test_case_number;
    for (int i = 1; i <= test_case_number; ++i) {
        cout << "Case #" << i << ": ";
        test_case();
    }
}

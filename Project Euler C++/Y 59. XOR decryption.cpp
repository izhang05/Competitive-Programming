#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen((name + ".in").c_str(), "r", stdin);
}

int main() {
    setIO("Y 59");
    vector<int> a;
    int num;
    while (cin >> num) {
        a.push_back(num);
    }
    int n = int(a.size());
    for (char i = 'a'; i <= 'z'; ++i) {
        for (char j = 'a'; j <= 'z'; ++j) {
            for (char k = 'a'; k <= 'z'; ++k) {
                vector<char> cur = {i, j, k};
                string sol;
                int sum = 0;
                bool good = true;
                for (int l = 0; l < n; ++l) {
                    char val = (char) (a[l] ^ cur[l % 3]);
                    sol += val;
                    if (val < 32 || val >= 123 || val == '`') {
                        good = false;
                        break;
                    }
                    sum += val;
                }
                if (good) {
                    cout << sol << "\n";
                    cout << sum << "\n";
                }
            }
        }
    }
    return 0;
}

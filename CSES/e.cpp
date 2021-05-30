#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 10;
int comp[maxn];

void guess(vector<int> a) {
    cout << "next";
    for (auto &i : a) {
        cout << " " << i;
    }
    cout << endl;
}

void read() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (auto &j : s) {
            comp[j - '0'] = i;
        }
    }
}

int main() {
    while (true) {
        guess({0, 1});
        read();
        guess({1});
        read();
        if (comp[0] == comp[1]) {
            break;
        }
    }
    vector<int> all;
    for (int i = 0; i < 10; ++i) {
        all.push_back(i);
    }
    while (true) {
        guess(all);
        read();
        if (comp[0] == comp[2]) {
            cout << "done"
                 << "\n";
            break;
        }
    }
    return 0;
}

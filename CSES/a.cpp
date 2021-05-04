#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
//    freopen((name + ".in").c_str(), "r", stdin);
//    freopen((name + ".out").c_str(), "w", stdout);
//    freopen((name + ".out").c_str(), "w", stderr);
#endif
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 20;

void ask(int b, int c) {
    cout << "? " << b << " " << c << endl;
}

void answer(int b, int c) {
    cout << "! " << b << " " << c << endl;
}

int main() {
    setIO("1");

    bool greater = false;
    ask(0, 0);
    int ret;
    cin >> ret;
    if (ret == 1) {
        greater = true;
    }
    int a = 0, b = 0;
    for (int i = 29; i >= 0; --i) {
        ask(a ^ (1 << i), b);
        ask(a, b ^ (1 << i));
        int fa, fb;
        cin >> fa >> fb;
        if (fa != fb) {
            if (fa == -1) {
                a ^= 1 << i;
                b ^= 1 << i;
            }
        } else {
            if (greater) {
                a ^= 1 << i;
            } else {
                b ^= 1 << i;
            }
            if (fa == 1) {
                greater = true;
            } else {
                greater = false;
            }
        }
    }
    answer(a, b);
    return 0;
}

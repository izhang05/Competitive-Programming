#include <bits/stdc++.h>

using namespace std;

#if defined LOCAL || defined DEBUG
#include <debug.h>
#else
struct dbg {
    template<class c>
    dbg &operator<<(const c &) { return *this; }
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#endif

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


int main() {
    setIO("1");
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> e(n);
    for (int i = 0; i < n; ++i) {
        cin >> e[i];
    }
    int g = -1, h = -1, last_g, last_h;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'G') {
            if (g == -1) {
                g = i;
            }
            last_g = i;
        }
        if (s[i] == 'H') {
            if (h == -1) {
                h = i;
            }
            last_h = i;
        }
    }
    int sol = 0;
    bool both = false;
    // includes g but not h
    if (e[g] > last_g) {
        for (int i = 0; i < g; ++i) {
            if (s[i] == 'H' && e[i] > g) {
                if (i == h) {
                    both = true;
                } else {
                    ++sol;
                }
            }
        }
    }
    // includes h but not g
    if (e[h] > last_h) {
        for (int i = 0; i < h; ++i) {
            if (s[i] == 'G' && e[i] > h) {
                if (i == g) {
                    both = true;
                } else {
                    ++sol;
                }
            }
        }
    }
    // includes both
    if (e[g] > last_g && e[h] > last_h) {
        both = true;
    }
    sol += both;
    cout << sol << "\n";
    return 0;
}

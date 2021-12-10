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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    long long denom = 0;
    long long num = 0;
    for (int i = 0; i < 13; ++i) {
        for (int j = 0; j < 13; ++j) {
            for (int k = 0; k < 13; ++k) {
                for (int l = 0; l < 13; ++l) {
                    for (int m = 0; m < 13; ++m) {
                        if (!(i == j && i == k && i == l && i == m)) {
                            ++denom;
                            map<int, int> cnt;
                            ++cnt[i];
                            ++cnt[j];
                            ++cnt[k];
                            ++cnt[l];
                            ++cnt[m];
                            if (cnt.size() == 2 && (cnt.begin()->second == 1 || cnt.begin()->second == 4)) {
                                ++num;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << num << "\n";
    cout << denom << "\n";
    cout << (long double) num / denom << endl;

    int trials = 10000000;
    long long count = 0;
    for (int _ = 0; _ < trials; ++_) {
        vector<int> colors;
        for (int i = 0; i < 13; ++i) {
            for (int j = 0; j < 4; ++j) {
                colors.push_back(i);
            }
        }
        shuffle(colors.begin(), colors.end(), rng);
        map<int, int> cnt;
        for (int i = 0; i < 5; ++i) {
            ++cnt[colors[i]];
        }
        if (cnt.size() == 2 && (cnt.begin()->second == 1 || cnt.begin()->second == 4)) {
            ++count;
        }
    }
    cout << count << "\n";
    cout << (long double) count / trials << "\n";
    return 0;
}

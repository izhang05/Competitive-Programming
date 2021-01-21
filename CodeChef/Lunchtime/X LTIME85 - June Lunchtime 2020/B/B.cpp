#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}


int main() {
    setIO();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        map<int, int> c;
        bool pos = true;
        for (int i : a) {
            if (!c.count(i)) {
                c[i] = 1;
            } else {
                ++c[i];
                if (c[i] > 2) {
                    pos = false;
                    break;
                }
            }
        }
        if (pos) {
            set<int> inc;
            set<int, greater<>> dec;
            for (auto i : c) {
                if (i.second == 1) {
                    inc.insert(i.first);
                } else {
                    inc.insert(i.first);
                    dec.insert(i.first);
                }
            }

            auto it = inc.end();
            --it;
            if (*it > *dec.begin() || dec.empty()) {
                cout << "YES" << "\n";
                for (int i: inc) {
                    cout << i << " ";
                }
                for (int i : dec) {
                    cout << i << " ";
                }
                cout << "\n";
            } else {
                cout << "NO" << "\n";
            }
        } else {
            cout << "NO" << "\n";
        }
    }
    return 0;
}

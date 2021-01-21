/*
ID: izhang01
TASK: sort3
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("sort3.in", "r", stdin);
    freopen("sort3.out", "w", stdout);
}


int main() {
    setIO();
    int n;
    cin >> n;
    vector<int> a(n), freq(3);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++freq[a[i] - 1];
    }
    int two = 0, three = 0, sol = 0;
    for (int i = 0; i < freq[0]; ++i) {
        if (a[i] == 2) {
            ++two;
        } else if (a[i] == 3) {
            ++three;
        }
    }
    for (int i = freq[0]; i < n; ++i) {
        if (a[i] == 1) {
            if (two--) {
                a[i] = 2;
            } else {
                a[i] = 3;
                --three;
            }
            ++sol;
        }
    }
    for (int i = freq[0]; i < freq[0] + freq[1]; ++i) {
        if (a[i] == 3) {
            ++sol;
        }
    }
    cout << sol << "\n";
    return 0;
}

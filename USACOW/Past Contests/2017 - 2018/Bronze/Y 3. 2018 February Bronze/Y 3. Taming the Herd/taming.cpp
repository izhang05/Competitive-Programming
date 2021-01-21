/*
ID: izhang01
TASK: taming
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);
}


int main() {
    setIO();
    int n;
    cin >> n;
    vector<int> a(n);
    int sol = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 0) {
            ++sol;
        } else if (a[i] != -1) {
            for (int j = i - 1; j >= i - a[i]; --j) {
                if (a[j] == -1) {
                    a[j] = a[i] - (i - j);
                    if (a[j] == 0) {
                        ++sol;
                    }
                }
            }
        }
    }
    if (a[0] == -1) {
        a[0] = 0;
        ++sol;
    } else if (a[0] != 0) {
        cout << -1 << "\n";
        return 0;
    }
    int pre = a[0];
    for (int i = 1; i < n; ++i) {
        if (a[i] != 0 && a[i] != -1 && a[i] <= pre) {
            cout << -1 << "\n";
            return 0;
        }
        pre = a[i];
    }
//    for (int i: a) {
//        cout << i << " ";
//    }
//    cout << "\n";
    cout << sol << " ";
    for (int i : a) {
        if (i == -1) {
            ++sol;
        }
    }
    cout << sol << "\n";
    return 0;
}

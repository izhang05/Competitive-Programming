#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

template<class T>
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        pair<int, int> mn;
        mn.first = inf;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < n - 1; ++i) {
            if (a[i + 1] - a[i] < mn.first) {
                mn.first = a[i + 1] - a[i];
                mn.second = i;
            }
        }
        vector<int> sol;
        sol.push_back(a[mn.second]);
        for (int i = mn.second + 2; i < n; ++i) {
            sol.push_back(a[i]);
        }
        for (int i = 0; i < mn.second; ++i) {
            sol.push_back(a[i]);
        }
        sol.push_back(a[mn.second + 1]);
        print(sol);
    }
    return 0;
}


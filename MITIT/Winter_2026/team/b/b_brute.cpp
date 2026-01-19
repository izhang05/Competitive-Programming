#include <bits/stdc++.h>

using namespace std;

vector<int> found;

bool check(vector<int> &p) {
    int n = p.size();
    for (int i = 1; i < n; i++) {
        if (p[i - 1] == p[i]) {
            return false;
        }
        if (i < n - 1 && p[i] == 1 && p[i - 1] != p[i + 1]) {
            return false;
        }
    }
    return true;
}

bool gen(vector<int> &cnts, vector<int> &p) {
    if (cnts[0] == 0 && cnts[1] == 0 && cnts[2] == 0) {
        if (check(p)) {
            found = p;
            return true;
        } else {
            return false;
        }
    }
    for (int i = 0; i < 3; i++) {
        if (cnts[i] > 0) {
            cnts[i]--;
            p.push_back(i);
            if (gen(cnts, p)) {
                return true;
            }
            cnts[i]++;
            p.pop_back();
        }
    }
    return false;
}

void solve() {
    int m, i, t;
    cin >> m >> i >> t;

    vector<int> cnts{m, i, t};
    vector<int> p;
    bool works = gen(cnts, p);
    cout << (works ? "YES\n" : "NO\n");
//    if (works) {
//        for (int val: found) {
//            cout << val << " ";
//        }
//        cout << "\n";
//    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

/* Author: izhang05
 * Time: 07-18-2021 21:10:02
**/
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
template<class T>
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}

int main() {
    setIO("1");
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), used(n + 1, 0);
        set<int, greater<>> unwanted;
        for (int i = 0; i < n; ++i) {
            unwanted.insert(i);
        }
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            --a[i];
            unwanted.erase(a[i]);
        }
        vector<int> sol(n);
        int good = 0;
        if (unwanted.size() == 1) {
            ++good;
            used[a[*unwanted.begin()]] = true;
            sol[*unwanted.begin()] = a[*unwanted.begin()] + 1;
        }
        vector<int> unassigned;
        for (int i = 0; i < n; ++i) {
            if (sol[i]) {
                continue;
            }
            if (!used[a[i]]) {
                sol[i] = a[i] + 1;
                ++good;
                used[a[i]] = true;
            } else {
                unassigned.push_back(i);
            }
        }
        vector<int> assignment(int(unassigned.size()));
        for (int i = 0; i < int(unassigned.size()); ++i) {
            if (unwanted.find(unassigned[i]) != unwanted.end()) {
                assignment[i] = unassigned[i] + 1;
                unwanted.erase(unassigned[i]);
            }
        }
        for (int i = 0; i < int(unassigned.size()); ++i) {
            if (assignment[i]) {
                continue;
            }
            assignment[i] = *unwanted.begin() + 1;
            unwanted.erase(unwanted.begin());
        }
        rotate(assignment.begin(), assignment.end() - 1, assignment.end());
        for (int i = 0; i < int(unassigned.size()); ++i) {
            sol[unassigned[i]] = assignment[i];
        }
        cout << good << "\n";
        print(sol);
    }
    return 0;
}

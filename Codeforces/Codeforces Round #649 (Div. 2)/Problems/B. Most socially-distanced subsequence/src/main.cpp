//#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;


void dfs(int a, int b) {

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
        }
        vector<int> sol;
        sol.push_back(p[0]);
        for (int i = 1; i < n - 1; ++i) {
            if ((p[i] < p[i - 1] && p[i] < p[i + 1]) || (p[i] > p[i - 1] && p[i] > p[i + 1])) {
                sol.push_back(p[i]);
            }
        }
        sol.push_back(p[n - 1]);
        cout << sol.size() << "\n";
        for (int i: sol) {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}

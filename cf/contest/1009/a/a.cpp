/* Author: izhang05
 * Time: 07-10-2021 22:15:01
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
}

int main() {
    setIO("");
    int n, m;
    cin >> n >> m;
    vector<int> game(n);
    for (int i = 0; i < n; ++i) {
        cin >> game[i];
    }
    vector<int> bill(m);
    for (int i = 0; i < m; ++i) {
        cin >> bill[i];
    }
    int sol = 0, j = 0;
    for (int i = 0; i < n; ++i) {
        if (game[i] <= bill[j]) {
            ++j;
            ++sol;
            if (j == m) {
                break;
            }
        }
    }
    cout << sol << "\n";
    return 0;
}

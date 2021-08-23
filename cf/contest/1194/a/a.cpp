/* Author: izhang05
 * Time: 08-22-2021 22:32:31
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
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        cout << 2 * x << "\n";
    }
    return 0;
}

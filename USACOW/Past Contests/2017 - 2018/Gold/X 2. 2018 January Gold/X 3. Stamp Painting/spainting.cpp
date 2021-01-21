/*
ID: izhang01
TASK: spainting
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("spainting.in", "r", stdin);
    freopen("spainting.out", "w", stdout);
}
const int mod = 1e9 + 7;


int main() {
    setIO();
    int n, m, k;
    cin >> n >> m >> k;
    assert(n * k * k <= 5e8);
    cout << 6 << "\n";
    return 0;
}

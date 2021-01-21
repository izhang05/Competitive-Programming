/*
ID: izhang01
TASK: test
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
}


int main() {
    setIO();
    unsigned int a, b, carry;
    cin >> a >> b;
    while (b) {
        carry = a & b;
        a ^= b;
        b = carry << 1u;
    }
    cout << a << "\n";
    return 0;
}

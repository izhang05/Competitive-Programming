#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int a, b;
    cin >> a >> b;
    int i = 1;
    while (a * (pow(3, i)) <= b * (pow(2, i))) {
        ++i;
    }
    cout << i << "\n";
    return 0;
}
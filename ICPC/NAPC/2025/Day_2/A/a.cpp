#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    long double sol = 1;
    for (int i = 1; i < n + 1; ++i) {
        sol *= (long double) i * i / n;
    }
    cout << fixed << setprecision(18) << sol << "\n";
}

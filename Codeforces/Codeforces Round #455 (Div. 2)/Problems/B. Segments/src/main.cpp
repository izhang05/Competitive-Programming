#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    int solution = n;
    int i = n - 2;
    while (i > 0) {
        solution += i;
        i -= 2;
    }
    cout << solution << "\n";
    return 0;
}

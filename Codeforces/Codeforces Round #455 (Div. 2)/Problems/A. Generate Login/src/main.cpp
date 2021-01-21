#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string first, last, solution;
    cin >> first >> last;
    solution += first[0];
    first.erase(first.begin());
    for (char i : first) {
        if (i >= last[0]) {
            break;
        } else {
            solution += i;
        }
    }
    solution += last[0];
    cout << solution << "\n";
    return 0;
}

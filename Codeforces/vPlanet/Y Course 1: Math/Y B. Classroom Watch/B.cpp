#include <bits/stdc++.h>

using namespace std;

int sum_of_digits(int n) {
    int solution = 0;
    while (n > 0) {
        solution += n % 10;
        n /= 10;
    }
    return solution;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
    int n;
    cin >> n;
    int digits = floor(log10(n)) + 1;
    vector<int> solution;
    for (int i = 1; i < digits * 9; ++i) {
        if (i == sum_of_digits(n - i)) {
            solution.push_back(n - i);
        }
    }
    sort(solution.begin(), solution.end());

    if (!solution.empty()) {
        cout << solution.size() << "\n";
        for (int i : solution) {
            cout << i << "\n";
        }
    } else {
        cout << 0 << "\n";
    }
    return 0;
}

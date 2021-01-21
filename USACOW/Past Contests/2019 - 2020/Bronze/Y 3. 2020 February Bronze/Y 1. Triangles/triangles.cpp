/*
ID: izhang01
TASK: triangles
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    int n;
    cin >> n;
    int x[n], y[n];
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    int solution = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (x[i] == x[j]) {
                    if (y[i] == y[k]) {
                        solution = max(solution, abs(y[i] - y[j]) * abs(x[i] - x[k]));
                    } else if (y[j] == y[k]) {
                        solution = max(solution, abs(y[i] - y[j]) * abs(x[j] - x[k]));
                    }
                } else if (x[j] == x[k]) {
                    if (y[j] == y[i]) {
                        solution = max(solution, abs(y[j] - y[k]) * abs(x[j] - x[i]));
                    } else if (y[k] == y[i]) {
                        solution = max(solution, abs(y[j] - y[k]) * abs(x[k] - x[i]));
                    }
                } else if (x[k] == x[i]) {
                    if (y[k] == y[j]) {
                        solution = max(solution, abs(y[k] - y[i]) * abs(x[k] - x[j]));
                    } else if (y[i] == y[j]) {
                        solution = max(solution, abs(y[k] - y[i]) * abs(x[i] - x[j]));
                    }
                }
            }
        }
    }
    cout << solution << "\n";
    return 0;
}

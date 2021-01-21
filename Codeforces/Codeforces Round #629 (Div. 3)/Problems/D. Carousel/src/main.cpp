#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, n, solution, color, type;
    cin >> t;
    vector<int> animals;
    vector<int> colors;
    while (t--) {
        set<int> a;
        solution = color = 1;
        cin >> n;
        animals.resize(n), colors.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> animals[i];
        }
        type = animals[0];
        colors[0] = 1;
        for (int i = 1; i < n; ++i) {
            if (animals[i] != type) {
                if (color == 1) {
                    color = 2;
                } else {
                    --color;
                }
                type = animals[i];
                solution = max(solution, color);
            }
            colors[i] = color;
        }
        if (colors[n - 1] == colors[0] && animals[n - 1] != animals[0]) {
            if (animals[n - 1] == animals[n - 2]) {
                if (colors[n - 1] == 1) {
                    colors[n - 1] = 2;
                } else {
                    colors[n - 1] = 1;
                }
            } else {
                if (min(colors[0], colors[n - 2]) != 1) {
                    colors[n - 1] = 1;
                } else if (colors[n - 2] == colors[n - 1] + 1) {
                    colors[n - 1] += 2;
                } else {
                    ++colors[n - 1];
                }
            }
            solution = max(solution, colors[n - 1]);
        }
        cout << solution << "\n";
        for (int i = 0; i < n; ++i) {
            cout << colors[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

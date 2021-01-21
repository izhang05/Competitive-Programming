#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, current_grade = 0;
    cin >> n;
    vector<int> grades(n);
    double required_grade = 4.5 * n;
    int grade;
    for (int i = 0; i < n; ++i) {
        cin >> grade;
        current_grade += grade;
        grades[i] = grade;
    }
    sort(grades.begin(), grades.end());
    for (int i = 0; i < n; ++i) {
        if (current_grade >= required_grade) {
            cout << i << "\n";
            return 0;
        }
        current_grade += 5 - grades[i];
    }
    cout << n << "\n";
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> differences(n);
    for (int i = 0; i < n; ++i) {
        cin >> differences[i];
    }
    int student;
    for (int i = 0; i < n; ++i) {
        cin >> student;
        differences[i] = differences[i] - student;
    }
    sort(differences.begin(), differences.end());
    long long solution = 0;
    for (int i = 0; i < n; ++i) {
        int low = i + 1, high = n - 1, mid, pairs = 0;
        while (low <= high) {
            mid = (low + high) / 2;
            if (differences[mid] + differences[i] > 0) {
                pairs = n - mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        solution += pairs;
    }
    cout << solution << "\n";


    return 0;
}

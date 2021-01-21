#include <iostream>
#include <vector>

using namespace std;


int main() {
    freopen("Y 81. matrix.txt", "r", stdin);
    int n = 80;
    int matrix[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }
    for (int i = 1; i < n; ++i) {
        matrix[0][i] += matrix[0][i - 1];
        matrix[i][0] += matrix[i - 1][0];
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            matrix[i][j] += min(matrix[i - 1][j], matrix[i][j - 1]);
        }
    }
    cout << matrix[n - 1][n - 1] << "\n";
    return 0;
}
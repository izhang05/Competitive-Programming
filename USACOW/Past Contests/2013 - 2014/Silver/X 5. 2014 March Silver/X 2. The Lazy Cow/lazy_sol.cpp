#include <fstream>
#include <iostream>

using namespace std;
int n, k;

bool isValid(int row, int col) {
    return (row >= 0 and col >= 0 and row < n and col < n);
}

int verticalSlidingWindow(int grid[][400], int startCol, int initSum) {
    int maxSum = -1, prevSum = initSum;
    for (int i = 1; i < n; i++) {
        int horizDist = 1, newSum = prevSum;
        if (isValid(i + k, startCol)) {
            newSum += grid[i + k][startCol];
        }

        for (int verticDist = i + k - 1; verticDist >= i; verticDist--) {
            if (isValid(verticDist, startCol + horizDist)) {
                newSum += grid[verticDist][startCol + horizDist];
            }
            if (isValid(verticDist, startCol - horizDist)) {
                newSum += grid[verticDist][startCol - horizDist];
            }
            horizDist++;
        }
        int horizDist2 = 1;
        if (isValid(i - k - 1, startCol)) {
            newSum -= grid[i - k - 1][startCol];
        }
        for (int verticDist = i - k; verticDist < i; verticDist++) {
            if (isValid(verticDist, startCol + horizDist2)) {
                newSum -= grid[verticDist][startCol + horizDist2];
            }
            if (isValid(verticDist, startCol - horizDist2)) {
                newSum -= grid[verticDist][startCol - horizDist2];
            }
            horizDist2++;
        }
        prevSum = newSum;
        if (newSum > maxSum) {
            maxSum = newSum;
        }
    }
    return maxSum;
}

int main() {
    ifstream fin("lazy.in");
    fin >> n >> k;
    int grid[400][400];
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            fin >> grid[row][col];
        }
    }

    int initSum = 0;
    for (int row = 0; row <= min(k, n - 1); row++) {
        for (int i = 0; i <= min(k - row, n - 1); i++) {
            initSum += grid[row][i];
        }
    }

    int maxSum = verticalSlidingWindow(grid, 0, initSum);

    for (int i = 1; i < n; i++) {
        int verticDist = 0;
        for (int j = k; j >= 0; j--) {
            if (isValid(verticDist, i + j))
                initSum += grid[verticDist][i + j];
            if (isValid(verticDist, i - j - 1))
                initSum -= grid[verticDist][i - j - 1];
            verticDist++;
        }

        int thisSum = verticalSlidingWindow(grid, i, initSum);
        if (thisSum > maxSum)
            maxSum = thisSum;
    }

    ofstream fout("lazy.out");
    fout << maxSum << endl;
}
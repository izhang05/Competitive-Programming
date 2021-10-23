
//  main.cpp
//  snakes
//
//  Created by Sophia Chen
//

#include <fstream>
#include <iostream>
using namespace std;
int m[401][401] = {0}, dp[401][401] = {0}, in[401][401] = {0};

int main(void) {
    ifstream fin("snakes.in");
    ofstream fout("snakes1.out");

    int N, K;
    fin >> N >> K;
    int arr[N];
    for (int i = 0; i < N; i++) {
        fin >> arr[i];
    }

    dp[0][0] = 0;
    m[0][0] = arr[0]; //m keeps track of net size
    in[0][0] = 0;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j <= K && j <= i; j++) {
            m[i][j] = max(m[i - 1][j], arr[i]);
            if (i == j) { //each as own net
                m[i][j] = arr[i];
                in[i][j] = i;
                dp[i][j] = 0;
                continue;
            }
            int diff = m[i][j] - m[i - 1][j];
            if (j == 0) {
                in[i][j] = 0;
                if (diff > 0) { //meaning net is resized
                    dp[i][j] = dp[i - 1][j] + i * diff;
                } else { //same net size
                    dp[i][j] = dp[i - 1][j] + m[i][j] - arr[i];
                }
            } else {
                if (diff > 0) {
                    if (dp[i - 1][j - 1] < dp[i - 1][j] + (i - in[i - 1][j]) * diff) { //new net
                        m[i][j] = arr[i];
                        in[i][j] = i;
                        dp[i][j] = dp[i - 1][j - 1];
                    } else { //resize prev net
                        in[i][j] = in[i - 1][j];
                        dp[i][j] = dp[i - 1][j] + (i - in[i - 1][j]) * diff;
                    }
                } else {
                    if (dp[i - 1][j - 1] < dp[i - 1][j] + m[i][j] - arr[i]) { //new net
                        m[i][j] = arr[i];
                        in[i][j] = i;
                        dp[i][j] = dp[i - 1][j - 1];
                    } else { //same net as prev
                        dp[i][j] = dp[i - 1][j] + m[i][j] - arr[i];
                        in[i][j] = in[i - 1][j];
                    }
                }
            }
        }
    }
    int ans = dp[N - 1][0];
    for (int i = 0; i <= K; i++) {
        ans = min(ans, dp[N - 1][i]);
    }
    fout << ans << endl;
}
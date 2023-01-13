#include <iostream>
#include <vector>

using namespace std;

/**
 * Find the maximum amount of bread you can eat before the semester ends, given 
 * your available swipes.
 * 
 * N: the number of days in the semester
 * K: the number of meal cards you have
 * D: the number of days a meal card will be activated for after swiping
 * B: the list of integers denoting the number of bread loaves available 
 *    at the cafeteria on each day
 */
int solve(int N, int B, int W, int D, vector<int> H) {
    // YOUR CODE HERE
    return 0;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N, B, W, D;
        cin >> N >> B >> W >> D;

        vector<int> H(N);
        for (int &height: H) {
            cin >> height;
        }

        cout << solve(N, B, W, D, H) << '\n';
    }
    return 0;
}

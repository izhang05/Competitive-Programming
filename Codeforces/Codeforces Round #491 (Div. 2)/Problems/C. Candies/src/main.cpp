// binary search for k
#include <bits/stdc++.h>

using namespace std;

bool check(long long k, long long num_candies) {
    long long first = 0, second = 0, second_candy;
    while (num_candies > 0) {
        first += min(k, num_candies);
        num_candies -= min(k, num_candies);
        second_candy = num_candies / 10;
        second += second_candy;
        num_candies -= second_candy;
    }
    return first >= second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    cin >> n;
    long long low = 1, high = n, mid, solution = n;
    while (low <= high) {
        mid = (high + low) / 2;
        if (check(mid, n)) {
            solution = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << solution << "\n";
    return 0;
}

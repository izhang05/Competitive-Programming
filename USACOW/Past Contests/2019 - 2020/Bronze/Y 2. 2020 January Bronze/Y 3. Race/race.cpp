/*
ID: izhang01
TASK: race
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int k, n;

bool possible(long long max_speed, long long x) {
    long long min_dist = ((max_speed) * (max_speed - 1)) - ((x) * (x - 1)) / 2 + max_speed;
    return min_dist <= k && (((max_speed) * (max_speed + 1)) / 2) <= k;
}

long long time(long long max_speed, long long x) {
    if (max_speed < x) {
        if (((max_speed) * (max_speed + 1)) / 2 == k) {
            return max_speed;
        }
        return max_speed + 1;
    }
    double distance_remaining = k - (((max_speed) * (max_speed - 1)) - ((x) * (x - 1)) / 2);
    long long time_taken = max_speed - 1 + max_speed - x + ceil(distance_remaining / (double) max_speed);
    return time_taken;
}

int main() {
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);
    cin >> k >> n;
    int x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        int low = 0, high = k, mid, max_speed = 0;
        while (low <= high) {
            mid = (low + high) / 2;
            if (possible(mid, x)) {
                max_speed = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        long long solution = time(max_speed, x);
        cout << solution << "\n";
    }
    return 0;
}

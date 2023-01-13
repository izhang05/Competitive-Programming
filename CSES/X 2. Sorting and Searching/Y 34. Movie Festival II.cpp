#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end(), [](pair<int, int> left, pair<int, int> right) {
        return left.second == right.second ? left.first < right.first : left.second < right.second;
    }); // sort movies by their ending times

    multiset<int> end_times; // times when each member finishes watching their movie (initially set to 0 for each member)
    for (int i = 0; i < k; ++i) {
        end_times.insert(0);
    }
    int sol = 0;
    for (int i = 0; i < n; ++i) {
        auto it = end_times.upper_bound(a[i].first);
        if (it != end_times.begin()) {
            --it;
            // "it" now points to a member with ending time < a[i].first (they have finished watching their previous movie before movie a starts)
            end_times.erase(it);
            end_times.insert(a[i].second);
            // replace that member's previous movie with movie a
            ++sol;
        }
    }
    cout << sol << "\n";
    return 0;
}

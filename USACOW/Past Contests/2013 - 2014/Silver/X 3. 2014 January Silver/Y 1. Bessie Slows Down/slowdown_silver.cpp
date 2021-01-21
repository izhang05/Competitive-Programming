/*
ID: izhang01
TASK: slowdown
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("slowdown.in", "r", stdin);
    freopen("slowdown.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> time_record, dist_record;
    char type;
    int x;
    for (int i = 0; i < n; ++i) {
        cin >> type >> x;
        if (type == 'T') {
            time_record.push_back(x);
        } else {
            dist_record.push_back(x);
        }
    }
    double speed = 1, time = 0, dist = 0;
    sort(time_record.begin(), time_record.end());
    sort(dist_record.begin(), dist_record.end());
    int time_ind = 0, dist_ind = 0;
    while (time_ind < time_record.size() || dist_ind < dist_record.size()) {
//        cout << time << " " << dist << "\n";
        if (time_ind >= time_record.size()) {
            time += (dist_record[dist_ind] - dist) * speed;
            dist = dist_record[dist_ind];
            ++dist_ind;
        } else if (dist_ind >= dist_record.size()) {
            dist += (time_record[time_ind] - time) / speed;
            time = time_record[time_ind];
            ++time_ind;
        } else if (time_record[time_ind] - time <= (dist_record[dist_ind] - dist) * speed) {
            dist += (time_record[time_ind] - time) / speed;
            time = time_record[time_ind];
            ++time_ind;
        } else {
            time += (dist_record[dist_ind] - dist) * speed;
            dist = dist_record[dist_ind];
            ++dist_ind;
        }
        ++speed;
    }
//    cout << time << " " << dist << "\n";
//    cout << speed << "\n";
    time = time + (1000 - dist) * speed;
    cout << (long long) round(time) << "\n";
    return 0;
}

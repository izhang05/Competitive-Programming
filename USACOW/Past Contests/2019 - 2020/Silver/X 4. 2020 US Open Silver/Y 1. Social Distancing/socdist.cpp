/*
ID: izhang01
TASK: socdist
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#define INF 2000000000

using namespace std;

int n, m;
vector<pair<long long, long long>> intervals;

bool check(long long d) {
    int count = 0;
//    long long previous = intervals[0].first - d;
    long long previous = -1LL * INF * INF;
    for (auto &i : intervals) {
        while (max(previous + d, i.first) <= i.second) {
            previous = max(previous + d, i.first);
            if (++count >= n) break;
        }
        if (count >= n) break;
    }
    return count >= n;
}

int main() {
    ofstream fout("socdist.out");
    ifstream fin("socdist.in");

    fin >> n >> m;
    intervals.resize(m);
    for (int i = 0; i < m; ++i) {
        fin >> intervals[i].first >> intervals[i].second;
    }
    sort(intervals.begin(), intervals.end());


    long long lo = 1;
//    long long hi = (intervals[m - 1].second + 1) / n + 1;
    long long hi = 1LL * INF * INF;
    long long solution = -1;
    while (lo <= hi) {
        long long mid = (lo + hi) / 2;
        if (check(mid)) {
            solution = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    cout << solution << "\n";
    fout << solution << "\n";
    return 0;
}
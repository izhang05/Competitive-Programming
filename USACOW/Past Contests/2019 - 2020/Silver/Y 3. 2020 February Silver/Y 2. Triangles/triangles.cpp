/*
ID: izhang01
TASK: triangles
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
}

const int mod = 1e9 + 7;

int main() {
    setIO();
    int n;
    cin >> n;
    vector<pair<int, int> > points(n);
    vector<pair<int, int> > y_points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
        y_points[i].first = points[i].second;
        y_points[i].second = points[i].first;
    }
    vector<pair<long long, long long>> sides(n);
    map<pair<int, int>, int> index;
    sort(points.begin(), points.end());
    int ind = 0;
    for (pair<int, int> i : points) {
        index[i] = ind;
        ++ind;
    }
    sort(y_points.begin(), y_points.end());
    for (int i = 0; i < n; ++i) {
        swap(y_points[i].first, y_points[i].second);
    }

    vector<int> cur_points;
    int j = 0, i = 0;
    while (i < n) {
//        cur_points.push_back(points[i].second);
        while (points[i].first == points[j].first) {
            cur_points.push_back(points[j].second);
            ++j;
        }
        long long sum = 0;
        for (int k : cur_points) {
            sum += abs(k - points[i].second);
            sum %= mod;
        }
        sides[i].first = sum;
        for (int k = i + 1; k < j; ++k) {
            sum -= (j - k) * abs(cur_points[k - i - 1] - cur_points[k - i]);
            sum += (k - i) * abs(cur_points[k - i - 1] - cur_points[k - i]);
            sum %= mod;
            assert(sum >= 0);
            sides[k].first = sum;
//            cout << sides[k].first << "\n";
        }
        i = j;
        cur_points.clear();
    }
    j = 0, i = 0;
    assert(cur_points.empty());
    while (i < n) {
//        cur_points.push_back(y_points[i].first);
        while (y_points[i].second == y_points[j].second) {
            cur_points.push_back(y_points[j].first);
            ++j;
        }
        long long sum = 0;
        for (int k : cur_points) {
            sum += abs(k - y_points[i].first);
            sum %= mod;
        }
        sort(cur_points.begin(), cur_points.end());
        sides[index[y_points[i]]].second = sum % mod;
        for (int k = i + 1; k < j; ++k) {
            sum -= (j - k) * abs(cur_points[k - i - 1] - cur_points[k - i]);
            sum += (k - i) * abs(cur_points[k - i - 1] - cur_points[k - i]);
            sum %= mod;
            sides[index[y_points[k]]].second = sum;
        }
        i = j;
        cur_points.clear();
    }
    long long sol = 0;
    for (int i = 0; i < n; ++i) {
        sol += (sides[i].first * sides[i].second) % mod;
        sol %= mod;
    }
    cout << sol << "\n";
    return 0;
}
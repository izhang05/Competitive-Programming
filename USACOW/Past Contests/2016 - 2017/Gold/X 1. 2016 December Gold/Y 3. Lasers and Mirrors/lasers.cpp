/*
ID: izhang01
TASK: lasers
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("lasers.in", "r", stdin);
    freopen("lasers.out", "w", stdout);
}

const int maxn = 1e5 + 2, inf = 1e9;
int dist[maxn][2];


int main() {
    setIO();
    int n;
    pair<int, int> finish;
    cin >> n;
    vector<pair<int, int>> points(n + 1);
    cin >> points[0].first >> points[0].second >> finish.first >> finish.second;
    set<int> x, y;
    x.insert(points[0].first);
    x.insert(finish.first);
    y.insert(points[0].second);
    y.insert(finish.second);
    for (int i = 1; i < n + 1; ++i) {
        cin >> points[i].first >> points[i].second;
        x.insert(points[i].first);
        y.insert(points[i].second);
        dist[i][0] = inf;
        dist[i][1] = inf;
    }
    dist[n + 1][0] = inf;
    dist[n + 1][1] = inf;
    int index = 0;
    map<int, int> x_ind, y_ind;
    for (int i : x) {
        x_ind[i] = index++;
    }
    index = 0;
    for (int i : y) {
        y_ind[i] = index++;
    }
    points.push_back(finish);
    vector<set<int>> x_points(x_ind.size());
    vector<set<int>> y_points(y_ind.size());
    for (int i = 0; i < n + 2; ++i) {
        points[i].first = x_ind[points[i].first];
        points[i].second = y_ind[points[i].second];
        x_points[points[i].first].insert(i);
        y_points[points[i].second].insert(i);
    }
    deque<pair<int, pair<int, int>>> q; // pair<dist, pair<index, direction> >
    q.push_front(make_pair(0, make_pair(0, 0)));
    q.push_front(make_pair(0, make_pair(0, 1)));
    // direction 0 = vertical(same x point), 1 = horizontal(same y point)
    while (!q.empty()) {
        pair<int, pair<int, int>> cur = q.front();
        q.pop_front();
        //        cout << cur.first << " " << cur.second.first << " " << cur.second.second << endl;
        if (dist[cur.second.first][cur.second.second] == cur.first) {
            int next_dist = cur.first + int(cur.second.second == 1);
            auto it = x_points[points[cur.second.first].first].lower_bound(cur.second.first);
            if (it != x_points[points[cur.second.first].first].begin()) {
                int next_point = *prev(it);
                if (dist[next_point][0] > next_dist) {
                    dist[next_point][0] = next_dist;
                    if (cur.first == next_dist) {
                        q.push_front(make_pair(next_dist, make_pair(next_point, 0)));
                    } else {
                        q.emplace_back(next_dist, make_pair(next_point, 0));
                    }
                }
            }
            if (it != x_points[points[cur.second.first].first].end() && next(it) != x_points[points[cur.second.first].first].end()) {
                int next_point = *next(it);
                if (dist[next_point][0] > next_dist) {
                    dist[next_point][0] = next_dist;
                    if (cur.first == next_dist) {
                        q.push_front(make_pair(next_dist, make_pair(next_point, 0)));
                    } else {
                        q.emplace_back(next_dist, make_pair(next_point, 0));
                    }
                }
            }
            //
            //            for (int i : x_points[points[cur.second.first].first]) {
            //                if (i != cur.second.first) {
            //                    if (dist[i][0] > next_dist) {
            //                        dist[i][0] = next_dist;
            //                        if (cur.first == next_dist) {
            //                            q.push_front(make_pair(next_dist, make_pair(i, 0)));
            //                        } else {
            //                            q.emplace_back(next_dist, make_pair(i, 0));
            //                        }
            //                    }
            //                }
            //            }
            next_dist = cur.first + int(cur.second.second == 0);
            it = y_points[points[cur.second.first].second].lower_bound(cur.second.first);
            if (it != y_points[points[cur.second.first].second].begin()) {
                int next_point = *prev(it);
                if (dist[next_point][1] > next_dist) {
                    dist[next_point][1] = next_dist;
                    if (cur.first == next_dist) {
                        q.push_front(make_pair(next_dist, make_pair(next_point, 1)));
                    } else {
                        q.emplace_back(next_dist, make_pair(next_point, 1));
                    }
                }
            }
            if (it != y_points[points[cur.second.first].second].end() && next(it) != y_points[points[cur.second.first].second].end()) {
                int next_point = *next(it);
                if (dist[next_point][1] > next_dist) {
                    dist[next_point][1] = next_dist;
                    if (cur.first == next_dist) {
                        q.push_front(make_pair(next_dist, make_pair(next_point, 1)));
                    } else {
                        q.emplace_back(next_dist, make_pair(next_point, 1));
                    }
                }
            }

//            for (int i : y_points[points[cur.second.first].second]) {
//                if (i != cur.second.first) {
//                    if (dist[i][1] > next_dist) {
//                        dist[i][1] = next_dist;
//                        if (cur.first == next_dist) {
//                            q.push_front(make_pair(next_dist, make_pair(i, 1)));
//                        } else {
//                            q.emplace_back(next_dist, make_pair(i, 1));
//                        }
//                    }
//                }
//            }
        }
    }
    cout << (min(dist[n + 1][0], dist[n + 1][1]) == inf ? -1 : min(dist[n + 1][0], dist[n + 1][1])) << "\n";
    return 0;
}

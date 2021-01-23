///*
//ID: izhang01
//TASK: fairphoto
//LANG: C++11
//*/
//
//#include <bits/stdc++.h>
//
//using namespace std;
//
//void setIO() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    freopen("fairphoto.in", "r", stdin);
//    freopen("fairphoto.out", "w", stdout);
//}
//
//
//int main() {
//    setIO();
//    int n;
//    cin >> n;
//    vector<pair<int, bool>> a(n);
//    char c;
//    for (int i = 0; i < n; ++i) {
//        cin >> a[i].first >> c;
//        if (c == 'S') {
//            a[i].second = false;
//        } else {
//            a[i].second = true;
//        }
//    }
//    sort(a.begin(), a.end());
//    int sol = 0;
//    for (int i = 0; i < n; ++i) {
//        int white = 0;
//        for (int j = i + 1; j < n; j += 2) {
//            if (a[j - 1].second) {
//                ++white;
//            }
//            if (a[j].second) {
//                ++white;
//            }
//            if (white * 2 >= j - i + 1) {
//                sol = max(sol, a[j].first - a[i].first);
//            }
//        }
//    }
//    cout << sol << "\n";
//    return 0;
//}

/*
ID: izhang01
TASK: fairphoto
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("fairphoto.in", "r", stdin);
    freopen("fairphoto.out", "w", stdout);
}

const int inf = 1e9;
int main() {
    setIO();
    int n;
    cin >> n;
    vector<pair<long long, bool>> a(n);
    char c;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> c;
        if (c == 'S') {
            a[i].second = false;
        } else {
            a[i].second = true;
        }
    }
    sort(a.begin(), a.end());
    vector<long long> pre_sum(n);
    set<pair<long long, int>> occ[2];
    int pre = 0;
    long long sol = 0;
    for (int i = 0; i < n; ++i) {
        if (occ[i % 2].empty() || occ[i % 2].rend()->first < pre) {
            occ[i % 2].insert({pre, i});
        }
        if (a[i].second) {
            ++pre;
        } else {
            --pre;
        }
        auto it = occ[!(i % 2)].lower_bound({-pre, 0});
        if (it != occ[!(i % 2)].end()) {
            //            cout << i << " " << a[i].first << " " << a[it->second].first << "\n";
            sol = max(sol, a[i].first - a[it->second].first);
        }
    }
    cout << sol << "\n";
    return 0;
}

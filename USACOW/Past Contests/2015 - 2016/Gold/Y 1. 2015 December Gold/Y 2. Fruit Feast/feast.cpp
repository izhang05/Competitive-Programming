// O(nlogn)
///*
//ID: izhang01
//TASK: feast
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
//    freopen("feast.in", "r", stdin);
//    freopen("feast.out", "w", stdout);
//}
//const int maxn = 50000001;
//bool pos[maxn];
//
//
//int main() {
//    setIO();
//    int t, a, b;
//    cin >> t >> a >> b;
//    queue<int> q;
//    q.push(a);
//    q.push(b);
//    pos[0] = pos[a] = pos[b] = true;
//    int sol = 0;
//    set<int> nums;
//    while (!q.empty()) {
//        int cur = q.front();
//        q.pop();
//        nums.insert(cur);
//        sol = max(sol, cur);
//        if (cur + a <= t && !pos[cur + a]) {
//            q.push(cur + a);
//            pos[cur + a] = true;
//        }
//        if (cur + b <= t && !pos[cur + b]) {
//            q.push(cur + b);
//            pos[cur + b] = true;
//        }
//    }
//
//    for (int i : nums) {
//        auto it = nums.upper_bound(t - i / 2);
//        if (it != nums.begin()) {
//            --it;
//            sol = max(sol, *it + i / 2);
//        }
//    }
//    cout << sol << "\n";
//    return 0;
//}


// O(n)
/*
ID: izhang01
TASK: feast
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);
}

const int maxn = 50000001;
bool pos[maxn][2];


int main() {
    setIO();
    int t, a, b;
    cin >> t >> a >> b;
    queue<int> q;
    q.push(a);
    q.push(b);
    pos[0][0] = true;
    int sol = 0;
    for (int i = 0; i < t; ++i) {
        if (pos[i][0]) {
            if (i + a <= t) {
                pos[i + a][0] = true;
                sol = max(sol, i + a);
            }
            if (i + b <= t) {
                pos[i + b][0] = true;
                sol = max(sol, i + b);
            }
            pos[i / 2][1] = true;
        }
    }
    for (int i = 0; i < t; ++i) {
        if (pos[i][1]) {
            if (i + a <= t) {
                pos[i + a][1] = true;
                sol = max(sol, i + a);
            }
            if (i + b <= t) {
                pos[i + b][1] = true;
                sol = max(sol, i + b);
            }
            pos[i / 2][1] = true;
        }
    }
    cout << sol << "\n";
    return 0;
}

///*
//ID: izhang01
//TASK: scramble
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
//    freopen("scramble.in", "r", stdin);
//    freopen("scramble.out", "w", stdout);
//}
//
//
//int main() {
//    setIO();
//    int n;
//    cin >> n;
//    set<string> low, high;
//    vector<pair<string, string>> cows(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> cows[i].first;
//        string copy = cows[i].first;
//        sort(copy.begin(), copy.end());
//        cows[i].first = copy;
//        low.insert(copy);
//        sort(copy.begin(), copy.end(), greater<char>());
//        high.insert(copy);
//        cows[i].second = copy;
//    }
////    if (n == 4) {
////        cout << 2 << " " << 3 << "\n";
////        cout << 1 << " " << 1 << "\n";
////        cout << 4 << " " << 4 << "\n";
////        cout << 2 << " " << 3 << "\n";
////    }
////    return 0;
//    for (pair<string, string> i : cows) {
//        high.erase(i.second);
//        high.insert(i.first);
//        cout << distance(high.begin(), high.lower_bound(i.first)) + 1 << " ";
//        high.erase(i.first);
//        high.insert(i.second);
//
//        low.erase(i.first);
//        low.insert(i.second);
//        cout << distance(low.begin(), low.lower_bound(i.second)) + 1 << "\n";
//        low.erase(i.second);
//        low.insert(i.first);
//    }
//    return 0;
//}

/*
ID: izhang01
TASK: scramble
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("scramble.in", "r", stdin);
    freopen("scramble.out", "w", stdout);
}

bool is_same_char(string s) {
    char cur = s[0];
    for (char i : s) {
        if (i != cur) {
            return false;
        }
    }
    return true;
}

int main() {
    setIO();
    int n;
    cin >> n;
    set<string> low_sort, same;
    vector<pair<string, string> > cows(2 * n);
    vector<pair<int, int> > sol(n);
    map<string, int> index;
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        string orig = s;
        if (is_same_char(s)) {
            same.insert(s);
            cows[2 * i] = pair<string, string>{s, s};
            cows[2 * i + 1] = pair<string, string>{s, s};
            index[s] = i;
        } else {
            sort(s.begin(), s.end());
            cows[2 * i] = pair<string, string>{s, orig};
            low_sort.insert(s);
            sort(s.begin(), s.end(), greater<char>());
            index[orig] = i;
            cows[2 * i + 1] = pair<string, string>{s, orig};
        }
    }
    sort(cows.begin(), cows.end());
//    cout << 2 * n << " " << cows.size() << "\n";
//    cout << index.size() << "\n";
    int low = 0, high = 0;
    for (auto i : cows) {
        if (!is_same_char(i.first)) {
            if (low_sort.find(i.first) != low_sort.end()) {
                ++low;
                sol[index[i.second]].first = high + 1;
            } else {
                ++high;
                sol[index[i.second]].second = low;  // No +1 because low includes self reversed
            }
        } else {
            if (same.find(i.first) != same.end()) {
                ++low;
                sol[index[i.second]].first = high + 1;
                same.erase(i.first);
            } else {
                ++high;
                sol[index[i.second]].second = low; // No +1 because low includes self reversed
//                assert(sol[index[i]].first == sol[index[i]].second);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << sol[i].first << " " << sol[i].second << "\n";
    }
    return 0;
}

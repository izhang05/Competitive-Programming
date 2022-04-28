#include <bits/stdc++.h>

using namespace std;

int binsearch(const vector<int> &a, int val) {
    int lo = 0, hi = int(a.size()) - 1, mid;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (a[mid] == val) {
            return mid;
        }
        if (a[mid] < val) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return -1;
}

int main() {
    unordered_map<int, int> m;
    m[0] = 1;
    m[0]++;
    cout << m[0] << "\n";
//    cout << binsearch(vector<int>{1, 3, 5, 9, 11, 13, 17}, 12) << "\n";
    return 0;
}

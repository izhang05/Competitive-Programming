#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    set<int> a;
    int num;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        a.insert(num);
    }
    multiset<int, greater<> > intervals;
    for (auto it = a.begin(); ++it != a.end(); ++it) {
        intervals.insert(*it - *--it);
    }
    cout << *a.rbegin() - *a.begin() - *intervals.begin() << "\n";
    int b, c;
    for (int i = 0; i < q; ++i) {
        cin >> b >> c;
        if (b) {
            auto it = a.upper_bound(c);
            if (it == a.begin()) {
                intervals.insert(*a.begin() - c);
            } else if (it == a.end()) {
                intervals.insert(c - *a.rbegin());
            } else {
                if (!intervals.empty()) {
                    intervals.erase(intervals.find(*it - *--it));
                }
                intervals.insert(c - *it);
                intervals.insert(*++it - c);
            }
            a.insert(c);
        } else {
            a.erase(c);
            auto it = a.upper_bound(c);
            if (it == a.begin()) {
                if (!intervals.empty()) {
                    intervals.erase(intervals.find(*it - c));
                }
            } else if (it == a.end()) {
                if (!intervals.empty()) {
                    intervals.erase(intervals.find(c - *--it));
                }
            } else {
                if (!intervals.empty()) {
                    intervals.erase(intervals.find(*it - c));
                }
                if (!intervals.empty()) {
                    intervals.erase(intervals.find(c - *--it));
                }
                intervals.insert(*++it - *--it);
            }
        }
        if (a.size() <= 2) {
            cout << 0 << "\n";
        } else {
            cout << *a.rbegin() - *a.begin() - *intervals.begin() << "\n";
        }
    }
    return 0;
}

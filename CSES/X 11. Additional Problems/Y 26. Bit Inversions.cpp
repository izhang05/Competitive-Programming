#include <bits/stdc++.h>
using namespace std;

string s;
set<int> diff; // stores the indices i where s[i - 1] != s[i]
multiset<int, greater<>> ranges; // multiset that orders element from greatest to smallest
int n;
void modify(int x) {
    if (x == 0 || x == n) {
        return;
    }
    auto it = diff.find(x);
    if (it != diff.end()) { // x is in the set diff, which means s[x] != s[x - 1]
        // we want to delete all ranges involving index x
        int a = *prev(it), b = *next(it); // a is the previous element (from x) in diff, and b is the next element
        ranges.erase(ranges.find(x - a)); // delete the range from x to the previous element in diff
//        ranges.erase(x - a); // bad because this deletes all occurrences of x - a
        ranges.erase(ranges.find(b - x)); // delete the range from x to the next element in diff

        ranges.insert(b - a); // add the new range formed by the deletion of x
        diff.erase(it);
    } else { // x is not in the set diff, which means s[x] == s[x - 1]
        // we perform similar operations as before, but we swap when we insert or delete
        it = diff.insert(x).first; // returns an iterator to element x
        int a = *prev(it), b = *next(it);
        ranges.erase(ranges.find(b - a));
        ranges.insert(x - a);
        ranges.insert(b - x);
    }
}

int main() {
    cin >> s;
    n = (int) s.size();
    int m;
    cin >> m;
    for (int i = 1; i < n; ++i) {
        if (s[i] != s[i - 1]) { // insert indices where consecutive elements are different into diff
            diff.insert(i);
        }
    }
    diff.insert(0);
    diff.insert(n);
    for (auto it = next(diff.begin()); it != diff.end(); ++it) {
        ranges.insert(*it - *prev(it)); // iterate through diff and add the difference of every consecutive pair into ranges.
    }
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        --x; // 0 index
        modify(x);
        modify(x + 1);
        cout << *ranges.begin() << " ";
    }
    cout << "\n";
    return 0;
}

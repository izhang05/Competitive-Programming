#include <bits/stdc++.h>

using namespace std;

int main() {
    int x, n;
    cin >> x >> n;
    long long sol = 0;
    priority_queue<int, vector<int>, greater<>> nums; // priority queue ordered from smallest to largest
    // we solve the problem in reverse order by building up to a full stick from the stick segments
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        nums.push(a);
    }
    while (nums.size() >= 2) {
        // take the two smallest stick segments and merge them
        int a = nums.top();
        nums.pop();
        int b = nums.top();
        nums.pop();
        sol += a + b;
        nums.push(a + b);
    }
    cout << sol << "\n";
    return 0;
}

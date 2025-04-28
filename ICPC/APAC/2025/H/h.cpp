#include <bits/stdc++.h>

using namespace std;

char type(int j) {
    cout << "type " << j << endl;
    string res;
    cin >> res;
    if (res == "lily") {
        return 'l';
    }
    return 'r';
}

int multi(int j) {
    cout << "multi " << j << endl;
    int res;
    cin >> res;
    return res;
}

void ans(int k) {
    cout << "answer " << k << endl;
}

void solve() {
    int n;
    cin >> n;
    int lo = 1, hi = n, mid;
    map<int, char> flower;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        char res = type(mid);
        flower[mid] = res;
        if (res == 'l') {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    int x, y, z;
    if (flower[mid] == 'l') {
        z = mid;
        y = mid - 1;
        x = mid - 2;
    } else {
        z = mid + 1;
        y = mid;
        x = mid - 1;
    }
    if (y == n) {
        ans(n - multi(n - 1));
        return;
    }
    if (y == 0) {
        ans(multi(1));
        return;
    }
    int qx = multi(x), qy = multi(y), qz = multi(z);
    int l_left = qx - qy;
    int r_right = qz - qy;
    int roses = r_right + (y - l_left);
    ans(roses);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

/*
ID: izhang01
TASK: a.cpp
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    freopen("paint.out", "w", stderr);
}
//#define DEBUG

int main() {
    setIO();
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a > c) {
        swap(a, c);
        swap(b, d);
    }
    int sol = (b - a) + (d - c);
    if (b > d) { // second segment contained in first
        sol -= d - c;
    } else if (b > c) { // subtract the intersection of the two ranges
        sol -= b - c;
    }
    cout << sol << "\n";
    return 0;
}

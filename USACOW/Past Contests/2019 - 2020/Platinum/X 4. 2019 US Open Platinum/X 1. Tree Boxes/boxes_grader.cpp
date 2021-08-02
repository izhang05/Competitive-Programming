#include "grader.h"
#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    freopen("boxes.in", "r", stdin);
    freopen("boxes.out", "w", stdout);
    freopen("boxes.out", "w", stderr);
}
int i_n, i_q;

void setFarmLocation(int id, int x, int y) {
    cout << id << " " << x << " " << y << "\n";
}

void addBox(int x1, int y1, int x2, int y2) {
    cout << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
}

int getN() {
    return i_n;
}
int getQ() {
    return i_q;
}

int main() {
    setIO();
    cin >> i_n >> i_q;
    for (int i = 0; i < i_n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        addRoad(a, b);
    }
    buildFarms();
    while (i_q--) {
        int a, b;
        cin >> a >> b;
        notifyFJ(a, b);
    }
    return 0;
}

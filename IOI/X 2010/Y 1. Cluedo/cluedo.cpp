#ifndef DEBUG
#include <cluedo.h>
#include <grader.h>
#endif

#include <bits/stdc++.h>

using namespace std;


void Solve() {
    int i = 1, j = 1, k = 1;
    while (true) {
        int res = Theory(i, j, k);
        if (res == 0) {
            break;
        }
        if (res == 1) {
            ++i;
        } else if (res == 2) {
            ++j;
        } else if (res == 3) {
            ++k;
        }
    }
}


#ifdef DEBUG
int main() {
}
#endif
#include "grader.h"
#include "memory.h"
 
#include <bits/stdc++.h>
 
using namespace std;
 
void play() {
    map<char, vector<int>> ind;
    for (int i = 1; i < 51; ++i) {
        char cur = faceup(i);
        ind[cur].push_back(i);
    }
    for (auto i : ind) {
        for (int j : i.second) {
            faceup(j);
        }
    }
}
 
#ifdef DEBUG
int main() {
    play();
}
#endif
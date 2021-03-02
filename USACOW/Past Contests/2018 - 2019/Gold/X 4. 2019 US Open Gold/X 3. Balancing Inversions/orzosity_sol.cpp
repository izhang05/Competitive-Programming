#include <cmath>
#include <iostream>
#include <stack>

using namespace std;

#define MAXN 100010

int n, arr[MAXN * 2];
int caused[MAXN * 2];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < 2 * n; i++)
        scanf("%d", &arr[i]);

    int lonecnt = 0, lzcnt = 0;
    int linv = 0;
    stack<int> lones, lzs;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) lonecnt++, lones.push(i);
        else
            linv += lonecnt, lzcnt++, caused[i] = lonecnt, lzs.push(i);
    }

    int rzcnt = 0, rocnt = 0;
    int rinv = 0;
    stack<int> ros, rzs;
    for (int i = 2 * n - 1; i >= n; i--) {
        if (arr[i] == 0) rzcnt++, rzs.push(i);
        else
            rinv += rzcnt, rocnt++, caused[i] = rzcnt, ros.push(i);
    }

    lonecnt = 0, lzcnt = 0, linv = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] == 0) lzcnt++;
        else
            lonecnt++, linv += lzcnt, caused[i] = lzcnt;
    }

    rzcnt = 0, rocnt = 0, rinv = 0;
    for (int i = n; i < 2 * n; i++) {
        if (arr[i] == 1) rocnt++;
        else
            rzcnt++, rinv += rocnt, caused[i] = rocnt;
    }


    if (rinv == linv) {
        printf("%d\n", 0);
        return 0;
    }
    if ((rinv > linv && rzcnt > lonecnt) || (rinv < linv && rocnt > lzcnt)) {
        int moves = 0, rem = abs(rinv - linv);
        while (lzs.size() && ros.size()) {
            int moveneed = n - 1 - lzs.top() + (ros.top() - n) + 1;
            int diff = abs(caused[lzs.top()] - caused[ros.top()]);
            //cout << moveneed << " " << diff << endl;


            if (moveneed > diff || (diff > rem && moveneed + abs(diff - rem) > rem)) {
                moves += rem;
                break;
            }
            if (diff > rem) {
                moves += diff + abs(diff - rem);
                break;
            }
            rem -= diff;
            moves += moveneed;
            lzs.pop();
            ros.pop();
            if (rem == 0) break;
        }
        printf("%d\n", moves);
    }

    else if ((rinv > linv && lonecnt > rzcnt) || (rinv < linv && rocnt < lzcnt)) {

        int moves = 0, rem = abs(rinv - linv);

        while (lones.size() && rzs.size()) {
            int moveneed = n - 1 - lones.top() + (rzs.top() - n) + 1;
            int diff = abs((--lonecnt) - caused[lones.top()] - (--rzcnt) + caused[rzs.top()]);
            rocnt++;
            lzcnt++;

            if (moveneed > diff || (diff > rem && moveneed + abs(diff - rem) > rem)) {
                moves += rem;
                break;
            }
            if (diff > rem) {
                moves += diff + abs(diff - rem);
                break;
            }
            rem -= diff;
            moves += moveneed;
            lones.pop();
            rzs.pop();
            if (rem == 0) break;
        }
        printf("%d\n", moves);
    }

    else {
        printf("%d\n", abs(rinv - linv));
    }
}
#include <bits/stdc++.h>

using namespace std;

const long MOD = 1e9 + 7;

int main() {
    int T;
    cin >> T;
    string str;
    for (int i = 0; i < T; i++) {
        int N, M;
        cin >> N >> M;
        char arr[N][M];
        for (int j = 0; j < N; j++) {
            cin >> str;
            for (int k = 0; k < M; k++) {
                arr[j][k] = str.at(k);
            }
        }
        //X's used to denote cells that are forced
        //Subtask 2
        //Step 1: Fill all forced

        //Vertical: This can be determined by each center's vertical neighbour
        long long ans = 1;
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (arr[j][k] == 'o') {
                    if (j == 0 || j == N - 1) {
                        ans = 0;
                    }
                    if (j == 0 || (arr[j - 1][k] == 'o' || arr[j - 1][k] == '#')) {
                        if (j + 1 < N && arr[j + 1][k] == '.') {
                            arr[j + 1][k] = 'X'; //Forced
                        } else {
                            ans = 0;
                        }
                    } else {
                        if (arr[j - 1][k] == '.') {
                            arr[j - 1][k] = 'X';
                        } else {
                            ans = 0;
                        }

                    }
                }
            }
        }
        //Test:
        /*
        for(int j=0;j<N;j++){
            cout << "\n";
            for(int k=0;k<M;k++){
                cout << arr[j][k];
            }
        }
         */
        //Now fill horizontal
        //Group into chunks of size 2

        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (arr[j][k] == 'o') { //This is leftmost part
                    int cnt = 1;
                    int cur = k; //Block of o.o.o.o.o.o.o
                    while (cur < M && arr[j][cur] == 'o') {
                        cur += 2;
                        cnt++;
                    }
                    cur -= 2;
                    //Now decide whether to multiply by cnt or not
                    int x = 0;
                    if (!(k > 0 && arr[j][k - 1] == '.')) {
                        x++;
                    }
                    if (!(cur < M - 1 && arr[j][cur + 1] == '.')) {
                        x++;
                    }
                    for (int l = k + 1; l < cur; l += 2) {
                        if (arr[j][l] != '.') {
                            x++;
                        }
                    }
                    if (x == 0) {
                        ans *= cnt;
                        ans %= MOD;
                    } else if (x >= 2) {
                        ans = 0;
                    }
                    k = cur + 2;
                }
            }
            //cout << ans << "\n";
        }
        cout << ans << "\n";
    }


}


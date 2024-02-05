#include <bits/stdc++.h>

using namespace std;


int main() {


    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N, K;
        cin >> N >> K;
        string s;
        cin >> s;

        int wildcard = 0;
        int cnt = 0;
        int j = 0;
        while (j < N && s.at(j) == 'W') {
            j++;
        }
        //So at this point s.at(j) is not 'W'
        if (j == N) {//The trivial case
            if (N & 1) {
                cout << "Amy" << "\n";
            } else {
                cout << "Aimee" << "\n";
            }
        } else {
            if (j == 1) {
                cnt++;
            } else if (j > 1) {
                wildcard++;
            }
            int k = N - 1;
            while (k >= 0 && s.at(k) == 'W') {
                k--;
            }
            if (k < N - 2) {
                wildcard++;
            } else if (k == N - 2) {
                cnt++;
            }

            if (wildcard == 1) {
                cout << "Amy" << "\n";
            } else {
                //Pretend wildcards don't exist
                char cur = s.at(j); //This is G or R
                int c = j;
                for (int l = j + 1; l <= k; l++) {
                    if (s.at(l) != 'W') {
                        if (l == c + 1 || s.at(l) == cur) {
                            cnt += (l - c - 1);
                        } else {
                            cnt += (l - c);
                        }
                        c = l;
                        cur = s.at(c);
                    }
                }
                if (wildcard == 0 || j == N - 1 - k) {
                    if (cnt & 1) {
                        cout << "Amy" << "\n";
                    } else {
                        cout << "Aimee" << "\n";
                    }
                } else if (j - (N - 1 - k) >= 2 || (N - 1 - k) - j >= 2) { //Wildcard = 2
                    cout << "Amy" << "\n";
                } else {
                    cnt++;
                    if (cnt & 1) {
                        cout << "Amy" << "\n";
                    } else {
                        cout << "Aimee" << "\n";
                    }
                }
            }
        }
    }
}

#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> arr(7, vector(26, '.'));

int d, h;

long double ans;

int main(){
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 24; j++){
            cin >> arr[i][j];
        }
    }

    cin >> d >> h;

    for(int m = 0; m < (1 << 24); m++){
        if(__builtin_popcount(m) == h){
            vector<int> cnts(7, 0);

            for(int i = 0; i < 24; i++){
                if((m >> i) & 1){
                    for(int j = 0; j < 7; j++){
                        cnts[j] += arr[j][i] == '.';
                    }
                }
            }

            sort(cnts.begin(), cnts.end(), greater<int>());

            int sum = 0;

            for(int i = 0; i < d; i++) sum += cnts[i];

            ans = max(ans, (long double)sum / (d * h));
        }
    }

    cout << setprecision(16) << fixed << ans;

    return 0;
}

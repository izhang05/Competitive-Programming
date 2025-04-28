#include <bits/stdc++.h>

using namespace std;

int n, m;

vector<vector<char>> arr;
vector<int> rowcnt, colcnt;

long long ans;

int main(){
    ios_base::sync_with_stdio();cin.tie(nullptr);

    cin >> n >> m;

    arr.assign(n, vector(m, '0'));
    rowcnt.assign(n, 0), colcnt.assign(m, 0);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];

            if(arr[i][j] == '.') rowcnt[i]++, colcnt[j]++;
        }
    }


    for(int row = 0; row < n; row++){
        ans += 1ll * rowcnt[row] * (rowcnt[row] - 1) * (rowcnt[row] - 2) * (rowcnt[row] - 3);

        long long sum = 0, sum2 = 0;

        for(int col = 0; col < m; col++){
            if(arr[row][col] == '.'){
                ans += 1ll * 2 * (colcnt[col] - 1) * (colcnt[col] - 2) * (rowcnt[row] - 1);

                if(colcnt[col] >= 2){
                    sum += colcnt[col] - 1;
                    sum2 += (colcnt[col] - 1) * (colcnt[col] - 1);
                }
            }
        }

        ans += sum * sum - sum2;
    }

    for(int col = 0; col < m; col++){
        ans += 1ll * colcnt[col] * (colcnt[col] - 1) * (colcnt[col] - 2) * (colcnt[col] - 3);

        long long sum = 0, sum2 = 0;

        for(int row = 0; row < n; row++){
            if(arr[row][col] == '.'){
                ans += 1ll * 2 * (rowcnt[row] - 1) * (rowcnt[row] - 2) * (colcnt[col] - 1);

                if(rowcnt[row] >= 2){
                    sum += rowcnt[row] - 1;
                    sum2 += (rowcnt[row] - 1) * (rowcnt[row] - 1);
                }
            }
        }

        ans += sum * sum - sum2;
    }

    cout << ans;
}

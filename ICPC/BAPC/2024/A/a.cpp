#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    int n, m, k;

    cin >> n >> m >> k;

    vector<pair<int, int>> arr;

    for(int i = 0; i < n; i++){
        string str;

        cin >> str;

        arr.push_back({count(str.begin(), str.end(), 'P'), i + 1});
    }

    while(true){
        bool flag = false;

        for(int i = n - 1; i >= 0; i--){
            if(arr[i].first){
                arr[i].first--;

                flag = true;

                string str;

                cin >> str >> str;

                if(str[3] == 'y'){
                    int ycount = str.size() - 9;

                    int newrank = i - ycount;

                    vector<pair<int, int>> newarr;

                    for(int j = 0; j < newrank; j++) newarr.push_back(arr[j]);

                    newarr.push_back(arr[i]);

                    for(int j = newrank; j < n; j++) if(j != i) newarr.push_back(arr[j]);

                    arr = newarr;
                }


                break;
            }
        }

        if(!flag) break;
    }

    for(int i = 0; i < n; i++){
        if(arr[i].second == k){
            cout << i + 1;
            return 0;
        }
    }
}
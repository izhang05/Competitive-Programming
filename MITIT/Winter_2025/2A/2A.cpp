#include <bits/stdc++.h>

using namespace std;

int n;

vector<int> arr, vis, par;
vector<array<int, 3>> ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    arr.assign(n + 1, 0);

    for(int i = 1; i <= n; i++) cin >> arr[i];

    vis = par = vector(n + 1, 0);

    int cur = 0;

    for(int i = 1; i <= n; i++){
        if(vis[i] == 0){
            cur++;
            int v = i;

            while(vis[v] == 0){
                vis[v] = cur;
                par[arr[v]] = v;

                if(vis[arr[v]] == cur){
                    int e = arr[v];

                    while(v != e){
                        ans.push_back({1, v, par[v]});
                        swap(arr[v], arr[par[v]]);

                        v = par[v];
                    }
                }

                v = arr[v];
            }
        }
    }

    for(int i = 1; i <= n; i++){
        if(arr[i] != i){
            ans.push_back({2, arr[i], i});
        }
    }

    cout << ans.size() << "\n";

    for(auto v : ans) cout << v[0] << " " << v[1] << " " << v[2] << "\n";
}
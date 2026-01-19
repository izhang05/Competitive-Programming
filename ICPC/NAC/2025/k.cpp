#include <bits/stdc++.h>

using namespace std;

int n;

vector<int> arr;

long long ans;

int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  cin >> n;

  arr.assign(n, 0);

  for(auto &x : arr) cin >> x;

  int k = 0;

  while(k < n && arr[k] == 0) k++;

  if(k == n){
    cout << 0;
    return 0;
  }

  if(arr[k] > 0) ans = arr[k] + 2;

  for(int i = k + 1; i < n; i++){
    if(arr[i] > arr[i - 1]){
      ans += arr[i] - arr[i - 1] + 1;
    }
  }

  cout << ans;
}
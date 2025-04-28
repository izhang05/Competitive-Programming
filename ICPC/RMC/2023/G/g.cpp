#include <bits/stdc++.h>

using namespace std;

vector<int> fix(vector<int> arr, int l, int r){
    vector<int> newarr;

    for(auto c : arr){
        if(l <= c && c <= r) continue;
        else newarr.push_back(c);
    }

    return newarr;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, r;

    cin >> n >> r;

    vector<int> arr(n);

    for(int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    vector<int> ansvec;

    while(!arr.empty()){
        pair<int, int> ans = {0, -1};

        int lft = 0;

        for(int rght = 0; rght < arr.size(); rght++){
            while(arr[rght] - arr[lft] > 2 * r) lft++;

            pair<int, int> tmp = {rght - lft + 1, arr[rght] - r};

            if(tmp.first > ans.first) ans = tmp;
        }

        ansvec.push_back(ans.second);

        arr = fix(arr, ans.second - r, ans.second + r);
    }

    cout << ansvec.size() << "\n";

    for(auto x : ansvec) cout << x << " ";
}

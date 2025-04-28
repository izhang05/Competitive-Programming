#include <bits/stdc++.h>

using namespace std;

int n, m;

vector<int> a, b;

string stra, strb;

void solve(){
    cin >> n >> m;
    cin >> stra >> strb;

    a = {0}, b = {0};

    for(auto c : stra){
        if(c == '1') a.back()++;
        else a.push_back(0);
    }

    for(auto c : strb){
        if(c == '1') b.back()++;
        else b.push_back(0);
    }

    if(count(stra.begin(), stra.end(), '0') > 0 && count(strb.begin(), strb.end(), '0') == 0){
        cout << "no\n";
        return;
    }

    if(a[0] < b[0]){
        cout << "no\n";
        return;
    }

    if(a.back() < b.back()){
        cout << "no\n";
        return;
    }

    int ptr = 0;

    for(auto x : b){
        while(ptr + 1 < a.size() && a[ptr] < x) ptr++;

        if(ptr < a.size() && a[ptr] >= x) ptr++;
        else{
            cout << "no\n";
            return;
        }
    }

    cout << "yes\n";
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    int t;

    cin >> t;

    while(t--) solve();
}

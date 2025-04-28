#include <bits/stdc++.h>

using namespace std;

int n, s, cur, cnt1, cnt2, cnt11, ans;

vector<int> arr;

int main() {
    cin >> n >> s;

    arr.assign(n, 0);

    for(auto &x : arr) cin >> x;

    sort(arr.begin(), arr.end());

    if(n == 1){
        cout << 1;
        return 0;
    }

    if(s == 1){
        cout << 1;
        return 0;
    }

    cur = ans = 2;

    for(int i = 0; i < n - 2; i++){
        if(arr[i] % 3 == 0){
            cur += arr[i] / 3;
        }
        else if(arr[i] % 3 == 1){
            cur += arr[i] / 3 + 1;
            cnt1++;

            while(cnt2 > 0 && cnt1 > 0){
                cur--;
                cnt1--;
                cnt2--;
            }

            while(cnt1 >= 2){
                cnt1 -= 2;
                cnt11++;

                cur--;
            }
        }
        else if(arr[i] % 3 == 2){
            cur += arr[i] / 3 + 1;
            cnt2++;

            if(cnt1 == 0 && cnt11 > 0){
                cnt11--;
                cur++;
                cnt1 += 2;
            }

            while(cnt2 > 0 && cnt1 > 0){
                cur--;
                cnt1--;
                cnt2--;
            }
        }

        if(cur <= s) ans++;
        else break;
    }

    cout << ans;

    return 0;
}

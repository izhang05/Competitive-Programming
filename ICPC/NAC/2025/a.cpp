#include <bits/stdc++.h>

using namespace std;

const int mxn = 1e5+5;

int prime[mxn];
map<int,int, greater<>> fact_list[mxn];

long long binpow(long long a, long long b) {
    long long c = 1;
    for(; b > 0; b /= 2, a = a*a) if(b & 1) c = c*a;
    return c;
}

map<int, int,greater<>> fact(int x) {
    map<int,int,greater<>> res;
    while(x > 1) {
        ++res[prime[x]];
        x /= prime[x];
    }
    res[1] = 1;
    // while(x%2==0) {
    //     ++res[2];
    //     x /= 2;
    // }
    // for(int i=3;i*i<=x;i+=2) {
    //     while(x%i==0) {
    //         ++res[i];
    //         x/=i;
    //     }
    // }
    // if (x != 1) {
    //     ++res[x];
    // }
    return res;
}

int main(){
    memset(prime,-1,sizeof(prime));
    for (int i = 2; i < mxn; i++) {
        if (prime[i] == -1) {
            prime[i] = i;
            for (int j = i + i; j < mxn; j += i) {
                prime[j] = i;
            }
        }
    }
    for (int i = 1; i < mxn; i++) {
        fact_list[i] = fact(i);
    }

    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int a,b;
    cin >> a >> b;
    map<int,int,greater<>> fa = fact_list[a],fb=fact_list[b];
    long long resa = 1, resb = 1;
    while(!(fa.empty()&&fb.empty())) {
        pair<int, int> pa = *fa.begin(), pb = *fb.begin();
        if (pa.first == 1 && pb.first == 1) {
            break;
        }
        // cout << pa.first << " " << pa.second << " " << pb.first << " " << pb.second << endl;
        if (pa.first == pb.first) {
            if (pa.second == pb.second) {
                fa.erase(fa.begin());
                fb.erase(fb.begin());
                continue;
            } else if (pa.second < pb.second) {
                pb.second -= pa.second;
                fa.erase(fa.begin());
                pa.first = -1;
            }else {
                pa.second -= pb.second;
                fb.erase(fb.begin());
                pb.first = -1;
            }
        }

        if (pa.first > pb.first) {
            if (pa.second % 2 ==1) {
                resa *= binpow(pa.first, (pa.second + 1)/2);
                for (auto i : fact_list[pa.first - 1]) {
                    fb[i.first] += i.second;
                }
            }else {
                resa *= binpow(pa.first, (pa.second)/2 + 1);
                // cout << pa.first<< endl;
                resb *= pa.first;
            }
            fa.erase(fa.begin());
        }else if (pa.first < pb.first) {
            if (pb.second % 2 ==1) {
                // cout << binpow(pb.first, (pb.second + 1)/2) << endl;
                resb *= binpow(pb.first, (pb.second + 1)/2);
                for (auto i : fact_list[pb.first - 1]) {
                    fa[i.first] += i.second;
                }
            }else {
                // cout << binpow(pb.first, (pb.second)/2 + 1) << endl;
                resb *= binpow(pb.first, (pb.second)/2 + 1);
                resa *= pb.first;
            }
            fb.erase(fb.begin());
        }
    }

    cout << resa << " " << resb << "\n";
}
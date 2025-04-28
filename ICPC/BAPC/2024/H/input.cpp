//#pragma GCC optimize("O3,unroll-loops")
//
//#include <bits/stdc++.h>
//
//using namespace std;
//
//int n, m, q;
//
//mt19937 rng(25);
//
//int randint(int a, int b){
//    return uniform_int_distribution(a, b)(rng);
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);cin.tie(NULL);
//
//    int n = 3000, m = 3000, q = 1e5;
//
//    cout << n << " " << m << " " << q << "\n";
//
//    for(int i = 0; i < n; i++){
//        for(int j = 0; j < m; j++){
//            cout << vector{'#', '.'}[randint(0, 1)];
//        }
//        cout << "\n";
//    }
//
//    while(q--){
//        cout << randint(1, n) << " " << randint(1, m) << "\n";
//    }
//}

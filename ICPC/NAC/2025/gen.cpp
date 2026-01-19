#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int randint(int a, int b) {
    return uniform_int_distribution<int>(a, b)(rng);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    int n = randint(2, 15);

    cout << n << "\n";

    for(int i = 2; i <= n; i++) cout << randint(1, i - 1) << " " << i << "\n";
}
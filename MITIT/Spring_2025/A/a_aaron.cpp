#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

void test_case() {
    int n; cin >> n;
    if(n == 4){
        cout << 2025 << "\n";
        return;
    }
    if(n == 5){
        cout << 42025 << "\n";
        return;
    }
    if(n % 2 == 0){
        int nines = (n - 4)/2;
        int zeros = (n - 6)/2;
        string s = "";
        for (int i = 0; i < nines; ++i) {
            s += "9";
        }
        s += "1";
        for (int i = 0; i < zeros; ++i) {
            s += "0";
        }
        s += "2025";
        cout << s << "\n";
        return;
    }
    else{
        int z1 = (n - 5)/2;
        int z2 = (n - 7)/2;
        string s = "1";
        for (int i = 0; i < z1; ++i) {
            s += "0";
        }
        s += "9";
        for (int i = 0; i < z2; ++i) {
            s += "0";
        }
        s += "2025";
        cout << s << "\n";
        return;
    }
}

int main() {
    setIO();

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}

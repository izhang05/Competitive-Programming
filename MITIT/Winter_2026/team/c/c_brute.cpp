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

int find(int x, int b) {
    for (int i = 1; i < 1e4; ++i) {
        int y = i;
        if (y % b != 1)
            continue;
        int z = x + y;
        multiset<int> digitsy;

        while (y > 0) {
            digitsy.insert(y % b);
            y = y / b;
        }

        multiset<int> digitsz;
        while (z > 0) {
            digitsz.insert(z % b);
            z = z / b;
        }

        if (digitsz == digitsy) {
            return i;
        }
    }
    return -1;
}

void printbase(int x, int b) {
    vector<int> digits;
    while (x > 0) {
        digits.push_back(x % b);
        x = x / b;
    }

    for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
        cout << *(it);
    }
    cout << " ";
}

void test_case() {
//    int N, B; cin >> N >> B;
//
//    vector<int> x(N);
//    for (int i = 0; i < N; ++i) {
//        cin >> x[i];
//    }
//    reverse(x.begin(), x.end());
    int b = 5;
    for (int x = 200; x <= 300; ++x) {
        if (find(x, b) != -1) {
            //cout << x << " " << find(x, b) << endl;
            printbase(x, b);
            printbase(find(x, b), b);
            cout << endl;
        }
    }

}

int main() {
    setIO();

    int test_case_number = 1;
    //cin >> test_case_number;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}

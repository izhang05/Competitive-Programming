//#include <bits/stdc++.h>
//
//using namespace std;
//
////#define DEBUG
//void setIO() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cin.exceptions(istream::failbit);
//}
//
//const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
//const long long INFL = 0x3f3f3f3f3f3f3f3f;
//
//void test_case() {
//    long long N, B;
//    cin >> N >> B;
//    long long sum = 0;
//    vector<long long> x(N);
//    for (long long i = 0; i < N; ++i) {
//        cin >> x[i];
//        sum += x[i];
//    }
//    if ((sum % (B - 1)) != 0) {
//        cout << "NO" << endl;
//        return;
//    }
//
//    reverse(x.begin(), x.end());
//    x.push_back(0);
//    x.push_back(0);
//
//    vector<long long> y(1);
//    y[0] = ((1 - x[0]) % (B - 1) + B - 1) % (B - 1);
//    vector<long long> z(1);
//    z[0] = (x[0] + y[0]) % B;
//    int carry = (x[0] + y[0] >= B);
//
//    for (int i = 1; i < N + 2; ++i) {
//        y.push_back((((y[i - 1] - x[i] - carry) % B) + B) % B);
//        z.push_back(y[i - 1]);
//        carry = (x[i] + y[i] + carry >= B);
//    }
//
//    y.push_back(1);
//    z.push_back(1);
//
//    cout << "YES" << "\n";
//    cout << N + 3 << "\n";
//
//    for (auto it = y.rbegin(); it != y.rend(); ++it) {
//        cout << *(it) << " ";
//    }
//    cout << "\n";
//
//    for (auto it = z.rbegin(); it != z.rend(); ++it) {
//        cout << *(it) << " ";
//    }
//    cout << "\n";
//}
//
//int main() {
//    setIO();
//
//    int test_case_number = 1;
//    cin >> test_case_number;
//    while (test_case_number--) {
//        test_case();
//    }
//    return 0;
//}


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
    long long N, B;
    cin >> N >> B;
    long long sum = 0;
    vector<long long> x(N);
    for (long long i = 0; i < N; ++i) {
        cin >> x[i];
        sum += x[i];
    }
    if ((sum % (B - 1)) != 0) {
        cout << "NO" << endl;
        return;
    }

    reverse(x.begin(), x.end());
    x.push_back(0);
    x.push_back(0);

    vector<long long> y(1);
    y[0] = ((1 - x[0]) % (B) + B) % (B);
    vector<long long> z(1);
    z[0] = (x[0] + y[0]) % B;
    int carry = (x[0] + y[0] >= B);

    for (int i = 1; i < N + 2; ++i) {
        y.push_back((((y[i - 1] - x[i] - carry) % B) + B) % B);
        z.push_back(y[i - 1]);
        carry = (x[i] + y[i] + carry >= B);
    }

    y.push_back(1);
    z.push_back(1);

    cout << "YES" << "\n";
    cout << N + 3 << "\n";

    for (auto it = y.rbegin(); it != y.rend(); ++it) {
        cout << *(it) << " ";
    }
    cout << "\n";

    for (auto it = z.rbegin(); it != z.rend(); ++it) {
        cout << *(it) << " ";
    }
    cout << "\n";
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

//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include <vector>
#include <map>
#include <numeric>
#include <random>
#include <chrono>


using namespace std;

#define rep(i, a, b)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

long long counter = 0;

ull modmul_kactl_1(ull a, ull b, ull M) {
    ll ret = a * b - M * ull(1.L / M * a * b);
    return ret + M * (ret < 0) - M * (ret >= (ll) M);
}

typedef uint64_t u64;
typedef int64_t i64;
typedef long double ld;

u64 modmul_kactl_2(u64 a, u64 b, u64 c) {
    i64 ret = a * b - c * u64(ld(a) * ld(b) / ld(c));
    return ret + c * (ret < 0) - c * (ret >= (i64) c);
}

ull modmul_128(ull a, ull b, ull M) {
    return ((__int128) a * b) % M;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ull rnd(ull l, ull r) { // [l, r]
    return uniform_int_distribution<ull>(l, r)(rng);
}


int main() {
    int trials = 10000000;
    int wrong = 0;
    for (int _ = 0; _ < trials; ++_) {
        ull mx = 1e14;
        ull M = rnd(2, mx), a = rnd(1, M - 1), b = rnd(1, M - 1);
        if (modmul_kactl_2(a, b, M) != modmul_128(a, b, M)) {
            ++wrong;
//            cout << a << " " << b << " " << M << "\n";
//            cout << "kactl: " << modmul_kactl_2(a, b, M) << "\n";
//            cout << "128: " << modmul_128(a, b, M) << "\n";
//            return 0;
        }
    }
    cout << (long double) wrong / trials << "\n";
}

////#include<bits/stdc++.h>
//#include<iostream>
//#include<algorithm>
//#include <vector>
//#include <map>
//#include <numeric>
//#include <random>
//#include <chrono>
//
//
//using namespace std;
//
//#define rep(i, a, b)
//#define all(x) begin(x), end(x)
//#define sz(x) (int) (x).size()
//typedef long long ll;
//typedef unsigned long long ull;
//typedef pair<int, int> pii;
//typedef vector<int> vi;
//
//long long counter = 0;
//
//ull modmul_kactl(ull a, ull b, ull M) {
//    ll ret = a * b - M * ull(1.L / M * a * b);
//    return ret + M * (ret < 0) - M * (ret >= (ll) M);
//}
//
//ull modmul_128(ull a, ull b, ull M) {
//    return ((__int128) a * b) % M;
//}
//
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//
//ull rnd(ull l, ull r) { // [l, r]
//    return uniform_int_distribution<ull>(l, r)(rng);
//}
//
//
//int main() {
//    cin.tie(0)->sync_with_stdio(0);
//    cin.exceptions(cin.failbit);
//    int trials = 10000;
//    int wrong = 0;
//    for (int _ = 0; _ < trials; ++_) {
//        ull mx = 1e18;
//        ull a = rnd(1, mx), b = rnd(1, mx), M = rnd(1, mx);
//        if (modmul_kactl(a, b, M) != modmul_128(a, b, M)) {
//            ++wrong;
////            cout << a << " " << b << " " << M << "\n";
////            cout << "kactl: " << modmul_kactl(a, b, M) << "\n";
////            cout << "128: " << modmul_128(a, b, M) << "\n";
////            return 0;
//        }
//    }
//    cout << (long double) wrong / trials << "\n";
//}
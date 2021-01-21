//#include <bits/stdc++.h>
//
//using namespace std;
//
//void setIO() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//#ifdef DEBUG
//    //freopen("solution.out", "w", stdout);
//    freopen("1.in", "r", stdin);
//#endif
//}
//
//
//int main() {
//    setIO();
//
//    int t;
//    cin >> t;
//    while (t--) {
//        int n, k;
//        cin >> n >> k;
//        vector<int> a(n);
//        for (int i = 0; i < n; ++i) {
//            cin >> a[i];
//        }
//        for (int i = 0; i < n; ++i) {
//            string binary = bitset<>(a[i]).to_string(); //to binary
//            cout << i << " " << binary << "\n";
//        }
//    }
//    return 0;
//}

// Solved with python

//for _ in range(int(input())):
//    n, k = map(int, input().split())
//    a = [int(i) for i in input().split()]
//    values = {i: 0 for i in range(35)}
//    for i in a:
//        num = str(bin(i))[2:]
//        s = len(num) - 1
//        # print(num)
//        for j in num:
//            # print(values)
//            if (s in values):
//                if (j == "1"):
//                    values[s] += 1
//            s -= 1
//    for i in values:
//        values[i] = (2 ** i * values[i])
//    sol = 0
//    # print(values)
//    new_values = sorted(values, key = values.get, reverse = True)
//    # print(values, new_values)
//    for i in range(len(values)):
//        # print(w)
//        if (i >= k):
//            break
//
//        sol += 2 ** new_values[i]
//    print(sol)
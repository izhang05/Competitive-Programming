#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int main() {
    srand(time(nullptr));
//    vector<string> s{"01", "02", "03", "04", "05", "06", "07", "08", "09", "10"};
    vector<string> s{"10"};

    for (auto &i: s) {
        system(("./ICPC_Challenge2025A2 < tests/" + i + " > output/" + i + ".out").c_str());
    }
}

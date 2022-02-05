#include <bits/stdc++.h>

using namespace std;


int main() {
//    system("g++ -std=c++17 -O2 pizza.cpp -o pizza");
    for (int i = 1; i < 5; ++i) {
        string input = "input_data/in";
        input += to_string(i);
        input += ".txt";
        string output = "output_data/out";
        output += to_string(i);
        output += ".txt";
        system(("./pizza < " + input + "> " + output).c_str());
    }
}
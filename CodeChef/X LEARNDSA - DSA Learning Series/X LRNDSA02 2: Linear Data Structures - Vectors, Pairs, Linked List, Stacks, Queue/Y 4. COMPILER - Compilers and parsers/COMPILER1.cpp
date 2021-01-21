#include <iostream>
#include <stack>

using namespace std;

int main() {
    int t, solution;
    string expression;
    cin >> t;
    while (t--) {
        cin >> expression;
        solution = 0;
        stack<int> parser;
        if (expression[0] == '<') {
            for (int i = 0; i < expression.length(); ++i) {
                if (expression[i] == '<') {
                    parser.push(0);
                } else {
                    if (parser.empty()) {
                        break;
                    }
                    parser.pop();
                }
                if (parser.empty()) {
                    solution = i + 1;
                }
            }
        }
        cout << solution << "\n";
    }
    return 0;
}
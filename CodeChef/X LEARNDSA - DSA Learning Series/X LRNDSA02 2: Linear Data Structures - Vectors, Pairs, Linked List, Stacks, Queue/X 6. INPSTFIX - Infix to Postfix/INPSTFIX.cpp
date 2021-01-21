#include <iostream>
#include <unordered_set>
#include <stack>

using namespace std;

int main() {
//    freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
    unordered_set<char> operators_list = {'+', '-', '*', '/', '^'};
    int t, n;
    stack<char> operators, variables;
    string expression, solution;
    char previous_operator, previous_var;
    cin >> t;
    while (t--) {
        solution = "";
        operators = {};
        variables = {};
        cin >> n;
        cin >> expression;
        //    first completely parenthesize the expression
        int k;
        if (isalpha(expression[0])) {
            previous_var = expression[0];
            previous_operator = expression[1];
            variables.push(previous_var);
            operators.push(previous_operator);
            k = 2;
        } else {
            k = 0;
            while (!isalpha(expression[k])) {
                previous_operator = expression[k];
                operators.push(previous_operator);
                ++k;
            }
            previous_var = expression[k];
            variables.push(previous_var);
            ++k;
        }
        expression.erase(0, k);
        for (char i : expression) {
            if (!isalpha(i)) {
                if (i == ')') {
                    operators.pop();
                } else {
                    operators.push(i);
                }
                previous_operator = i;
            } else {
                if (operators_list.count(previous_operator)) {
                    cout << variables.top() << "\n";
                    if (!variables.empty()) {
                        solution += variables.top();
                        variables.pop();
                    }
                    cout << variables.top() << endl;
                    solution += i;
                    solution += operators.top();
                    operators.pop();
                } else {
                    variables.push(i);
                }
                previous_var = i;
            }
        }
        solution += operators.top();
        operators.pop();
        cout << solution << "\n";
    }

    return 0;
}
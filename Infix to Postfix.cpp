// problem statement: Given an infix expression, Your task is to convert the given infix expression to a postfix expression
// theory: 
//Approach to Convert Infix Expression to Postfix:
//1. Start by scanning the infix expression from left to right.
//2. If the scanned character is an operand, print it immediately.
//3. If the scanned character is an operator:
  //    a. If the precedence of the operator is greater than the operator in the stack, or the stack is empty, or the stack contains a ‘(’, push the operator into the stack.
   //   b. Otherwise, pop all operators from the stack with higher or equal precedence than the scanned operator, then push the scanned operator into the stack.
//4. If the scanned character is a ‘(’, push it into the stack.
//5. If the scanned character is a ‘)’, pop the stack and output the operators until a ‘(’ is encountered, and discard both parentheses.
//6. Repeat steps 2-5 until the entire infix expression has been scanned.
//7. Print the output.
//8. Finally, pop and print all remaining operators in the stack until it is empty.

// solution:

// Function to return precedence of operators
int prec(char c) {
    if (c == '^')  // Exponent operator has highest precedence
        return 3;
    else if (c == '/' || c == '*')  // Multiplication and division have higher precedence than addition
        return 2;
    else if (c == '+' || c == '-')  // Addition and subtraction have lowest precedence
        return 1;
    else
        return -1;
}

// The main function to convert infix expression to postfix expression
void infixToPostfix(string s) {
    stack<char> st; // Stack to hold operators and parentheses
    string result;  // String to hold the resulting postfix expression

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        // If the scanned character is an operand, add it to the result string
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;

        // If the scanned character is an ‘(‘, push it to the stack
        else if (c == '(')
            st.push('(');

        // If the scanned character is a ‘)’, pop from stack until an ‘(‘ is encountered
        else if (c == ')') {
            while (st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop();  // Pop the ‘(‘ from the stack
        }

        // If an operator is scanned
        else {
            while (!st.empty() && prec(s[i]) <= prec(st.top())) {
                result += st.top();
                st.pop();
            }
            st.push(c);  // Push the current operator to the stack
        }
    }

    // Pop all the remaining elements from the stack
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    cout << "Postfix expression: " << result << endl;  // Output the result
}
// Time complexity:  O(N), where N is the length of the infix expression. Each character in the expression is processed once.
//Space Complexity: O(N), where N is the length of the infix expression. The stack can hold at most N operators and parentheses in the worst case.

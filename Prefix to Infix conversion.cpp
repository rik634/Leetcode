// problem statement:  You are given a valid arithmetic expression in prefix notation. Your task is to convert it into a fully parenthesized infix expression.
//Prefix notation (also known as Polish notation) places the operator before its operands. In contrast, infix notation places the operator between operands.
//Your goal is to convert the prefix expression into a valid fully parenthesized infix expression.

// steps:
//1. Traverse the prefix expression from right to left.
// 2. Use a stack to store operands.
// 3. For each operator, pop two operands from the stack, wrap them in parentheses, and push the resulting expression back.
// 4. The final item in the stack will be the infix expression.

// solution: 

// Function to convert prefix to infix
string prefixToInfix(string prefix) {
    stack<string> s;
    int n = prefix.size();

    // Traverse the prefix expression from right to left
    for (int i = n - 1; i >= 0; i--) {
        char c = prefix[i];

        // If the character is an operand, push it to the stack
        if (isalnum(c)) {
            s.push(string(1, c));
        } else {
            // Pop two operands from the stack
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();

            // Form the new infix expression and push back to stack
            s.push("(" + op1 + c + op2 + ")");
        }
    }

    // The final element in the stack is the result
    return s.top();
}
// Time complexity: O(n) where n is the length of the prefix expression (only one pass).
// space complexity: O(n) for the stack used to store operands.

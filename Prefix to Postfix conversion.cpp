// problem statemen: You are given a valid prefix expression consisting of binary operators and single-character operands. Your task is to convert it into a valid postfix expression.
//Prefix (Polish) notation places the operator before operands.
//Postfix (Reverse Polish) notation places the operator after operands.

// steps: 
// 1. Traverse the prefix expression from right to left.
// 2. Use a stack to store operands.
// 3. For each operator, pop two operands from the stack, combine them with the operator, and push the result back.
// 4. The final item in the stack will be the postfix expression.

// solutIon
// Function to convert prefix to postfix
string prefixToPostfix(string prefix) {
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

            // Form the new postfix expression and push back to stack
            s.push(op1 + op2 + c);
        }
    }

    // The final element in the stack is the result
    return s.top();
}
// time complexity:  O(n), single pass through the expression.
// space complexity:  O(n), stack space for storing intermediate results.

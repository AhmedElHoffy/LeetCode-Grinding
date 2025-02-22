class Solution {
private:
    bool Is_Digit(char ch){
        return (ch>='0' && ch<='9');
    }
    bool Is_Operator(char ch){
        return (ch=='*' || ch=='/' || ch=='+' || ch=='-');
    }

    bool Is_Higher_Precedence(char ch1, char ch2){
        return ( (ch1=='*' || ch1=='/') && (ch2=='+' || ch2=='-') );
    }
     
    int Convert_String2Num(string Digits){
        int Num=0;
        for(char ch : Digits){
            Num = Num*10 + (ch -'0'); 
        }
        return Num;
     }
     int Operation_Eval(int num1, int num2, char Operator){
        int num3;
        if(Operator =='*'){
            num3 = num1 * num2;
        }else if(Operator=='/'){
            num3 = num1 / num2;
        }else if(Operator=='+'){
            num3 = num1 + num2;
        }else{
            num3 = num1 - num2;
        }
        return num3;
     }
public:
    int calculate(string Str) {
         stack<int> Nums_Stk;
        stack<char> Operators_Stk;
        string num = "";
        int op1, op2, Curr_Cal;
        char Operator;

        for (int i = 0; i < Str.size(); i++) {
            char ch = Str[i];

            if (Is_Digit(ch)) {
                num += ch;
            }

            if (Is_Operator(ch) || i == Str.size() - 1) { // Operator or last number
                if (!num.empty()) {
                    Nums_Stk.push(Convert_String2Num(num));
                    num = "";
                }

                while (!Operators_Stk.empty() && !Is_Higher_Precedence(ch, Operators_Stk.top())) {
                    op2 = Nums_Stk.top();
                    Nums_Stk.pop();
                    op1 = Nums_Stk.top();
                    Nums_Stk.pop();
                    Operator = Operators_Stk.top();
                    Operators_Stk.pop();
                    Curr_Cal = Operation_Eval(op1, op2, Operator);
                    Nums_Stk.push(Curr_Cal);
                }

                if (i < Str.size() - 1) {
                    Operators_Stk.push(ch);
                }
            }
        }
         // Process remaining operators
        while (!Operators_Stk.empty()) {
            op2 = Nums_Stk.top();
            Nums_Stk.pop();
            op1 = Nums_Stk.top();
            Nums_Stk.pop();
            Operator = Operators_Stk.top();
            Operators_Stk.pop();
            Curr_Cal = Operation_Eval(op1, op2, Operator);
            Nums_Stk.push(Curr_Cal);
        }
        return Nums_Stk.top();
    }
};













/*

class Solution {
public:
    bool IsDigit(const char &c) {
        return (c >= '0' && c <= '9');
    }
    bool IsOperator_LowPriority(const char &c) {
        return (c == '+' || c == '-');
    }
    bool IsSpace(const char &c) {
        return (c == ' ');
    }

    int calculate(string s) {
        stack<int> nums; // Stack to store numbers
        stack<char> ops; // Stack to store operators
        int n = s.length();
        int num = 0;
        char prevOp = '+'; // Default operator for the first number

        for (int i = 0; i < n; ++i) {
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0'); // Parse the number
            }

            if ((!isdigit(s[i]) && !isspace(s[i])) || i == n - 1) {
                if (prevOp == '+') {
                    nums.push(num);
                } else if (prevOp == '-') {
                    nums.push(-num);
                } else if (prevOp == '*') {
                    int top = nums.top();
                    nums.pop();
                    nums.push(top * num);
                } else if (prevOp == '/') {
                    int top = nums.top();
                    nums.pop();
                    nums.push(top / num);
                }
                prevOp = s[i]; // Update the operator
                num = 0;       // Reset the number
            }
        }

        // Evaluate the remaining operations
        int result = 0;
        while (!nums.empty()) {
            result += nums.top();
            nums.pop();
        }
        return result;
    }
};

*/












/*

class Solution {
public:
    bool IsDigit(const char &c) {
        return (c >= '0' && c <= '9');
    }
    bool IsOperator_LowPriority(const char &c) {
        return (c == '+' || c == '-');
    }
    bool IsSpace(const char &c) {
        return (c == ' ');
    }

    int calculate(string s) {
        stack<int> nums; // Stack to store numbers
        stack<char> ops; // Stack to store operators
        int n = s.length();
        int num = 0;
        char prevOp = '+'; // Default operator for the first number

        for (int i = 0; i < n; ++i) {
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0'); // Parse the number
            }

            if ((!isdigit(s[i]) && !isspace(s[i])) || i == n - 1) {
                if (prevOp == '+') {
                    nums.push(num);
                } else if (prevOp == '-') {
                    nums.push(-num);
                } else if (prevOp == '*') {
                    int top = nums.top();
                    nums.pop();
                    nums.push(top * num);
                } else if (prevOp == '/') {
                    int top = nums.top();
                    nums.pop();
                    nums.push(top / num);
                }
                prevOp = s[i]; // Update the operator
                num = 0;       // Reset the number
            }
        }

        // Evaluate the remaining operations
        int result = 0;
        while (!nums.empty()) {
            result += nums.top();
            nums.pop();
        }
        return result;
    }
};

*/
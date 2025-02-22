class Solution {
public:
    string minRemoveToMakeValid(string Str) {
        int n = Str.length();
        stack<pair<char,int>>Parentheses_Stk;
        unordered_set<int>InValid_Parentheses_Set;
        for(int i = 0 ; i < n ; i++){
            if(Str[i]=='('){
                Parentheses_Stk.push({Str[i],i});
            }else if(Str[i]==')'){
                if(Parentheses_Stk.empty()){
                    Parentheses_Stk.push({Str[i],i});
                }else{
                    if(Parentheses_Stk.top().first=='('){
                        Parentheses_Stk.pop();
                    }else{
                        Parentheses_Stk.push({Str[i],i});
                    }
                }
            }
            
        }
        while(!Parentheses_Stk.empty()){
                auto[ch, Index] = Parentheses_Stk.top();
                Parentheses_Stk.pop();
                InValid_Parentheses_Set.insert(Index);
        }
        string Result;
        
        for(int i=0; i < n ; i++){
            if(InValid_Parentheses_Set.find(i)==InValid_Parentheses_Set.end()){
                    Result+=Str[i];
            }
        }
        return Result;
    }
};
















/*
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        int balance = 0;

        // First Pass: Remove invalid ')'
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                balance++;
            } else if (s[i] == ')') {
                if (balance == 0) {
                    s[i] = '*'; // Mark invalid ')'
                } else {
                    balance--; // Valid ')'
                }
            }
        }

        // Second Pass: Remove invalid '('
        balance = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ')') {
                balance++;
            } else if (s[i] == '(') {
                if (balance == 0) {
                    s[i] = '*'; // Mark invalid '('
                } else {
                    balance--; // Valid '('
                }
            }
        }

        // Third Pass: Build the result in-place
        int writeIndex = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != '*') {
                s[writeIndex++] = s[i];
            }
        }

        // Resize the string to exclude removed characters
        s.resize(writeIndex);
        return s;
    }
};

*/
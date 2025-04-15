class Solution {
public:
    string minRemoveToMakeValid(string Str) {
        int n = Str.size();
        stack<pair<char,int>>Stk_Paren;

        for (int i = 0; i < n; i++) {
        if (Str[i] == '(') {
            Stk_Paren.push({'(', i});
        } else if (Str[i] == ')') {
            if (!Stk_Paren.empty() && Stk_Paren.top().first == '(') {
                Stk_Paren.pop();
            } else {
                Stk_Paren.push({')', i});
            }
        }
        // Skip all other characters
    }

        unordered_set<int>Un_Valid_Idx;
        while(!Stk_Paren.empty()){
            Un_Valid_Idx.insert(Stk_Paren.top().second);
            Stk_Paren.pop();
        }
        string Result="";

        for(int j=0 ; j<n ; j++){
            if(!Un_Valid_Idx.count(j)){
                Result+=Str[j];
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
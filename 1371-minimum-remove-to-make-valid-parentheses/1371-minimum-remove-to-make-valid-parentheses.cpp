class Solution {
public:
    string minRemoveToMakeValid(string Str) {
        int n = Str.size();
        stack<pair<char,int>>Stk;
        for(int i=0; i<n ; i++){
            if(Str[i]==')'){
                if(!Stk.empty() && Stk.top().first=='('){
                    Stk.pop();
                }else{
                    Stk.push({Str[i],i}); // <-- this line was wrongly placed in your code
                }
            }else if(Str[i]=='('){
                Stk.push({Str[i],i});
            }
        }

        if(Stk.empty()){
            return Str;
        }

        unordered_set<int>Un_Valid_Paren_Idx;
        while(!Stk.empty()){
            Un_Valid_Paren_Idx.insert(Stk.top().second);
            Stk.pop();
        }
        string Result="";
        for(int j=0 ; j<n ; j++){
            if(Un_Valid_Paren_Idx.find(j)==Un_Valid_Paren_Idx.end()){
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
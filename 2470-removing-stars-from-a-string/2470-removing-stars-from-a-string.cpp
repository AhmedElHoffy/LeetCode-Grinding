class Solution {
public:
    string removeStars(string &Str) {
        int n = Str.size();
        stack<int>Asterick_Stk;

        for(int i=0 ; i<n ; i++){
            if(Str[i]=='*'){
                Asterick_Stk.push(i);
            }
        }
        if(Asterick_Stk.empty()){
            return Str;
        }

        stack<char>Chars_Stk;

        for(char Ch : Str){
            if(Ch!='*'){
                Chars_Stk.push(Ch);
            }else if(!Chars_Stk.empty()){
                Chars_Stk.pop();
            }
        }

        string Result="";
        while(!Chars_Stk.empty()){
            Result = Chars_Stk.top() + Result;
            Chars_Stk.pop();
        }
        return Result;
    }
};












/*

stack<char>Stk;
        string Result="";
        for(char c : s){
            if(c!='*'){
                Stk.push(c);
            }else if( !Stk.empty() && c=='*'){
                Stk.pop();
            }
        }
        while(!Stk.empty()){
            Result = Stk.top() + Result;
            Stk.pop();
        }
        return Result;
*/

























/*
class Solution {
public:
    string removeStars(string s) {

        // this code is not memory efficeint because we keep copying Result string
       // string Result="";
        //stack<char>Chars_Stack;
        //for(char c : s){
          //  if(c!='*'){
            //    Chars_Stack.push(c);
            //}else{
              //  Chars_Stack.pop();
            //} 
        //}
        
        //while(!Chars_Stack.empty()){
          //  Result = Chars_Stack.top() + Result ;
            // Chars_Stack.pop();
       // }
        //return Result;
        

        // instead we can use the string Result as stack already

         string result; // Use this directly as a "stack"
        
        for (char c : s) {
            if (c != '*') {
                result.push_back(c); // Append non-star characters
            } else {
                result.pop_back();   // Remove the last character
            }
        }
        
        return result;
    }
};

*/
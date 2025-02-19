class Solution {
public:
    string removeStars(string &s) {
         int index = 0; 

         for(char c : s){
            if(c!='*'){
                s[index++]=c;
                
            }else{
                index--;
            }
         }
         s.resize(index);
         return s;
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
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>Stk;

        int counter=0;
        for( int ch :s){
            if(ch=='('){
                Stk.push(ch);
            }else if( ch==')'){
                if(!Stk.empty()){
                    Stk.pop();
                }else{
                    counter++;
                }
            }
        }
        while(!Stk.empty()){
            counter++;
            Stk.pop();
        }
        return counter;
    }
};
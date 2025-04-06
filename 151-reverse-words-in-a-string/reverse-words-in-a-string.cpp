class Solution {
private: 
    
    void Swap_Chars(char &a, char &b){
        char temp = a;
             a = b;
             b = temp;
    } 

    void Reverse_Str(string &Str){
        int n = Str.length();
        int Left_Ptr=0, Right_Ptr=n-1;
        
        while(Left_Ptr < Right_Ptr){
            Swap_Chars(Str[Left_Ptr++],Str[Right_Ptr--]);
        }
    }

    void Reverse_Word(int Left_Ptr, int Right_Ptr, string &Str){
        while(Left_Ptr < Right_Ptr){
            Swap_Chars(Str[Left_Ptr++],Str[Right_Ptr--]);
        }
    }

    void Trim_Spaces(string &Str){
        // Remove leading space(s)
        while (!Str.empty() && Str.front() == ' ') {
         Str.erase(0, 1);
        }

        // Remove trailing space(s)
        while (!Str.empty() && Str.back() == ' ') {
            Str.pop_back();
        }
        int n = Str.length();
         // Remove multiple spaces between words
        for (int i = 0; i < (int)Str.size() - 1; ) {
            if (Str[i] == ' ' && Str[i + 1] == ' ') {
                Str.erase(i, 1);  // Remove the current space
                // Do not increment i because characters shift left
            } else {
                i++;  // Safe to move forward
            }
        }
    }

public:
    string reverseWords(string Str) {
        int Str_Len = Str.length();
        Reverse_Str(Str);
        
        int Running_Ptr=0;
        int Word_Start_Idx, Word_End_Idx;

        while(Running_Ptr < Str_Len){
            if(Str[Running_Ptr]!=' '){
                Word_Start_Idx = Running_Ptr;
                Word_End_Idx = Word_Start_Idx;
                while(Word_End_Idx < Str_Len && Str[Word_End_Idx]!=' '){
                    Word_End_Idx++;
                }
                Reverse_Word(Word_Start_Idx,Word_End_Idx-1,Str);
                Running_Ptr = Word_End_Idx;
            }
            Running_Ptr++;
        }
        Trim_Spaces(Str);
        return Str;
    }
};















/*
string reverseWords(string Str) {
       int Str_length = Str.size();
       int LeftPtr=0;
       int WordstartIdx, WordEndIdx;
       string Result = "";
       while(LeftPtr < Str_length){
        // get the  Index at start of the detected word
        WordstartIdx = LeftPtr;
        while(WordstartIdx < Str_length && Str[WordstartIdx]==' '){
            WordstartIdx++;
        }
        if(WordstartIdx>=Str_length)break;
        // Getting the end index of the detected word
        WordEndIdx = WordstartIdx + 1;
        while(WordEndIdx < Str_length && Str[WordEndIdx]!=' '){
            WordEndIdx++;
        }
        string Word = Str.substr(WordstartIdx,WordEndIdx - WordstartIdx);
        if(Result.size()==0 ){
            Result = Word;
        }else{

            Result = Word + " " + Result;
        }
        LeftPtr = WordEndIdx + 1;
       }
        return Result;
    }
    */




    // Time : O(n) ;  Space: O(n)
    /*
    string reverseWords(string Str) {
        stack<char> Chars_Stk;
        string Curr_Word="";
        string Result="";
        char Curr_Char;

        for( char Ch : Str){
            Chars_Stk.push(Ch);
        }

        while(!Chars_Stk.empty()){
            Curr_Char = Chars_Stk.top();

            if(Curr_Char!=' '){
                Curr_Word = Curr_Char + Curr_Word;
            }else{
                if(!Curr_Word.empty()){
                    Result = Result + Curr_Word + " ";
                    Curr_Word="";
                }
            }
            Chars_Stk.pop();
        }
        if(!Curr_Word.empty()){
            Result = Result + Curr_Word;
        }

        if(!Result.empty() && Result.back()==' '){
            Result.pop_back();
        }
        return Result;

    }

    */
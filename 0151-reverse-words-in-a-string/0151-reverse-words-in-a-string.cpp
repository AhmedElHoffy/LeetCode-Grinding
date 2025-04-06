class Solution {
public:
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
                    Result = Result +Curr_Word + " ";
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
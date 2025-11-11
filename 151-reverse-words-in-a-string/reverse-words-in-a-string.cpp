class Solution {
public:
    string reverseWords(string Str) {
        stack<string>Stk_Words;
        string Curr_Word;

        for (char Ch : Str){
            if(Ch !=' '){
                Curr_Word += Ch;
            }else if(!Curr_Word.empty()){
                Stk_Words.push(Curr_Word);
                Curr_Word.clear();
            }
        }

        // Add Last Word
        if(!Curr_Word.empty()){
            Stk_Words.push(Curr_Word);
        }

        string Result;

        while(!Stk_Words.empty()){
            if(!Result.empty()) Result += ' '; // Add Space
            Result+= Stk_Words.top();
            Stk_Words.pop();
        }
        return Result;
    }
};
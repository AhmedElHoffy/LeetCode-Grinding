class Solution {
public:
    string reverseWords(string Str) {
        int Str_Size = Str.size();
        stack<char>Word_Stk;
        int j=Str_Size-1;
        string Result="";
        bool firstWord = true; // To handle spaces correctly
        while(j>=0){
            while(j>=0 && Str[j]==' '){
                j--;
            }
            if (j < 0) break; // If no more words, stop
            
            while( j>=0 && Str[j]!=' '){ // Word Detected 
                Word_Stk.push(Str[j]);
                cout<<"Letter: "<<Str[j]<<" Detected"<<endl;
                j--;
                
            }
            cout<<endl;
            // Out of loop (word Captured)

            if (!firstWord ) {
                Result += " "; // Add space between words
            }
            while(!Word_Stk.empty()){
                Result.push_back(Word_Stk.top());
                cout<<" Letter: "<<Word_Stk.top()<<" Popped from Word_Stk"<<endl;
                Word_Stk.pop();
            }
            cout<<endl;
            cout<<"Result String now is = "<<Result<<endl<<endl;
            firstWord = false;
            j--;
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
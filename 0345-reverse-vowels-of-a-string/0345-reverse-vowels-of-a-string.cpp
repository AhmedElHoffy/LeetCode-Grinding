class Solution {
private:
    bool Vowel_Check(char c) {
        if (c == 'A' || c == 'a' || c == 'E' || c == 'e' ||
            c == 'I' || c == 'i' || c == 'O' || c == 'o' ||
            c == 'U' || c == 'u') {
            return true;
        }
        return false;
    }

    void swap(char &c1, char &c2){
        char temp = c1;
             c1 = c2;
             c2=temp;
    }

public:
    string reverseVowels(string Str) {
    int Str_Size= Str.size();
    vector<int>Vowels_Idx;
    for(int i=0 ; i < Str_Size ; i++){
        if(Vowel_Check(Str[i])){
            Vowels_Idx.push_back(i);
        }
    }
    string Result = Str;
    int ptr1=0,ptr2=Vowels_Idx.size()-1;
    while(ptr1<ptr2){
        swap(Result[Vowels_Idx[ptr1]],Result[Vowels_Idx[ptr2]]);
        ptr1++;
        ptr2--;
    }
    return Result;
    }
};


























/*    bool Vowel_Letter(char c){
        if(c =='a' ||c =='A' || c=='E' || c=='e' || c=='O' || c=='o' || c=='U' || c=='u' || c=='i' || c=='I'){
            return true;
        }else{
            return false;
        }
    }
    void swap_char(char &c1, char &c2){
        char temp = c1;
        c1 = c2;
        c2 = temp;
    }
    string reverseVowels(string s) {
        int size_str = s.size();
        int left = 0;
        int right = size_str-1;
        string Result = s;
        while(left < right){
            if(Vowel_Letter(Result[left])){
                while(!Vowel_Letter(Result[right])){
                    right--;
                }
                swap_char(Result[left],Result[right]);
                right--;
            }
            left++;
        }

       return Result;
    }
*/
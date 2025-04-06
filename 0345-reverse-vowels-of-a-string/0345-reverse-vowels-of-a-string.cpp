class Solution {
private:

    bool Vowel_Detect_Fn(char ch){
        if(ch == 'A' || ch == 'a' || ch == 'E' || ch == 'e'||
           ch == 'I' || ch == 'i' || ch == 'O' || ch == 'o' || 
           ch == 'U' || ch == 'u'){
            return true;
           }
           return false;
    }

    void Swap_Chars(char &a, char &b){
        char temp = a;
        a = b;
        b = temp;
    }

public:
    string reverseVowels(string &Str) {
       int n = Str.size();

       int Left_Ptr = 0, Right_Ptr=n-1;

       while(Left_Ptr < Right_Ptr){

         while(Left_Ptr < Right_Ptr  && !Vowel_Detect_Fn(Str[Left_Ptr])){
            Left_Ptr++;
         }

        while(Left_Ptr < Right_Ptr  && !Vowel_Detect_Fn(Str[Right_Ptr])){
            Right_Ptr--;
         }

         if(Left_Ptr < Right_Ptr){
            Swap_Chars(Str[Left_Ptr] , Str[Right_Ptr]);
            Left_Ptr++;
            Right_Ptr--;
         }

       }

       return Str;
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
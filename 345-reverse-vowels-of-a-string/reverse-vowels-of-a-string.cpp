class Solution {
public:
    bool isVowel(char ch){
        if(ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'i' || ch == 'I'
           || ch == 'o' || ch == 'O' || ch == 'u' || ch == 'U'){
            return true;
           }
           return false;
    }

    void Swap_Ch(char &a , char &b){
        char temp = a;
        a =b;
        b = temp;
    }
    string reverseVowels(string &str) {
        int n = str.size();
        int i=0 , j = n-1;

        while( i< j){
            while (i < j && !isVowel(str[i])) ++i;
            while (i < j && !isVowel(str[j])) --j;
            if (i < j) {                  // re-check before touching str[i], str[j]
                Swap_Ch(str[i], str[j]);   // or std::swap(str[i], str[j])
                ++i; --j;
            }
        }
        return str;
    }
};
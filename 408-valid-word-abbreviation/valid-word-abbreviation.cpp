class Solution {
private:
    int Str2Num(string Num){
        int Res=0;
        for(char Ch : Num){
            Res = (Res*10) + (Ch -'0');
        }
        return Res;
    }

    bool is_Digit(char ch){
        return (ch>='0' && ch<='9');
    }

public:
    bool validWordAbbreviation(string word, string abbr) {
        int n1 = word.size(), n2 = abbr.size();

        int Ptr_W = 0 , Ptr_abbr = 0;
        int Curr_Dup=0;
        string Num_Str="";
        while(Ptr_W<n1  &&  Ptr_abbr<n2){
           
            

            // Check Leading Zero
            if(is_Digit(abbr[Ptr_abbr])){
                if(abbr[Ptr_abbr]=='0') return false;
                 Num_Str="";
                Curr_Dup=0;
        
            while(Ptr_abbr<n2 && is_Digit(abbr[Ptr_abbr])){
                Num_Str+=abbr[Ptr_abbr];
                Ptr_abbr++;
            }
            Curr_Dup=Str2Num(Num_Str);
            Ptr_W+=Curr_Dup;
            }else {
                if(word[Ptr_W] != abbr[Ptr_abbr]) return false;
                Ptr_W++;
                Ptr_abbr++;
            }
        }
        return ( ( (Ptr_W==n1) && (Ptr_abbr==n2) ) ? true:false );
    }
};




























/*

class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int n1=word.size();
        int n2 = abbr.size();
        int ptr_1=0,ptr_2=0;
        int digit=0;


        // My attempt (not handling edge cases (Leading Zeros, Ptr_1 exceeds word string length and checking boundary  
        // cases efficiently ))
        
        while(ptr_1< n1 && ptr_2<n2){
            if(n1==1 && n2==1){
                return word[0]==abbr[0];
            }
            while(abbr[ptr_2]>='0' && abbr[ptr_2]<='9'){
                digit= digit*10 + (abbr[ptr_2] - '0');
                ptr_2++;
                count++;
            }
            //leading zeros check
            if(digit>0 &&  digit<9 && count>1){
                return false;
            }
            if(digit>0){
                ptr_1+=digit;
                digit=0; //reset digit;
                count=0; // reset digits count
            }
            if(word[ptr_1]!=abbr[ptr_2]){
                return false;
            }
            ptr_1++;
            ptr_2++;
        }
        return true;
        /////////////////////////////////////

         while (ptr_2 < n2) {
            if (isdigit(abbr[ptr_2])) {
                if (abbr[ptr_2] == '0' && digit == 0) {
                    // Leading zero is not allowed
                    return false;
                }
                // Accumulate digits
                digit = digit * 10 + (abbr[ptr_2] - '0');
                ptr_2++;
            } else {
                if (digit > 0) {
                    // Skip the characters in `word` based on `digit`
                    ptr_1 += digit;
                    digit = 0; // Reset digit

                    if (ptr_1 > n1) {
                        // If pointer exceeds word length, invalid abbreviation
                        return false;
                    }
                }
                // Check character match
                if (ptr_1 >= n1 || word[ptr_1] != abbr[ptr_2]) {
                    return false;
                }
                ptr_1++;
                ptr_2++;
            }
        }

        // After the loop, apply any remaining digit
        if (digit > 0) {
            ptr_1 += digit;
        }

        // Both pointers should reach the end for a valid abbreviation
        return ptr_1 == n1;    
        
    }
};
*/
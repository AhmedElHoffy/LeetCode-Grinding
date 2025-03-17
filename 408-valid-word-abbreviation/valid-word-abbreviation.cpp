class Solution {
private:
    
    bool Char_Check( char a){
        return (a>='a' && a<='z');
    }
    
    int Convert_StrDigit2Num(string Digits){
        int Num=0;
        for(char Digit : Digits){
            Num = Num*10 + (Digit -'0');
        }
        return Num;
    }
    
    bool Is_Digit(char ch){
        return (ch>='0' && ch<='9');
    }

public:
    bool validWordAbbreviation(string word, string abbr) {
        int n = word.length(), m = abbr.length();        
        int Ptr_w=0, Ptr_abbr=0;
        string Digits="";
        int Abbr_Num=0;
        while(Ptr_abbr < m && Ptr_w < n){
            if(Is_Digit(abbr[Ptr_abbr])){
                
                //Check Leading Zeros
                if(abbr[Ptr_abbr]=='0') return false;

                // Extract the full numebr form str 'abbr'
                while(Ptr_abbr < m && Is_Digit(abbr[Ptr_abbr]) ){
                    Digits+= abbr[Ptr_abbr++];
                }
                
            Abbr_Num = Convert_StrDigit2Num(Digits);
            Digits=""; // Reset Digits

            Ptr_w+=Abbr_Num;  //Move Ptr_W forward by Abbr_Num
            
            if ( Ptr_w > n)return false;

            }else{ // If Abbr character is not digit
                if(Ptr_w>= n || word[Ptr_w]!= abbr[Ptr_abbr]) return false;
                Ptr_w++;
                Ptr_abbr++;
            }
        }

        return Ptr_w == n && Ptr_abbr == m;

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
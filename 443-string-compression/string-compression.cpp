class Solution {
    vector<char>Digits_Interger_to_Char_Convert(int n){
        vector<char>Digits;
        while(n>0){
            Digits.insert( Digits.begin(),(n % 10) + '0');
            n/=10;
        }
        return Digits;
    }
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int index=0;
        char Curr_Char=chars[0];
        int Curr_Char_Count=1;
        chars[index++]=Curr_Char;
        vector<char>Digits;
        for(int i=1; i < n ; i++){
            if(chars[i]==Curr_Char){
                Curr_Char_Count++;

            }else{
                // Convert the count to chars and add them to the vector
                if (Curr_Char_Count > 1) {
                    Digits = Digits_Interger_to_Char_Convert(Curr_Char_Count);
                    for (char c : Digits) {
                        chars[index++] = c;
                    }
                }
                // Reset for the new character
                Curr_Char = chars[i];
                Curr_Char_Count = 1;
                chars[index++] = Curr_Char;
            }
        }

        // **Fix for the Last Character Group**
        if (Curr_Char_Count > 1) {
            Digits = Digits_Interger_to_Char_Convert(Curr_Char_Count);
            for (char c : Digits) {
                chars[index++] = c;
            }
        }

        cout<<endl;
        return index;

    }
};






























/*
class Solution {
public:
    vector<char> Convert_Digits_to_Chars(int x){
        vector<char>DigitsChars;
        char temp;
        while(x!=0){
            temp = '0' + x%10;
            DigitsChars.insert(DigitsChars.begin(),temp); //insert at the begining 
           x/=10;
        }
        return DigitsChars;
    }
    int compress(vector<char>& chars) {
        int curr_charIdx;
        int Curr_Char_Occorrunces;
        int i=0;
        int writeIdx = 0 ;   //ptr to write the compressed characters back
        while(i<chars.size()){
            curr_charIdx= i;
            Curr_Char_Occorrunces = 1;
            while(curr_charIdx + 1 < chars.size() && chars[curr_charIdx + 1] == chars[curr_charIdx]){
                Curr_Char_Occorrunces++;
                curr_charIdx++;
            }
            // write the current character
            chars[writeIdx++] = chars[i];

            // if the occorunces are greater than 1, wrtie the count
            if(Curr_Char_Occorrunces > 1){
                 vector<char> Digit = Convert_Digits_to_Chars(Curr_Char_Occorrunces);
                 for (int j = 0; j<Digit.size() ; j++){
                    chars[writeIdx++]=Digit[j];
                 }
            }

            // Move to the next Characters Group
            i =curr_charIdx + 1;
        }
        return writeIdx;
    }
};

*/
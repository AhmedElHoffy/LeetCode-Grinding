class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int write =0;
        char Curr_ch;
        int start_rep_idx, Count_rep;
        string Num_Str;
        for (int read_idx=0; read_idx < n ; ){
            Curr_ch =chars[read_idx];
            start_rep_idx = read_idx;

            while(read_idx<n && chars[read_idx]==Curr_ch) read_idx++;
            Count_rep = read_idx-start_rep_idx;

            chars[write++]=Curr_ch;

            if(Count_rep > 1){
                Num_Str = to_string(Count_rep);
                for(char ch : Num_Str){
                    chars[write++]=ch;
                }
            }
        }
        return write;
    }
};












/*
class Solution {
private: 
    string Num_2_Str_Convert(int num){
        string Result="";
        char Ch;
        while(num>0){
            Ch = (num%10) + '0';
            Result = Ch + Result;
            num/=10;
        }
        return Result;
    }

public:
    int compress(vector<char>& Chars) {
        int n = Chars.size();
        int Running_Ptr=0, Write_Idx=0;
        int Count_Chars=0;
        char Curr_Char;
        string Repeat_Char_Count_Str;
        int Compressed_Size;
        while(Running_Ptr < n){
            Curr_Char = Chars[Running_Ptr];
            Count_Chars=0;
            while(Running_Ptr < n && Chars[Running_Ptr]==Curr_Char){
                Count_Chars++;
                Running_Ptr++;
            }

            Chars[Write_Idx++] = Curr_Char;
            if(Count_Chars>1){
                Repeat_Char_Count_Str =  Num_2_Str_Convert(Count_Chars);
                cout<<"Repeated Chars count: "<<Count_Chars<<endl;
                cout<<"Repeated Chars Str: "<<Repeat_Char_Count_Str<<endl;
                for(char Ch : Repeat_Char_Count_Str){
                     Chars[Write_Idx++] = Ch;
                }
            }
        }
        Compressed_Size = Write_Idx;

        cout<<Compressed_Size<<endl<<endl;
        return Compressed_Size;
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
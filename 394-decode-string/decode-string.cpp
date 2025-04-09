class Solution {
private: 
    int Convert_Str_2_Num(string S){
        int Result=0;

        for(char Ch : S){
            Result = Result*10 + (Ch-'0');
        }
        return Result;
    }

public:
    string decodeString(string Str) {
        stack<int>Nums_Stk;
        stack<string>Str_Stk;
        string Curr="";
        int Num=0;
        string temp;
        int Repeat;

        for(char Ch : Str){
            if(Ch>='0' && Ch<='9'){
                Num = Num*10 + (Ch-'0');
            }else if( Ch == '['){
                Str_Stk.push(Curr);
                Curr="";
                Nums_Stk.push(Num);
                Num=0;
            }else if(Ch == ']'){
                temp = Curr;
                Curr= Str_Stk.top();
                Str_Stk.pop();
                Repeat = Nums_Stk.top();
                Nums_Stk.pop();
                while(Repeat--) Curr+=temp;
            }else{
                Curr+=Ch;
            }
        }
        return Curr;
    }
};





















/*
class Solution {
public:
    string decodeString(string Str) {
        // Recursion Apporach
        int idx = 0; // Global index pointer
        return decodeHelper(Str, idx);
    }
        /// Stack apporach
        
        string Result;
        stack<char> Encoded_Str;
        int Idx = 0;

        for (Idx; Idx < Str.size(); Idx++) {
            if (Str[Idx] != ']') {
                Encoded_Str.push(Str[Idx]); // Push all characters except ']'
            } else {
                // Closing Bracket Detected
                string Curr_Str = "";

                // Step 1: Extract the substring within the brackets
                while (!Encoded_Str.empty() && Encoded_Str.top() != '[') {
                    Curr_Str = Encoded_Str.top() + Curr_Str;
                    Encoded_Str.pop();
                }

                // Remove the '['
                if (!Encoded_Str.empty()) Encoded_Str.pop();

                // Step 2: Extract the repeat count (number before '[')
                string Repeat = "";
                while (!Encoded_Str.empty() && Encoded_Str.top() >= '0' && Encoded_Str.top() <= '9') {
                    Repeat = Encoded_Str.top() + Repeat; // Build the repeat string
                    Encoded_Str.pop();
                }

                // Step 3: Convert Repeat to integer
                int Repeat_Int = 0;
                for (int j = 0; j < Repeat.size(); j++) {
                    Repeat_Int = Repeat_Int * 10 + (Repeat[j] - '0');
                }

                // Step 4: Repeat the extracted substring
                string Repeated_str = "";
                for (int i2 = 0; i2 < Repeat_Int; i2++) {
                    Repeated_str += Curr_Str;
                }

                // Step 5: Push repeated substring back into the stack
                for (char c : Repeated_str) {
                    Encoded_Str.push(c);
                }
            }
        }

        // Construct the final result
        while (!Encoded_Str.empty()) {
            Result = Encoded_Str.top() + Result;
            Encoded_Str.pop();
        }

        return Result;
    }
    

// for recursion approach
    private:
    string decodeHelper(const string& s, int& idx) {
        string result = "";

        while (idx < s.size() && s[idx] != ']') {
            if (s[idx] >= '0' && s[idx] <= '9') {
                // Step 1: Extract the full number (repeat count)
                int repeatCount = 0;
                while (s[idx] >= '0' && s[idx] <= '9') {
                    repeatCount = repeatCount * 10 + (s[idx] - '0');
                    idx++;
                }

                // Step 2: Skip the opening bracket '['
                idx++; 

                // Step 3: Recursive call to decode the substring
                string decodedSubstring = decodeHelper(s, idx);

                // Step 4: Append the repeated substring to the result
                for (int i = 0; i < repeatCount; i++) {
                    result += decodedSubstring;
                }
            }
            else {
                // Add regular characters to the result
                result += s[idx];
                idx++;
            }
        }

        // Step 5: Skip the closing bracket ']' (if any)
        idx++;

        return result;
    }
};
*/
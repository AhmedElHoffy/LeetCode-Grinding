class Solution {
private:
    bool Char_Detect(char c){
        if(c>='A' && c<='Z'){
            return true;
        }else if(c>='a' && c<='z'){
            return true;
        }else if(c>='0' && c<='9') {
            return true;
        }else {
            return false;
        }
    }
    char Covnert_Upper2Lower(char ch){
        if (ch>='A' && ch<='Z'){
            return ch+32;
        }else{
            return ch;
        }
    }
public:
   bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;

        while (left < right) {
            // Move left pointer to the next alphanumeric character
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            // Move right pointer to the previous alphanumeric character
            while (left < right && !isalnum(s[right])) {
                right--;
            }

            // Compare characters (case-insensitive)
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            // Move pointers inward
            left++;
            right--;
        }

        return true; // If no mismatches are found
    }
};









/*

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;

        while (left < right) {
            // Move left pointer to the next alphanumeric character
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            // Move right pointer to the previous alphanumeric character
            while (left < right && !isalnum(s[right])) {
                right--;
            }

            // Compare characters (case-insensitive)
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            // Move pointers inward
            left++;
            right--;
        }

        return true; // If no mismatches are found
    }
};
*/